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

        // Custom push transition
        pushTransition: Transition {
            // Define the animation for the push transition
            NumberAnimation {
                properties: "opacity, x"
                from: 640
                to: 0
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }

        // Custom pop transition
        popTransition: Transition {
            // Define the animation for the pop transition
            NumberAnimation {
                properties: "opacity, x"
                from: 0
                to: -640
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }

    }
}
