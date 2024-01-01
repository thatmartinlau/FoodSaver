import QtQuick 2.12
import QtQuick.Controls 2.12
import com.Signin 1.0

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
        // Import Signin object
        Signin {
            id: signinLogic
        }

        // Add component
        TextField {
            width: parent.width
            id: input_username
            placeholderText: "Chose a username"
        }
        TextField {
            width: parent.width
            id: input_password
            placeholderText: "Chose a password"
        }
        TextField {
            width: parent.width
            id: input_password_check
            placeholderText: "Verify your password"
        }
        Button {
            anchors.left: parent.left
            text: "Do you already have an account?"
            onClicked: stackView.push(Qt.resolvedUrl("LoginPage.qml"))
        }

        Button {
            anchors.left: parent.left
            text: "Sign in"
            onClicked: {
                signinLogic.createUser(input_username.text, input_password.text, input_password_check.text)
            }
        }
        // Handling signals for UI feedback
        Text {
            id: usernameTakenText
            visible: false // Initially hidden
            text: "This username is already taken"
            color: "red"
            }

        Text {
            id: passwordMismatchText
            visible: false // Initially hidden
            text: "The password does not match"
            color: "red"
            }

        Connections {
            target: signinLogic

            onUsernameTaken: {
                usernameTakenText.visible = true;
            }

            onPasswordMismatch: {
                passwordMismatchText.visible = true;
            }

            onUserCreated: {
                stackView.push(Qt.resolvedUrl("Fridge.qml"))
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
