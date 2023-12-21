import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Main Window"

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: loginpage {}
    }
}
