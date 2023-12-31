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
    connect(&m_ws, &QWebSocket::textMessageReceived, this, &WebsocketClient::onTextMessageReceived);
}

void WebsocketClient::connectToServer() {
    qDebug() << "[WebsocketClient] Connecting to server...";
    qDebug() << "[WebsocketClient] Url: "<< SERVER_URL;
    m_ws.open(m_url);
}

void WebsocketClient::sendMessage(const QString &message) {
    m_ws.sendTextMessage(message);
}

void WebsocketClient::onConnected() {
    qDebug() << "[WebsocketClient] Connected to server";
}

void WebsocketClient::onTextMessageReceived(QString message) {
    qDebug() << "[WebsocketClient] Message received: " << message;
    emit messageReceived(message);
}
