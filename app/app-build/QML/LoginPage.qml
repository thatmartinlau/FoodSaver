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
            text: "Welcome back to FoodSaver!"
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
            id: noUsernameError2
            visible: false // Initially hidden
            text: "No username given"
            color: "red"
        }
        Text {
            id: noPasswordError2
            visible: false // Initially hidden
            text: "No password given"
            color: "red"
        }
        Text {
            id: usernameError2
            visible: false // Initially hidden
            text: "This username is not registered"
            color: "red"
        }
        Text {
            id: passwordError2
            visible: false // Initially hidden
            text: "The password is incorrect"
            color: "red"
        }

        // Regular page components
        TextField {
            width: parent.width
            id: input_username2
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            placeholderText: "username"
        }

        TextField {
            width: parent.width
            id: input_password2
            placeholderText: "password"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            echoMode: TextInput.Password //hide the text
        }

        Text {
            anchors.left: parent.left
            text: "New here?"
            color: "#1C6F30"
            font.bold: true

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    stackView.push(Qt.resolvedUrl("SigninPage.qml"))
                }
            }
        }

        Button {
            anchors.left: parent.left
            text: "Log in"
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
                stackView.push(Qt.resolvedUrl("Market.qml"))
                // if (login.logIn(input_username2.text, input_password2.text)){
                //                     passwordError.visible = false;
                //                     usernameError.visible = false;
                //                     noUsernameError.visible = false;
                //                     noPasswordError.visible = false;
                //                 }
                // input_username2.text = ""
                // input_password2.text = ""
            }

        }


        // Implementing connections to C++ code
        Connections {
            target: login

            // Errors upon login
            function onOpenNoUsernameError2() {
                noUsernameError.visible = true;
                usernameError.visible = false;
                passwordError.visible = false;
                noPasswordError.visible = false;
            }
            function onOpenPasswordError2() {
                noUsernameError.visible = false;
                usernameError.visible = false;
                passwordError.visible = true;
                noPasswordError.visible = false;
            }
            function onOpenUsernameError2() {
                noUsernameError.visible = false;
                passwordError.visible = false;
                usernameError.visible = true;
                noPasswordError.visible = false;
            }
            function onOpenNoPasswordError2() {
                noUsernameError.visible = false;
                noPasswordError.visible = true;
                passwordError.visible = false;
                usernameError.visible = false;
            }

            // Successful login
            function onOpenMarketPage2() {
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
