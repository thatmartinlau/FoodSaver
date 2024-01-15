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
    AwaitingPassword
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
                                                    "- /Check_your_fridge - check your fridge contents\n"
                                                    "- /Update_fridge - update the entire fridge";);
    });

    //
    bot.getEvents().onCommand("Login", [&bot, &userStates](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) != userCredentialsMap.end()) {
            // User already logged in
            bot.getApi().sendMessage(chatId, "This telegram account already login.");
        } else {
            // User needs to log in
            UserInfo& userInfo = userStates[message->chat->id];
            userInfo.state = UserState::AwaitingUsername;
            bot.getApi().sendMessage(chatId, "Enter your username: ");
        }
    });

    //
    bot.getEvents().onCommand("Check_fridge", [&bot, &userCredentialsMap, &c](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) == userCredentialsMap.end()) {
            bot.getApi().sendMessage(chatId, "Please login first using /login.");
        } else {
            auto& credentials = userCredentialsMap[chatId];
            std::string fridgeContent = c.call("get_fridge", credentials.username, credentials.password).as<std::string>();
            bot.getApi().sendMessage(chatId, "Your fridge contains: " + fridgeContent);
        }
    });

    //
    bot.getEvents().onCommand("Update_fridge", [&bot, &userCredentialsMap, &c](TgBot::Message::Ptr message) {
        int64_t chatId = message->chat->id;
        if (userCredentialsMap.find(chatId) == userCredentialsMap.end()) {
            bot.getApi().sendMessage(chatId, "Please login first using /login.");
        } else {
            auto& credentials = userCredentialsMap[chatId];
            c.call("update_fridge", credentials.username, credentials.password, content);
            bot.getApi().sendMessage(chatId, "Your fridge has been updated successfully";
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