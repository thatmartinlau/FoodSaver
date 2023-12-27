import QtQuick 2.12
import QtQuick.Controls 2.12

//Hello hello Fanny,
//Sorry i kinda stole a bit of your work from you, it was just a small amount of changes to get the ball rolling
//Could you continue working on this page by writing the C++ code to complete the login functions?
//It would also be rly good if you could also make a page for new users to register, as well as the c++ code for that
//Thanks!

//PS: delete these comments once you see them, and text me the word 'banana' on Telegram.
//-Martin

Item {

    // FOODSAVER LOGO/LABEL

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height/3.3

        Label {
            horizontalAlignment: Text.AlignHCenter // Center the text within the Label
            anchors.horizontalCenter: parent.horizontalCenter // Center the Label within the Rectangle
            text: "Welcome to FoodSaver!"
        }
    }

    // TEXT ENTRIES + BUTTON

    Column{
        spacing: 10
        width: 300

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        TextField {
            width: parent.width
            id: input_username
            placeholderText: "Username"
        }
        TextField {
            width: parent.width
            id: input_password
            placeholderText: "Password"
        }

        Button {
            anchors.left: parent.left
            text: "Login"
            onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) //replace this soon with the login function, to be implemented
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
