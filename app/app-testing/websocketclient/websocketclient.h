/*
 * This is a encapsulated QWebSocket class, intended to connect with the backend
 * via a websocket protocol, sending / retrieving data and process it to be rendered
 * to the user interface implemented by QML. -Xiaxi
 * ALL data to/from server shall be a SERIALIZED MsgPack DATA transmitted as BINARY, parsed locally
 * Format: {"func":String, "payload":MsgPack::Object}
 * !!!NO DIRECT TEXT MESSAGE ALLOWED FOR SECURITY CONCERNS!!!
*/

#ifndef WEBSOCKETCLIENT_WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_WEBSOCKETCLIENT_H

#include <QUrl>
#include <QObject>
#include <QString>
#include <QByteArray>
#include <QWebSocket> //Websocket class provided by Qt Framework
#include <QQmlApplicationEngine> //QML engine used to navigate between components
#include "dependencies/msgpack11/msgpack11.hpp"
#include <QVariantList>
#include <QVariant>
#include <QThread>
#include <QTimer>

/* Q: How to handle a callback from server?
 * A: Make sure you follows the protocol at the start of this header file, add yourCallback to enum CallbackFuncs
 *      Add a line `if(funcStr=="yourCallback") return yourCallback` to resolveCallbackFuncs (before `return funcNotFound`)
 *      Then you may be able to handle your callback in websocketclient.cpp with a new `case yourCallback`(remember to `break;`)
*/

enum CallbackFuncs{ // This enum is used to store all possible values of key "func" from the server
    userLoginSuccess, // Two call-backs when trying to login
    userLoginFail,
    updateFridge,
    funcNotFound // All other cases when theres an unresolved callback (which means u need to check the server-side)
};

CallbackFuncs resolveCallbackFuncs(std::string funcStr); // Convert parsed MsgPack to enum types


class WebsocketClient : public QObject //Inheriting QObject makes it possible to be a QML component
{
    Q_OBJECT
public:
    explicit WebsocketClient(QObject *parent = nullptr);


signals:
    void messageReceived(QString message); // On receiving websocket string message from server
    void loadHomePage();
    void loadLoginPage();
    void updateFridgeModel(QList<QList<QVariant>> data);
    void mountLoadingMask(QString text);
    void unmountLoadingMask();

public slots:
    void connectToServer();
    void sendMsgPack(const msgpack11::MsgPack &msgpack);
    void onConnected();
    void onBinaryMessageReceived(const QByteArray serialized_data); // on QWebSocket::binaryMessageReceived
    void requestUpdateFridge(); // Actively updating fridge items from server
    void onDisconnected(); // on QWebSocket::disconnected
    void onErrorOccured(QAbstractSocket::SocketError err); // on QWebSocket::errorOccured
#ifdef QT_DEBUG // Testing slot functions
    void testUserLogin();
#endif


private:
    QWebSocket m_ws;
    QUrl m_url;
    int error_counter;

    void sendFunc(const std::string &func); // Pack MsgPacks with no "payload" and only "func"
    // Server Callback Handlers
    void handleUserLoginSuccess(msgpack11::MsgPack payload);
    void handleUserLoginFail(msgpack11::MsgPack payload);
    void handleUpdateFridge(msgpack11::MsgPack payload);
    void handleFuncNotFound();
    void tryReconnect(QAbstractSocket::SocketError err);
};

#endif // WEBSOCKETCLIENT_H
