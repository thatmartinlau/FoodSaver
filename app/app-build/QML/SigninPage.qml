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
            color: "#1C6F30"
            font.pixelSize: 32
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
            id: noUsernameError
            visible: false // Initially hidden
            text: "You need to chose a username"
            color: "red"
        }
        Text {
            id: noPasswordError
            visible: false // Initially hidden
            text: "You need to chose and verify your password"
            color: "red"
        }
        Text {
            id: shortPasswordError
            visible: false // Initially hidden
            text: "Password must contain at least 8 characters"
            color: "red"
        }
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

        // Regular page components
        TextField {
            width: parent.width
            id: input_username
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            placeholderText: "Chose a username"
        }
        TextField {
            width: parent.width
            id: input_telegram_username
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            placeholderText: "Fill in your telegram username"
        }
        TextField {
            width: parent.width
            id: input_password
            placeholderText: "Chose a password"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            echoMode: TextInput.Password //hide the text
        }
        TextField {
            width: parent.width
            id: input_password_check
            placeholderText: "Verify your password"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            echoMode: TextInput.Password //hide the text
        }
        Text {
            anchors.left: parent.left
            text: "Do you already have an account?"
            color: "#1C6F30"
            font.bold: true

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    stackView.push(Qt.resolvedUrl("LoginPage.qml"))
                }
            }
        }

        Button {
            anchors.left: parent.left
            text: "Sign in"
            background: Rectangle {
                    color: "#1C6F30"
                    radius: 4
            }
            contentItem: Text { // Text properties
                text: parent.text
                font: parent.font
                color: "white"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                padding: 5
            }
            onClicked: {
                if (signin.signIn(input_username.text, input_password.text, input_password_check.text, input_telegram_username.text)){
                    passwordError.visible = false;
                    usernameError.visible = false;
                    noUsernameError.visible = false;
                    noPasswordError.visible = false;
                    shortPasswordError.visible = false;
                }
                input_username.text = ""
                input_password.text = ""
                input_password_check.text = ""
                input_telegram_username.text = ""
            }
        }


        // Implementing connections to C++ code
        Connections {
            target: signin

            // Errors upon signin
            function onOpenNoUsernameError() {
                noUsernameError.visible = true;
                usernameError.visible = false;
                passwordError.visible = false;
                noPasswordError.visible = false;
                shortPasswordError.visible = false;
            }
            function onOpenPasswordError() {
                noUsernameError.visible = false;
                usernameError.visible = false;
                passwordError.visible = true;
                noPasswordError.visible = false;
                shortPasswordError.visible = false;
            }
            function onOpenUsernameError() {
                noUsernameError.visible = false;
                passwordError.visible = false;
                usernameError.visible = true;
                noPasswordError.visible = false;
                shortPasswordError.visible = false;
            }
            function onOpenNoPasswordError() {
                noUsernameError.visible = false;
                noPasswordError.visible = true;
                passwordError.visible = false;
                usernameError.visible = false;
                shortPasswordError.visible = false;
            }
            function onOpenShortPasswordError() {
                noUsernameError.visible = false;
                noPasswordError.visible = false;
                shortPasswordError.visible = true;
                passwordError.visible = false;
                usernameError.visible = false;
            }

            // Successful singin
            function onOpenMarketPage() {
                var currentUsername = CurrentUser.username;
                var currentPassword = CurrentUser.password;
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
