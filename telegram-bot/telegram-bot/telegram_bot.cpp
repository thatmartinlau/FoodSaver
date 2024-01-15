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

std::map<int64_t, UserInfo> userStates;


void link_verification(client client, string token) {}

void send_remind_messages(client client) {}

string check_expiration(vector<vector<string>> fridge) {}

string check_fridge(client)

int main() {
    TgBot::Bot bot("6644281748:AAFh40LQLa5054caEUPt8T_9wf-Yv1hAB-w");

    rpc::client c("3333", rpc::constants::DEFAULT_PORT);

    bot.getEvents().onCommand("Start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Welcome to FoodSaver, I can help you manage your fridge in Apps." 
                                                    "Here are the things that I can do for you:\n"
                                                    "- /Check_your_fridge - check your fridge contents\n"
                                                    "- /Link_your_fridge - link your fridge account to this bot\n"
                                                    "- /add_food - add food to your fridge\n"
                                                    "- /remove_food - remove food from your fridge";);
    });

    //
    bot.getEvents().onCommand("check_fridge", [&bot, &userStates](TgBot::Message::Ptr message) {
    UserInfo& userInfo = userStates[message->chat->id];
    userInfo.state = UserState::AwaitingUsername;
    bot.getApi().sendMessage(message->chat->id, "Enter your username:");
    });

    bot.getEvents().onAnyMessage([&bot, &userStates, &c](TgBot::Message::Ptr message) {
        if (StringTools::startsWith(message->text, "/")) {
            // Ignore command messages
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

            // Here you call your RPC function with the collected username and password
            double fridge = c.call("get_fridge", userInfo.username, userInfo.password).as<double>();

            bot.getApi().sendMessage(chatId, "Your fridge contains: " + std::to_string(fridge));
        }
    });


    //
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    if (StringTools::startsWith(message->text, "/link_your_fridge")) {
        return;
    }

    bot.getApi().sendMessage(message->chat->id, "Enter your username: " + message->text);

    // Codes for receive username from user, username

    bot.getApi().sendMessage(message->chat->id, "Enter your password: " + message->text);

    // Codes for receive password from user, password

    double server_message = c.call("get_token", username, password).as<double>();

    if (server_message == "1") {
        bot.getApi().sendMessage(message->chat->id, "Linked successfully!" + message->text);
    } 
    else if (server_message == "0") {
        bot.getApi().sendMessage(message->chat->id, "This account has already been linked in telegram." + message->text);
    }
    });

    //
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    if (StringTools::startsWith(message->text, "/add_food")) {
        return;
    }

    bot.getApi().sendMessage(message->chat->id, "Enter the food you want to add: " + message->text);
    });

    // receive message from user

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