import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    width: 320
    height: 480

    Button {
        text: "Back to Home"
        anchors.centerIn: parent
        onClicked: stackView.pop()
    }
}
