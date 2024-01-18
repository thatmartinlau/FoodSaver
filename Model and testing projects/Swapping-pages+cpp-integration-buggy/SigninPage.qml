import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    Button {
        text: "Login"
        onClicked: stackView.push("HomePage.qml")
    }
    Button {
        text: "Already have an account?"
        onClicked: stackView.push("LoginPage.qml")
    }
}
