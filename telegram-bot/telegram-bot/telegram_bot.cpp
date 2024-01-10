#include <tgbot/tgbot>
#include "rpc.client.h"
#include <iostream>
#include <string>

using namespace rpc;
using namespace std;
using namespace TgBot;

void link_verification(client client, string token) {}

void send_remind_messages(client client) {}

void check_expiration(vector<vector<string>> fridge) {}




int main() {
    TgBot::Bot bot("6354477753:AAFal99-y11oE7oKx2Uf5rzLk6nphuW-JWA");

    bot.getEvents().onCommand("sell", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Sell command received");
    });

    bot.getEvents().onCommand("get_lists", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Get lists command received");
    });

    bot.getEvents().onCommand("buy", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Buy command received");
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("Error: %s\n", e.what());
    }

    return 0;
}