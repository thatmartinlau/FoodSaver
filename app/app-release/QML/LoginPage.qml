import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Column {
        Button {
            text: "market"
            onClicked: {stackView.push(Qt.resolvedUrl("Market.qml"))}
        }
        Button {
            text: "fridge"
            onClicked: {stackView.push(Qt.resolvedUrl("Fridge.qml"))}
        }
    }

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

        Rectangle {
            id: customButton
            width: 60
            height: 20
            color: "#1C6F30"
            radius: 4

            Text {
                anchors.centerIn: parent
                text: "Log in"
                color: "white"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Button clicked!");
                    if (login.logIn(input_username2.text, input_password2.text)) {
                        passwordError.visible = false;
                        usernameError.visible = false;
                        noUsernameError.visible = false;
                        noPasswordError.visible = false;
                    }
                    input_username2.text = "";
                    input_password2.text = "";
                }
            }
        }

        // Implementing connections to C++ code
        Connections {
            target: login

            // Errors upon login
            function onOpenNoUsernameError2() {
                noUsernameError2.visible = true;
                usernameError2.visible = false;
                passwordError2.visible = false;
                noPasswordError2.visible = false;
            }
            function onOpenPasswordError2() {
                noUsernameError2.visible = false;
                usernameError2.visible = false;
                passwordError2.visible = true;
                noPasswordError2.visible = false;
            }
            function onOpenUsernameError2() {
                noUsernameError2.visible = false;
                passwordError2.visible = false;
                usernameError2.visible = true;
                noPasswordError2.visible = false;
            }
            function onOpenNoPasswordError2() {
                noUsernameError2.visible = false;
                noPasswordError2.visible = true;
                passwordError2.visible = false;
                usernameError2.visible = false;
            }

            // Successful login
            function onOpenMarketPage2() {
                stackView.push(Qt.resolvedUrl("Market.qml"))
                var currentUsername = CurrentUser.username;
                var currentPassword = CurrentUser.password;
            }
        }
    }


    // SIDE + EXTRA BUTTONS
    Rectangle {
        width: 200
        height: 100.5
        color: "white"
        radius: 12.5
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.width * 0.6 * 0.04
        anchors.rightMargin: parent.width * 0.2 * 0.5 - 100

        Column {
            Rectangle {
                width: 200
                height: 50
                color: "transparent" // Transparent color
                radius: 12.5 // Add radius to the transparent rectangle

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        var url = "https://github.com/thatmartinlau/FoodSaver"
                        Qt.openUrlExternally(url)
                    }

                    Rectangle {
                        width: 24
                        height: 24
                        color: "#A3C995" // Updated color
                        radius: 2 // Updated radius
                        anchors.verticalCenter: parent.verticalCenter
                        x: 13 // Additional property for the small rectangle
                        Label {
                            text: "📄"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Label {
                        text: "About this project"
                        anchors.verticalCenter: parent.verticalCenter
                        x: 50 // Additional property for the label
                    }

                    hoverEnabled: true

                    onEntered: {
                        parent.color = "#D3D3D3"; // Light grey when hovered
                    }

                    onExited: {
                        parent.color = "transparent"; // Back to transparent when not hovered
                    }
                }
            }

            Rectangle {
                width: 200
                height: 0.5 // Height of the grey bar
                color: "#D3D3D3" // Light grey color
            }

            Rectangle {
                width: 200
                height: 50
                color: "transparent" // Transparent color
                radius: 12.5 // Add radius to the transparent rectangle

                MouseArea {
                    anchors.fill: parent
                    onClicked: Qt.quit()

                    Rectangle {
                        width: 24
                        height: 24
                        color: "#A3C995" // Updated color
                        radius: 2 // Updated radius
                        anchors.verticalCenter: parent.verticalCenter
                        x: 13 // Additional property for the small rectangle
                        Label {
                            text: "✖️"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Label {
                        text: "Exit"
                        anchors.verticalCenter: parent.verticalCenter
                        x: 50 // Additional property for the label
                    }

                    hoverEnabled: true

                    onEntered: {
                        parent.color = "#D3D3D3"; // Light grey when hovered
                    }

                    onExited: {
                        parent.color = "transparent"; // Back to transparent when not hovered
                    }
                }
            }
        }
    }
    /*Column {
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
    }*/
}
