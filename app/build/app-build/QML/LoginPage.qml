import QtQuick 2.12
import QtQuick.Controls 2.12

Item {

    Rectangle {

        x: parent.width / 2.2
        y: parent.height / 3.3

        Label {
            text: "Welcome to FoodSaver!"
        }

    }

    Column{
        spacing: 10
        width: 300

        x: parent.width / 2.2
        y: parent.height / 2

        TextField {
            width: parent.width
            id: input_username
            placeholderText: "Username"
        }
        TextField {
            width: parent.width
            id: input_password
            placeholderText: "Password"
        }

        Button {
            anchors.left: parent.left
            text: "Login"
            onClicked: stackView.push(Qt.resolvedUrl("HomePage.qml")) //replace this soon with the login function, to be implemented
        }
    }

}
