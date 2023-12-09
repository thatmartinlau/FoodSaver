import QtQuick
import QtQuick.Controls

Item {

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
