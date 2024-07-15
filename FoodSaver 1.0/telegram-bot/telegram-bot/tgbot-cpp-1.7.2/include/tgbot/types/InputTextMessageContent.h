#ifndef TGBOT_INPUTTEXTMESSAGECONTENT_H
#define TGBOT_INPUTTEXTMESSAGECONTENT_H

#include "tgbot/types/InputMessageContent.h"
#include "tgbot/types/MessageEntity.h"

#include <memory>
#include <string>
#include <vector>

namespace TgBot {

/**
 * @brief Represents the content of a text message to be sent as the result of an inline query.
 *
 * @ingroup types
 */
class InputTextMessageContent : public InputMessageContent {
public:
    static const std::string TYPE;

    typedef std::shared_ptr<InputTextMessageContent> Ptr;

    InputTextMessageContent() {
        this->type = TYPE;
    }

    /**
     * @brief Text of the message to be sent, 1-4096 characters
     */
    std::string messageText;

    /**
     * @brief Optional. Mode for parsing entities in the message text.
     * See https://core.telegram.org/bots/api#formatting-options for more details.
     */
    std::string parseMode;

    /**
     * @brief Optional. List of special entities that appear in message text, which can be specified instead of InputTextMessageContent::parseMode
     */
    std::vector<MessageEntity::Ptr> entities;

    /**
     * @brief Optional. Disables link previews for links in the sent message
     */
    bool disableWebPagePreview;
};
}

#endif //TGBOT_INPUTTEXTMESSAGECONTENT_H
