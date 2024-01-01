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

            // ... Label for title ...

            TextField {

            }

            GridLayout {
                columns: 2
                columnSpacing: 10
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width - (padding * 2) // Adjust for padding

                // Configure columns to have equal width
                Column {
                    Layout.fillWidth: true

                    TextField {
                        width: parent.width
                        height: 10
                        // Other TextField properties
                    }
                }

                Column {
                    Layout.fillWidth: true

                    TextField {
                        width: parent.width
                        height: 10
                        // Other TextField properties
                    }
                }
            }

            Column {
                width: parent.width
                spacing: 20
                padding: 15

                // ... Label for Personal Information ...

                Button {
                    // ... Button properties ...
                }
            }
    }
}


