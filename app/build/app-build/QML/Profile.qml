import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3


//MENU FOR THE PREFERENCES MENU
//Shall include the following features:
//Ability to change what their food diets and allergies are
//Ability to change their display name and 103 address
//Ability to add a photo, potentially

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

    Column {
        width: parent.width
        spacing: 10
        padding: 20

        Label {
            text: "Profile"
            font.pixelSize: 32
            color: "#1C6F30" // Bright blue color for the title
            horizontalAlignment: Text.AlignHCenter
        }

        Column {
            width: parent.width
            spacing: 20
            padding: 15

            Label {
                text: "Personal Information"
                color: "#28A745"
                font.pixelSize: 25
            }

            // Adjusted Row
            GridLayout {
                columns: 2
                columnSpacing: 10
                width: parent.width

                TextField {
                    Layout.fillWidth: true
                    height: 10
                }

                TextField {
                    Layout.fillWidth: true
                    height: 10
                }
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
    }
}


