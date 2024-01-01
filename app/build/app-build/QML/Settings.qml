import QtQuick 2.12
import QtQuick.Controls 2.15

Popup {
    id: settingswindow
    anchors.centerIn: parent
    width: Screen.width / 2.5
    height: Screen.height / 1.5
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

    Column {
        width: parent.width
        spacing: 10
        padding: 20

        Label {
            text: "Settings"
            leftPadding: 20
            rightPadding: 20
            font.pixelSize: 32
            color: "#1C6F30" // Bright blue color for the title
            horizontalAlignment: Text.AlignHCenter
        }

        Column {

            width: parent.width
            spacing: 20
            padding: 15

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
                    // Add logic to change password
                }
            }

        }

        Column {

            width: parent.width
            spacing: 20
            padding: 15

            Label {
                text: "Telegram"
                color: "#28A745"
                font.pixelSize: 25
            }

            TextField {
                id: telegramUser
                width: parent.width * 0.8
                placeholderText: "Bind Telegram Username"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
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
                        // Add logic to bind Telegram username
                    }
                }
            }

        }

        Column {

            spacing: 20
            width: parent.width
            padding: 15

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
                settingswindow.close()
                // Add logic to apply settings changes
            }
        }
    }
}
