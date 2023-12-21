import QtQuick
import QtQuick.Controls

Item {
    Column {
        Row {

            Text {
                text: ""
            }

            TextInput {
                id: usernameTextInput
                text: ""

                inputMethodHints: Qt.ImhSensitiveData
                maximumLength: 30

                Text { // Placeholder hint for user
                    text: "Username"
                    color: "#aaa"
                    visible: !usernameInput.text
                }

            }
        }

        Row {

            Text {
                text: "Password: "
            }

            TextInput {
                id: passwordTextInput
                text: encryptedPassword?"password_encrypted":""

                inputMethodHints: Qt.ImhHiddenText
                echoMode: TextInput.Password // Hide password
                maximumLength: 30

                property bool encryptedPassword: false

                Text { // Placeholder hint for user
                    text: "Username"
                    color: "#aaa"
                    visible: !usernameInput.text
                }
            }

        }

        Button {
            text: "Login"

            onClicked: {
                wsClient.testUserLogin();
            }
        }
    }

    // Connect to WebsocketClient object in C++
    Connections {
        target: wsClient
    }
}
