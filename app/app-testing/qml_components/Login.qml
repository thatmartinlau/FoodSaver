import QtQuick
import QtQuick.Controls

Item {

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
