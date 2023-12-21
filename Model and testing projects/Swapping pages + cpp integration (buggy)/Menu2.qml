import QtQuick 2.12
import QtQuick.Controls 2.12


Column {
    spacing: 50

    Button {
        text: "Back to Home"
        onClicked: stackView.pop()
    }

    TextField {
            id: nameInput
            width: 200
            height: 40
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "Enter your name"
        }

    Button {
        text: "Enter Name"
        anchors.top: nameInput.bottom

        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            backend.storeName(nameInput.text)
            nameInput.text = "";
        }
    }

    Button {
        text: "Show Name History"
        anchors.top: parent.top
        anchors.topMargin: 50
        onClicked: nameHistoryLabel.text = backend.getNameHistory().join(", ")
    }

    Label {
        id: nameHistoryLabel
        anchors.top: parent.top
        anchors.topMargin: 100
    }
}
