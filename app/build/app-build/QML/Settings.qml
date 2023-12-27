import QtQuick 2.12
import QtQuick.Controls 2.15


Popup {
    id: settings
    anchors.centerIn: parent
    property alias changePassoword: changepw.text
    property alias confirmChangePassowrd: confirmpw.text

    width: 200
    height: 300
    closePolicy: "CloseOnEscape"
    background: Rectangle {
            color:"#EEEEEE"
            radius: 12.5
            border.color: "black"
            border.width: 1
        }

    Button {
        anchors.right: parent.right
        anchors.top: parent.top
        text: "X"
        palette.buttonText:  "#000000"
        width: 50
        background: null
        onClicked: {
            settings.close()
        }
    }

    Column {

        anchors.centerIn: parent
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

        Popup {
            id: areyousure
            width: 300
            height: Screen.height
            background: Rectangle {
                    color:"#EEEEEE"
                    radius: 12.5
                    border.color: "black"
                    border.width: 1
                }
            Column {
                Label {
                    text: "WARNING: This process is irreversible."
                }
                Label {
                    text: "Input your password to confirm deletion of your account."
                }
                TextField {
                    id: confirmpw_delete
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
            }
            //end popup definition
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
                areyousure.open()
            }


        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Apply Changes"
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
    // end of column definition
    }
// end of popup definition
}
