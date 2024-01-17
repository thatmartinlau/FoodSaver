#include <tgbot/tgbot>
#include "rpc.client.h"
#include <iostream>
#include <string>
#include "test3/temp.front.cpp"

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
    std::string username;
    std::string password;
};

struct UserCredentials {
    std::string username;
    std::string password;
};

std::map<int64_t, UserCredentials> userCredentialsMap;

std::map<int64_t, UserInfo> userStates;


string check_expiration(vector<vector<string>> fridge) {}

void link_verification(client client, string token) {}


int main() {
    TgBot::Bot bot("6644281748:AAFh40LQLa5054caEUPt8T_9wf-Yv1hAB-w");

    rpc::client c("3333", rpc::constants::DEFAULT_PORT);

    bot.getEvents().onCommand("Start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Welcome to FoodSaver bot, I can help you manage your fridge account." 
                                                    "Here are the things that I can do for you:\n"
                                                    "- /Login - login to your fridge account\n"
                                                    "- /Register - register a new fridge account\n"
                                                    "- /Check_your_fridge - check your fridge contents\n";);
    });

    //
    bot.getEvents().onCommand("Login", [&bot, &userStates](TgBot::Message::Ptr message) {
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
    bot.getEvents().onCommand("Register", [&bot, &userStates](TgBot::Message::Ptr message) {
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
    bot.getEvents().onCommand("Check_fridge", [&bot, &userCredentialsMap, &c](TgBot::Message::Ptr message) {
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
    bot.getEvents().onAnyMessage([&bot, &userStates, &c](TgBot::Message::Ptr message) {
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
            bot.getApi().sendMessage(chatId, "Sorry, I couldn't understand your command.");
        }
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}