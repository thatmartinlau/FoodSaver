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
                    id: usernameError
                    visible: false // Initially hidden
                    text: "This username is already taken"
                    color: "red"
                }
                Text {
                    id: passwordError
                    visible: false // Initially hidden
                    text: "The password does not match"
                    color: "red"
                }

        // Page components
        TextField {
            width: parent.width
            id: input_username
            placeholderText: "Username"
        }
        TextField {
            width: parent.width
            id: input_password
            placeholderText: "Password"
            echoMode: TextField.Password //hide text
        }
        Button {
            anchors.left: parent.left
            text: "New here?"
            onClicked: stackView.push(Qt.resolvedUrl("SigninPage.qml"))
        }

        Button {
            anchors.left: parent.left
            text: "Login"
            Button {
                anchors.left: parent.left
                text: "Login"
                onClicked: {
                    var loginSuccess = login.checkCredentials(input_username.text, input_password.text);
                    if (loginSuccess) {
                        console.log("Login successful");
                        stackView.push(Qt.resolvedUrl("Fridge.qml"))
                        // Navigate to the next page or perform the desired action
                    } else {
                        console.log("Login failed");
                        // Optionally, set error message visibility here
                        usernameError.visible = true;
                        passwordError.visible = true;
                    }
                }
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
