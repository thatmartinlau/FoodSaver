import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    width: 200; height: 200
    color: "blue"
    MouseArea {
        anchors.fill: parent
        onClicked: window.close()
    }
}
