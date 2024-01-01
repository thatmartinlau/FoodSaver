import QtQuick 2.12
import QtQuick.Controls 2.15

//MENU FOR THE PREFERENCES MENU
//Shall include the following features:
//Ability to change what their food diets and allergies are
//Ability to change their display name and 103 address
//Ability to add a photo, potentially

Popup {
    id: prefwindow
    //window positioning
    anchors.centerIn: parent

    width: Screen.width / 2.5
    height: Screen.height / 2

    focus: true //Listen to keyboard inputs
    closePolicy: "CloseOnEscape" //Close upon escape button pressed
    modal:true //Make it so no other buttons can be pressed while the popup is opened.

    //background information
    background: Rectangle {
            color:"#EEEEEE"
            radius: 12.5
            border.color: "black"
            border.width: 1
        }

    //this part makes it so that information can pass in and out of the popup.
    //property alias "something"

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
                prefwindow.close()

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
                prefwindow.close() // IMPORTANT: include a function which also submits these settings changes.
            }
        }
    }
// end of popup definition
}
