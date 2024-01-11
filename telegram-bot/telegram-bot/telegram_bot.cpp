#include <tgbot/tgbot>
#include "rpc.client.h"
#include <iostream>
#include <string>

using namespace rpc;
using namespace std;
using namespace TgBot;

void link_verification(client client, string token) {}

void send_remind_messages(client client) {}

string check_expiration(vector<vector<string>> fridge) {}

string check_fridge(client)

int main() {
    TgBot::Bot bot("6644281748:AAFh40LQLa5054caEUPt8T_9wf-Yv1hAB-w");

    bot.getEvents().onCommand("Start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Welcome to FoodSaver, I can help you manage your fridge in Apps." 
                                                    "Here are the things that I can do for you:\n"
                                                    "- /check_fridge - check your fridge contents\n"
                                                    "- /link_your_fridge - link your fridge to the app";);
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    if (StringTools::startsWith(message->text, "/check_fridge")) {
        return;
    }
    bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
    if (StringTools::startsWith(message->text, "/link_your_fridge")) {
        return;
    }
    bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
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