import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Button {
        text: "Menu 1"
        onClicked: stackView.push("Menu1.qml")
    }
    Button {
        text: "Menu 2"
        y: 50
        onClicked: stackView.push("Menu2.qml")
    }
    Button {
        text: "Fridge"
        y: 100
        onClicked: stackView.push("Menu3.qml")
    }
}
