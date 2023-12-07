import QtQuick
import QtQuick.Controls
import QtWebSockets

Window {
    width: 720
    height: 1280
    visible: true
    title: qsTr("App")

    WebSocket {
        id: socket
        url: "ws://127.0.0.1:3333"
        onTextMessageReceived: {
            test.text = test.text + "\n Received message: " + message
        }
        onStatusChanged: if (socket.status == WebSocket.Error) {
                             console.log("Error: " + socket.errorString)
                         } else if (socket.status == WebSocket.Open) {
                             socket.sendTextMessage("Hello World")
                         } else if (socket.status == WebSocket.Closed) {
                             test.text += "\nSocket closed"
                         }
        active: true
    }

    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent
        Item {
            Text {
                id: test
                text: qsTr("text")
            }
        }

        /*Fridge {
            id: fridgeView
        }*/
        Share {
            id: shareView
        }
        Account {
            id: accountView
        }
    }

    TabBar {
        id: menuTab
        width: parent.width

        currentIndex: view.currentIndex

        anchors.bottom: parent.bottom

        TabButton {
            id: fridgeTabbtn
            text: qsTr("Fridge")
        }
        TabButton {
            id: shareTabbtn
            text: qsTr("Share")
        }
        TabButton {
            id: accountTabbtn
            text: qsTr("Account")
        }

        onCurrentIndexChanged: {
            print("menuTab currentIndex change to ", currentIndex)
            view.setCurrentIndex(currentIndex)
        }
    }
}
