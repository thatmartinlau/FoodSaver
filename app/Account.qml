import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Item {
    ColumnLayout {
        anchors.fill: parent
        spacing: 2
        Text {
            id: accountText
            text: qsTr("This is the Account Page")
        }
        Text {
            id: anotherText
            text: qsTr("This is another line to show columnlayout")
        }
        Button {
            text: "Send message to server"
            onClicked: {
                wsClient.sendMessage("Hello World");
            }
        }
        // Connect to wsClient in main.cpp
        Connections {
            target: wsClient
            onMessageReceived: {
                console.log("[QML Connections]Message from server: ", message)
            }
        }
    }
}
