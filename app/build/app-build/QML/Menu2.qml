import QtQuick 2.12
import QtQuick.Controls 2.12

Item {

    Label {
        text: "this is menu 2."
    }
    Button {
        text: "Back to Home"
        anchors.centerIn: parent
        onClicked: stackView.pop()
    }
}
