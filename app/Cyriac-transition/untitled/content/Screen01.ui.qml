/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.2
import QtQuick.Controls 6.2
import untitled

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: "#facffb"

    property alias button: button
    property alias label: label

    Button {
        id: button
        property color property: "#3445d4"
        text: qsTr("test22")
        anchors.verticalCenter: parent.verticalCenter
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

        Connections {
            target: button
            onPressAndHold: rectangle.state = ""
        }
    }

    Text {
        id: label
        text: qsTr("Hello untitled")
        anchors.top: button.bottom
        anchors.horizontalCenterOffset: 2
        font.family: Constants.font.family
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        SequentialAnimation {
            id: animation

            ColorAnimation {
                id: colorAnimation1
                target: rectangle
                property: "color"
                to: "#3445d4"
                from: Constants.backgroundColor
            }

            ColorAnimation {
                id: colorAnimation2
                target: rectangle
                property: "color"
                to: Constants.backgroundColor
                from: "#2294c6"
            }
        }
    }
    states: [
        State {
            name: "clicked"
            when: button.checked

            PropertyChanges {
                target: label
                text: qsTr("Button NOT Checked")
            }

        }
    ]


}
