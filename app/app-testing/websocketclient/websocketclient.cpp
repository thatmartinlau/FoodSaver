#include "websocketclient.h"
#include "config.h"

WebsocketClient::WebsocketClient(QObject *parent)
    : QObject{parent}
{
    m_url = QUrl(QStringLiteral(SERVER_URL));
    // Call WebsocketClient::onConnected after connected to server
    connect(&m_ws, &QWebSocket::connected, this, &WebsocketClient::onConnected);
    // Call WebsocketClient::onConnected when m_ws receives a text message from server
    // m_ws receives data -> client runs onTextMessageReceived(message) ->
    // emit messageReceived signal -> QML receives signal with onMessageReceived
    connect(&m_ws, &QWebSocket::binaryMessageReceived, this, &WebsocketClient::onBinaryMessageReceived);
}

CallbackFuncs resolveCallbackFuncs(std::string funcStr) { // Convert parsed MsgPack to enum types
    if(funcStr=="userLoginSuccess") return userLoginSuccess;
    if(funcStr=="userLoginFail") return userLoginFail;
    if(funcStr=="updateFridge") return updateFridge;
    return funcNotFound;
}

void WebsocketClient::connectToServer() {
    qDebug() << "[WebsocketClient] Connecting to server...";
    qDebug() << "[WebsocketClient] Url: "<< SERVER_URL;
    m_ws.open(m_url);
}

void WebsocketClient::sendMsgPack(const msgpack11::MsgPack &msgpack) {
    std::string dumped_payload= msgpack.dump();
    m_ws.sendBinaryMessage(QByteArray(dumped_payload.data(), dumped_payload.size()));
}

void WebsocketClient::onConnected() {
    qDebug() << "[WebsocketClient] Connected to server";
}



void WebsocketClient::onBinaryMessageReceived(QByteArray serialized_data) {
    qDebug() << "[WebsocketClient] Message received: " << serialized_data;
    std::string err;
    msgpack11::MsgPack m_msgpack = msgpack11::MsgPack::parse(std::string(serialized_data.constData(), serialized_data.size()), err);
    std::string func = m_msgpack["func"].string_value();
    msgpack11::MsgPack payload = m_msgpack["payload"];
    if(!err.empty()) qDebug() << "[WebsocketClient] Error while parsing serialized_data: " << err;
    qDebug() << "[WebsocketClient] Func name from server: " << m_msgpack["func"].string_value();
    switch(resolveCallbackFuncs(func)) {
    case userLoginSuccess:
        handleUserLoginSuccess(payload);
        break;
    case userLoginFail:
        handleUserLoginFail(payload);
        break;
    case updateFridge:
        handleUpdateFridge(payload);
        break;
    case funcNotFound:
        qDebug() << "Func: " << func << " not found";
        break;
    }
}

void WebsocketClient::sendFunc(const std::string &func) {
    msgpack11::MsgPack payload = msgpack11::MsgPack::object {
        {"func", func}
    };
    sendMsgPack(payload);
}

void WebsocketClient::requestUpdateFridge() {
    qDebug() << "[WebsocketClient] Updating Fridge...";
    sendFunc("updateFridge");
    }

// Write handler here
void WebsocketClient::handleUserLoginSuccess(msgpack11::MsgPack payload) {
    qDebug() << "User login success, username: " << payload["username"].string_value();
    emit loadHomePage(); // Load Home.qml, this will be done in main.qml
}

void WebsocketClient::handleUserLoginFail(msgpack11::MsgPack payload) {
    qDebug() << "User login fail, message from server: " << payload["message"].string_value();
}

void WebsocketClient::handleUpdateFridge(msgpack11::MsgPack payload) {
    qDebug() << "handleUpdateFridge()";
    QList<QList<QVariant>> result;
    for(const msgpack11::MsgPack &p : payload.array_items()) {
        QList<QVariant> arr;
        for(const auto &item : p.array_items()) {
            if(item.is_string()) {
                // qDebug() << item.string_value();
                arr << QVariant(QString::fromStdString(item.string_value()));
            }
            if(item.is_int()) {
                // qDebug() << item.int_value();
                arr << QVariant(item.int_value());
            }
        }
        result << arr;
    }
    qDebug() << result;
    emit updateFridgeModel(result);
}

// Testing functions here
#ifdef QT_DEBUG
void WebsocketClient::testUserLogin() {
    msgpack11::MsgPack payload = msgpack11::MsgPack::object {
        {"func", "userLogin"},
        {"payload", msgpack11::MsgPack::object {
                {"username", "test"},
                {"password", "test"}
            }
        }
    };
    sendMsgPack(payload);
}
#endif
