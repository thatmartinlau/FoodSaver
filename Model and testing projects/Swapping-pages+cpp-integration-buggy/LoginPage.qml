import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Button {
        text: "Login"
        onClicked: stackView.push("HomePage.qml")
    }
    Button {
        text: "New here?"
        y: 50
        onClicked: stackView.push("Menu2.qml")
    }
}
