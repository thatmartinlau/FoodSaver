import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Button {
        text: "Login"
        onClicked: stackView.push("HomePage.qml")
    }
}
