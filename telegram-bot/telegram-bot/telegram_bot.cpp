#include "tgbot/tgbot.h"
#include "rpc/client.h"
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip> // for std::get_time
#include <thread>
#include <chrono>
#include <tgbot/tgbot.h>

using namespace rpc;
using namespace std;
using namespace TgBot;

enum class UserState {
    None,
    AwaitingUsername,
    AwaitingPassword,
    RegiUsername,
    RegiPassword,
};

struct UserInfo {
    UserState state = UserState::None;
    string username;
    string password;
};

struct UserCredentials {
    string username;
    string password;
};

std::map<int64_t, UserCredentials> userCredentialsMap;

std::map<int64_t, UserInfo> userStates;

TgBot::Bot bot("6644281748:AAFh40LQLa5054caEUPt8T_9wf-Yv1hAB-w");
rpc::client c("3333", rpc::constants::DEFAULT_PORT);


vector<vector<string>> check_expiration(client& c) {
    vector<vector<string>> result;
    for (const auto& entry : userCredentialsMap) {
        auto& credentials = entry.second;
        vector<vector<string>> fridgeContent = c.call("get_fridge", credentials.username, credentials.password).as<vector<vector<string>>>();

        for (const auto& item : fridgeContent) {
            if (item.size() >= 4) {
                std::tm expiry_tm = {};
                std::istringstream ss(item[3]);
                ss >> std::get_time(&expiry_tm, "%d-%m-%Y");

                // Check if the expiry date is within 1 day
                std::time_t now = std::time(nullptr);
                std::time_t expiry_time_t = std::mktime(&expiry_tm);
                double seconds_diff = std::difftime(expiry_time_t, now);
                
                if (seconds_diff >= 0 && seconds_diff <= 86400) { // 86400 seconds in a day
                std::string chatIdStr = std::to_string(entry.first);
                std::string message = item[0] + " (" + item[1] + ", " + item[2] + ") is going to expire in less than one day (Expiry Date: " + item[3] + ").";
                result.push_back({chatIdStr, message});
                }
            }
        }
    }

    return result;
}

int main() {
    bot.getEvents().onCommand("start", [](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Welcome to FoodSaver bot, I can help you manage your fridge account." 
                                                    "Here are the things that I can do for you:\n"
                                                    "- /Login - login to your fridge account\n"
                                                    "- /Register - register a new fridge account\n"
                                                    "- /Check_your_fridge - check your fridge contents\n");
    });

    //
    bot.getEvents().onCommand("Login", [](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) != userCredentialsMap.end()) {
            // User already logged in
            bot.getApi().sendMessage(chatId, "This telegram account has already logged in.");
        } else {
            // User needs to log in
            UserInfo& userInfo = userStates[message->chat->id];
            userInfo.state = UserState::AwaitingUsername;
            bot.getApi().sendMessage(chatId, "Enter your username: ");
        }
    });

    //
    bot.getEvents().onCommand("Register", [](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) == userCredentialsMap.end()) {
            // User not in list
            UserInfo& userInfo = userStates[message->chat->id];
            userInfo.state = UserState::RegiUsername;
            bot.getApi().sendMessage(chatId, "Enter you desired username: ");
        } else {
            // User already exists
            bot.getApi().sendMessage(chatId, "This telegram account has already logged in.");
        }
    });

    //
    bot.getEvents().onCommand("Check_fridge", [](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) == userCredentialsMap.end()) {
            bot.getApi().sendMessage(chatId, "Please login first using /Login, or register a new account using /Register.");
        } else {
            auto& credentials = userCredentialsMap[chatId];
            vector<vector<string>> fridgeContent = c.call("get_fridge", credentials.username, credentials.password).as<vector<vector<string>>>();
            string formattedFridgeContent;

            for (const auto& item : fridgeContent) {
                if (item.size() >= 4) { // Make sure there are at least 4 elements (name, category, quantity, expiry_date)
                    formattedFridgeContent += "- " + item[0] + ", " + item[1] + ", " + item[2] + ", " + item[3] + "\n";
                }
            }

            if (!formattedFridgeContent.empty()) {
                bot.getApi().sendMessage(chatId, "Your fridge contains: \n" + formattedFridgeContent);
            } else {
                bot.getApi().sendMessage(chatId, "Your fridge is currently empty.");
            }
        }
    });

    //
    bot.getEvents().onAnyMessage([](TgBot::Message::Ptr message) {
        if (StringTools::startsWith(message->text, "/")) {
            return;
        }

        int64_t chatId = message->chat->id;
        UserInfo& userInfo = userStates[chatId];

        if (userInfo.state == UserState::AwaitingUsername) {
            userInfo.username = message->text;
            userInfo.state = UserState::AwaitingPassword;
            bot.getApi().sendMessage(chatId, "Enter your password:");
        } else if (userInfo.state == UserState::RegiUsername) {
            userInfo.username = message->text;
            userInfo.state = UserState::RegiPassword;
            bot.getApi().sendMessage(chatId, "Enter your password:");
        } else if (userInfo.state == UserState::RegiPassword) {
            userInfo.password = message->text;
            userInfo.state = UserState::None;

            userCredentialsMap[chatId] = {userInfo.username, userInfo.password};

            // RPC call to link the fridge
            c.call("add_user", userInfo.username, userInfo.password);

            bot.getApi().sendMessage(chatId, "Registered successfully!");

        } else if (userInfo.state == UserState::AwaitingPassword) {
            userInfo.password = message->text;
            userInfo.state = UserState::None;

            userCredentialsMap[chatId] = {userInfo.username, userInfo.password};

            // RPC call to link the fridge
            double server_message = c.call("check_user", userInfo.username, userInfo.password).as<double>();

            // Check the server's response
            if (server_message == 1) {
                bot.getApi().sendMessage(chatId, "Linked successfully!");
            } else if (server_message == 0) {
                bot.getApi().sendMessage(chatId, "This account has already been linked in Telegram.");
            } else {
                bot.getApi().sendMessage(chatId, "An error occurred while linking your fridge.");
            }
        } else {
            bot.getApi().sendMessage(chatId, "Sorry, I couldn't understand. Please use /start to check more commands. ");
        }
    });

    //std::thread expirationCheckerThread = std::thread(expirationChecker);
    std::thread expirationChecker([]() {
        while (true) {
            auto expiringItems = check_expiration(c);

            for (const auto& item : expiringItems) {
                try {
                    int64_t chatId = std::stoll(item[0]);
                    std::string message = item[1];
                    bot.getApi().sendMessage(chatId, message);
                } catch (const std::exception& e) {
                    std::cerr << "Error sending message: " << e.what() << std::endl;
                }
            }

            std::this_thread::sleep_for(std::chrono::minutes(30)); // Sleep for 30 minutes
        }
    });

    // Main loop for the bot
    try {
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            std::cout << "Starting the bot" << std::endl;
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    expirationChecker.join();

    return 0;
}