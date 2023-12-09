import QtQuick
import QtQuick.Controls

Window {
    width: 720
    height: 1280
    visible: true
    title: qsTr("App")

    signal userLogin
    Button {
        text: "Login"
        onClicked: {
            wsClient.testUserLogin();
        }
    }

    // Connect to WebsocketClient object in C++
    Connections {
        target: wsClient
    }
}
