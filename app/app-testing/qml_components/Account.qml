import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

Item {
    ColumnLayout {
        anchors.fill: parent
        spacing: 1
        Text {
            id: accountText
            text: qsTr("This is the Account Page")
            Layout.preferredHeight: 40
        }
        Text {
            id: anotherText
            text: qsTr("This is another line to show columnlayout")
            Layout.preferredHeight: 40
        }
        Button {
            text: "Send message to server"
            onClicked: {
                wsClient.sendMessage("Hello World");
            }
            Layout.preferredHeight: 40
        }
        // Connect to wsClient in main.cpp
        Connections {
            target: wsClient
            function onMessageReceived(message){
                console.log("[QML Connections]Message from server: ", message)
            }
        }
    }
}
