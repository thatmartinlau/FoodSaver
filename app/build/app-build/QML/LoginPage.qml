import QtQuick 2.12
import QtQuick.Controls 2.12

Item {

    // FOODSAVER LOGO/LABEL

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height/3.3

        Label {
            horizontalAlignment: Text.AlignHCenter // Center the text within the Label
            anchors.horizontalCenter: parent.horizontalCenter // Center the Label within the Rectangle
            text: "Welcome to FoodSaver!"
        }
    }

    // TEXT ENTRIES + BUTTON

    Column{
        spacing: 10
        width: 300

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        // Error messages (originally hidden)

        Text {
            id: passwordOrUsernameErrorText
            visible: false // Initially hidden
            text: "The username and/or password is incorrect"
            color: "red"
        }
        TextField {
            width: parent.width
            id: input_username
            placeholderText: "Username"
        }
        TextField {
            width: parent.width
            id: input_password
            placeholderText: "Password"
            echoMode: TextField.Password
        }
        Button {
            anchors.left: parent.left
            text: "New here?"
            onClicked: stackView.push(Qt.resolvedUrl("SigninPage.qml"))
        }

        Button {
            anchors.left: parent.left
            text: "Login"
            onClicked: {
                login.verifyPasswordUsername(input_username.text, input_password.text);
                input_username.text = ""
                input_password.text = ""
                passwordOrUsernameErrorText.visible = false;
            }
        }

        // Implementing connections to C++ code
        Connections {
            target: login

            // Errors upon login
            onOpenPasswordUsernameError: {
                passwordOrUsernameErrorText.visible = true;
            }

            // Successful login
            onoOenMarketPage: {
                stackView.push(Qt.resolvedUrl("Market.qml"))
            }
        }


    }

    // SIDE + EXTRA BUTTONS

    Column {
        anchors.right: parent.right
        anchors.bottomMargin: 10
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        width: 150
        spacing: 10

        Button {
            text: "About this project"
            width: parent.width
            onClicked: {
                var url = "https://github.com/thatmartinlau/FoodSaver"
                Qt.openUrlExternally(url)
            }
        }

        Button {
            width: parent.width
            text: "Exit"
            onClicked: Qt.quit()
        }
    }
}
