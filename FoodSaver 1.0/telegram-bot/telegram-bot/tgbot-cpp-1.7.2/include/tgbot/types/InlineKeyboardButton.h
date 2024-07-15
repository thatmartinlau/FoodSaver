#ifndef TGBOT_INLINEKEYBOARDBUTTON_H
#define TGBOT_INLINEKEYBOARDBUTTON_H

#include "tgbot/types/WebAppInfo.h"
#include "tgbot/types/LoginUrl.h"
#include "tgbot/types/CallbackGame.h"

#include <memory>
#include <string>

namespace TgBot {

/**
 * @brief This object represents one button of an inline keyboard.
 * You must use exactly one of the optional fields.
 *
 * @ingroup types
 */
class InlineKeyboardButton {
public:
    typedef std::shared_ptr<InlineKeyboardButton> Ptr;

    /**
     * @brief Label text on the button
     */
    std::string text;

    /**
     * @brief Optional. HTTP or tg:// URL to be opened when the button is pressed.
     * Links tg://user?id=<user_id> can be used to mention a user by their ID without using a username, if this is allowed by their privacy settings.
     */
    std::string url;

    /**
     * @brief Optional. Data to be sent in a callback query to the bot when button is pressed, 1-64 bytes
     */
    std::string callbackData;

    /**
     * @brief Optional. Description of the Web App that will be launched when the user presses the button.
     * The Web App will be able to send an arbitrary message on behalf of the user using the method Api::answerWebAppQuery.
     * Available only in private chats between a user and the bot.
     */
    WebAppInfo::Ptr webApp;

    /**
     * @brief Optional. An HTTPS URL used to automatically authorize the user.
     * Can be used as a replacement for the Telegram Login Widget.
     */
    LoginUrl::Ptr loginUrl;

    /**
     * @brief Optional. If set, pressing the button will prompt the user to select one of their chats, open that chat and insert the bot's username and the specified inline query in the input field.
     * May be empty, in which case just the bot's username will be inserted.
     *
     * Note: This offers an easy way for users to start using your bot in inline mode when they are currently in a private chat with it.
     * Especially useful when combined with switch_pm… actions - in this case the user will be automatically returned to the chat they switched from, skipping the chat selection screen.
     */
    std::string switchInlineQuery;

    /**
     * @brief Optional. If set, pressing the button will insert the bot's username and the specified inline query in the current chat's input field.
     * May be empty, in which case only the bot's username will be inserted.
     * 
     * This offers a quick way for the user to open your bot in inline mode in the same chat - good for selecting something from multiple options.
     */
    std::string switchInlineQueryCurrentChat;

    /**
     * @brief Optional. Description of the game that will be launched when the user presses the button.
     *
     * NOTE: This type of button must always be the first button in the first row.
     */
    CallbackGame::Ptr callbackGame;

    /**
     * @brief Optional. Specify True, to send a Pay button.
     *
     * NOTE: This type of button must always be the first button in the first row and can only be used in invoice messages.
     */
    bool pay;
};
}

#endif //TGBOT_INLINEKEYBOARDBUTTON_H
