/*
 * This is a encapsulated QWebSocket class, intended to connect with the backend
 * via a websocket protocol, sending / retrieving data and process it to be rendered
 * to the user interface implemented by QML. -Xiaxi
*/

#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QWebSocket> //Websocket class provided by Qt Framework


class WebsocketClient : public QObject //Inheriting QObject makes it possible to be a QML component
{
    Q_OBJECT
public:
    explicit WebsocketClient(QObject *parent = nullptr);

signals:
    void messageReceived(QString message); //On receiving websocket string message from server

public slots:
    void connectToServer();
    void sendMessage(const QString &message);
    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket m_ws;
    QUrl m_url;

};

#endif // WEBSOCKETCLIENT_H
