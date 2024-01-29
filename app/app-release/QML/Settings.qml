import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts

Popup {
    id: settingswindow
    anchors.centerIn: parent
    width: Screen.width / 2.5
    height: Screen.height / 1.3
    focus: true
    closePolicy: Popup.CloseOnEscape
    modal: true

    background: Rectangle {
        color: "#F0F0F0" // Light grey background
        radius: 12.5
        border.color: "#CCCCCC" // Light border color
        border.width: 1
    }

    property alias newPassword: changepw.text
    property alias confirmNewPassword: confirmpw.text
    property alias telegramUsername: telegramUser.text
    property alias confirmdeletion: confirmdelete.text

    //Column contains all the settings options
    Column {
        width: parent.width
        spacing: 5
        padding: 20
        anchors.centerIn: parent

        //Title bar
        Label {
            text: "Settings"
            leftPadding: 20
            rightPadding: 20
            font.pixelSize: 32
            color: "#1C6F30" // Dark color for the title
            horizontalAlignment: Text.AlignHCenter
        }

        //Password options
        Column {

            width: parent.width
            spacing: 20
            padding: 15

            Rectangle {
                    width: parent.width * 0.8
                    height: 1 // Adjust the height for border thickness
                    color: "#A0A0A0" // Border color
            }

            Label {
                text: "Change Password"
                color: "#28A745"
                font.pixelSize: 25
            }

            TextField {
                id: changepw
                property bool passwordVisible: false
                width: parent.width * 0.8
                placeholderText: "Enter new password"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                echoMode: passwordVisible ? TextField.Normal : TextField.Password
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    border.color: "#A0A0A0"
                    border.width: 0.5
                    radius: 8
                }


                Button {
                    id: toggleButton
                    width: 50
                    background: Rectangle {
                        color: "#D9E8FF" // Light blue for text field
                        radius: 8
                    }

                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 5
                    onClicked: parent.passwordVisible = !parent.passwordVisible

                    Text {
                        text: parent.parent.passwordVisible ? "Hide" : "Show"
                        color: "#544E3D" // Set your desired text color here
                        anchors.centerIn: parent
                    }
                }
            }

            TextField {
                id: confirmpw
                width: parent.width * 0.8
                placeholderText: "Confirm new password"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                echoMode: TextField.Password
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
                }
            }

            Label {
                id: updatemessagepw
                text: ""
            }


            Button {
                text: "Change Password"
                width: parent.width * 0.8
                background: Rectangle {
                    color: "#28A745" // Green for positive actions
                    radius: 8
                }
                onClicked: {
                    updatemessagepw.text = settingsManager.changePassword(changepw.text, confirmpw.text)
                    changepw.text = ""
                    confirmpw.text = ""
                }
            }

        }

        //Telegram options
        Column {

            width: parent.width
            spacing: 20
            padding: 15

            Rectangle {
                    width: parent.width * 0.8
                    height: 1 // Adjust the height for border thickness
                    color: "#A0A0A0" // Border color
            }

            Label {
                text: "Telegram"
                color: "#28A745"
                font.pixelSize: 25
            }

            GridLayout {
                id: telegram
                columns:3
                width: parent.width * 0.8

                Text { text: "Telegram Username"; color: "#28A745"; Layout.preferredWidth: 75}
                Text { text: "Notifications"; color: "#28A745" }
                Text { text: "   "} // placeholder for the other grid item
                //Text { text: "   "}

                TextField {
                    id: telegramUser
                    width: parent.width
                    placeholderText: "Bind Telegram Username"
                    placeholderTextColor: "#A0A0A0"
                    color: "#544E3D"
                    background: Rectangle {
                        color: "#D9E8FF" // Light blue for text field
                        radius: 8
                    }
                }

                Text { text: "Food expiry"; color: "#1C6F30"}

                Switch {
                    id: toggleSwitchexpiry
                    // Position and size
                    width: 60
                    height: 30

                    // Toggle logic
                    onToggled: {
                        console.log("Toggle state:", checked ? "On" : "Off");
                    }
                }


                Button {
                    text: "Bind Telegram Username"
                    width: parent.width * 0.8
                    background: Rectangle {
                        color: mouseAreatelegram.containsMouse ? "#17A2B8" : "#28A745" // Yellow, turns red on hover
                        radius: 8
                    }
                    MouseArea {
                        id: mouseAreatelegram
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            // Logic to bind Telegram username
                            settingsManager.bindTelegramUsername(telegramUser.text)
                            telegramUser.text = ""
                        }
                    }
                }

                Text { text: "Marketplace notifications"; color: "#1C6F30"}

                Switch {
                    id: toggleSwitchmarket
                    // Position and size
                    width: 60
                    height: 30

                    // Toggle logic
                    onToggled: {
                        console.log("Toggle state:", checked ? "On" : "Off");
                    }
                }

            }







        }

        //Account deletion
        Column {

            spacing: 20
            width: parent.width
            padding: 15

            Rectangle {
                    width: parent.width * 0.8
                    height: 1 // Adjust the height for border thickness
                    color: "#A0A0A0" // Border color
            }

            Label {
                text: "Delete account"
                color: "#28A745"
                font.pixelSize: 25
            }

            Label {
                text: "WARNING: This process is irreversible!"
                color: "red"
            }

            TextField {
                id: confirmdelete
                width: parent.width* 0.8
                placeholderText: "Type your password to confirm"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                echoMode: TextField.Password
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
                }

            }

            Button {
                text: "Delete Account"
                width: parent.width * 0.8
                background: Rectangle {
                    color: mouseAreadelete.containsMouse ? "#DC3545" : "#28A745" // Yellow, turns red on hover
                    radius: 8
                }

                MouseArea {
                    id: mouseAreadelete
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        // Add logic for account deletion confirmation
                    }
                }
            }

        }

    }

    //Bottom buttons
    Row {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Button {
            text: "Cancel"
            background: Rectangle {
                color: "#6C757D" // Grey for neutral/cancel actions
                radius: 8
            }
            onClicked: {
                settingswindow.close()
                changepw.text = ""
                confirmpw.text = ""
                telegramUser.text = ""
            }
        }

        Button {
            text: "Apply"
            background: Rectangle {
                color: "#28A745" // Blue for apply/confirm actions
                radius: 8
            }
            onClicked: {

                updatemessagepw.text = settingsManager.changePassword(changepw.text, confirmpw.text)
                changepw.text = ""
                confirmpw.text = ""

                settingsManager.bindTelegramUsername(telegramUser.text)
                telegramUser.text = ""

                // Save the preferences of the switch buttons
                let notificationSettings = settingsManager.processNotifications(toggleSwitchexpiry.checked, toggleSwitchmarket.checked);
                // Use notificationSettings as needed

            }
        }
    }
}
