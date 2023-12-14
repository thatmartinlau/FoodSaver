import QtQuick 6.2
import QtQuick.Controls 6.2

Button {
    id: button
    property color property: "#3445d4"
    text: qsTr("test22")
    anchors.verticalCenter: parent.verticalCenter
    property int property0: 0
    anchors.verticalCenterOffset: 0
    anchors.horizontalCenterOffset: 1
    checkable: true
    anchors.horizontalCenter: parent.horizontalCenter

    Connections {
        target: button
        onClicked: rectangle.state = "clicked"
    }

    Connections {
        target: button
        onToggled: rectangle.state = "clicked"
    }

    Connections {
        target: button
        onClicked: rectangle.state = ""
    }
}
