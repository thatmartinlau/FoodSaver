import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: Screen.width
    height: Screen.width
    title: "Main Window"

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: LoginPage {}
    }
}
