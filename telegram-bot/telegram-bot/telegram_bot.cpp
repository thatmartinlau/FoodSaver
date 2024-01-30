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
#include <random>

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
rpc::client c("172.20.10.7", 8080); // IP number, Port number

// Check expiration from all fridges
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
                                                    "- /Logout - terminate the link of this telegram account\n"
                                                    "- /Register - register a new fridge account\n"
                                                    "- /Check_fridge - check your fridge contents\n"
                                                    "- /Get_random_recipe - get a random recipe from our recipe list\n");
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
    bot.getEvents().onCommand("Logout", [](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) != userCredentialsMap.end()) {
            // User already logged in
            userCredentialsMap.erase(chatId);
            bot.getApi().sendMessage(chatId, "Logout successfully!");
        } else {
            // User needs to log in
            bot.getApi().sendMessage(chatId, "Sorry, this telegram account hasn't linked to any fridge!");
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
    bot.getEvents().onCommand("Get_random_recipe", [](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) == userCredentialsMap.end()) {
            // User not in list
            bot.getApi().sendMessage(chatId, "Please login first using /Login, or register a new account using /Register.");
        } else {
            // User already exists
            vector<string> recipe_list = c.call("getAllRecipes").as<vector<string>>();
            std::random_device rd;
            std::mt19937 gen(rd());

            if (!recipe_list.empty()) {
                std::uniform_int_distribution<> distrib(0, recipe_list.size() - 1);
                int randomIndex = distrib(gen); // Generate a random index
                std::string randomRecipe = recipe_list[randomIndex]; // Get the element at the random index

                // tilte @ instruction % ingredient * source # tags , url
                std::string title, instructions, ingredients, source, tags, url;
                std::istringstream recipeStream(randomRecipe);
                std::getline(recipeStream, title, '@');
                std::getline(recipeStream, instructions, '%');
                std::getline(recipeStream, ingredients, '*');
                std::getline(recipeStream, source, '#');
                std::getline(recipeStream, tags, ',');
                std::getline(recipeStream, url);

                std::string formattedMessage = "Here is your random recipe:\n\n";
                formattedMessage += "Title: " + title + "\n\n";
                formattedMessage += "Instructions:\n" + instructions + "\n\n";
                formattedMessage += "Ingredients:\n" + ingredients + "\n\n";
                formattedMessage += "Source: " + source + "\n";
                formattedMessage += "Tags: " + tags + "\n";
                formattedMessage += "URL: " + url + "\n";


                bot.getApi().sendMessage(chatId, formattedMessage);
            } else {
                std::cout << "Error! The recipe list is empty!" << std::endl;
                bot.getApi().sendMessage(chatId, "Sorry! Our recipe list is currently empty, this is a problem caused by the server.");
            }
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
                bot.getApi().sendMessage(chatId, "Your fridge contains: \n" "Food name, Category, Quantity, Expired date \n" + formattedFridgeContent);
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

            double server_message = c.call("check_user", userInfo.username, userInfo.password).as<double>();

            if (server_message == 1) {
                c.call("add_user", userInfo.username, userInfo.password);
                bot.getApi().sendMessage(chatId, "Registered successfully!");
            } else if (server_message == 0) {
                bot.getApi().sendMessage(chatId, "This username has been used, Sorry!");
            } else {
                bot.getApi().sendMessage(chatId, "An error occurred during registration, please try later.");
            }

            // RPC call to link the fridge
            

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
            std::cout << "Starting checking expiration!" << std::endl;
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

            std::this_thread::sleep_for(std::chrono::minutes(1)); // Sleep for 30 minutes (testing mode is 1 minute)
        }
    });

    // Main loop for the bot
    try {
        TgBot::TgLongPoll longPoll(bot);
        std::cout << "Starting the bot" << std::endl;
        while (true) {
            std::cout << "Receiving messages from telegram" << std::endl;
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    expirationChecker.join();

    return 0;
}
