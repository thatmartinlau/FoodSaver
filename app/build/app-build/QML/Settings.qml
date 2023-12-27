import QtQuick 2.12
import QtQuick.Controls 2.15


Popup {
    id: settings
    property alias changePassoword: changepw.text
    property alias confirmChangePassowrd: confirmpw.text

    anchors.centerIn: parent
    width: Screen.width / 2.5
    height: Screen.height / 2
    closePolicy: "CloseOnEscape"
    background: Rectangle {
            color:"#EEEEEE"
            radius: 12.5
            border.color: "black"
            border.width: 1
        }




    //Text
    Rectangle {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

        Label {
            text: "Settings"
            color: "black"
        }
    }


    //Profile options



    //
    Column {

        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 10
        spacing: 10

        Label {
            id: changepwlabel
            text: "Change password"
            color: "#000000"
        }

        TextField {
            padding: 5
            id: changepw
            width: 190
            height: 25
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
            placeholderText: "Enter new password"

            echoMode: TextField.Password
        }

        TextField {
            id: confirmpw
            width: 190
            height: 25
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
            placeholderText: "Confirm your password"
            echoMode: TextField.Password
        }

        Button {
            text: "Change password"
            id: changepwbutton
            width: 100
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
            onClicked: {} //insert the function that makes the button do something
        }

        Button {
            text: "Delete account"
            id: nukeyourself
            width: 100
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }

            //this part makes the button turn red when hovered over
            MouseArea {
                anchors.fill: parent // Fill the entire area of the rectangle
                hoverEnabled: true   // Enable hover events

                onEntered: {
                    nukeyourself.background.color = "red" // Change color on hover
                }
                onExited: {
                    nukeyourself.background.color = "#5E9F7C"  // Revert color when mouse leaves
                }
            }

            // Opens up a second popup to confirm whether they really want to delete their account
            onClicked: {

            }


        }


    // end of column definition
    }

    Row {
        anchors.bottom:parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 10
        anchors.rightMargin: 10
        spacing: 10

        Button {
            text: "Cancel"
            width: 100
            background: Rectangle {
                color: "#5E9F7C"
                radius:12.5
            }
            onClicked: {
                settings.close()
                changepw.text = ""
                confirmpw.text = ""
            }

        }

        Button {
            text: "Apply"
            width: 100
            //anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius:12.5
            }

            onClicked: {
                settings.close() // IMPORTANT: include a function which also submits these settings changes.
            }
        }
    }
// end of popup definition
}
