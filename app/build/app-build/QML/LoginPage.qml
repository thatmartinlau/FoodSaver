import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    width: 320
    height: 480

    Button {
        text: "Login"
        anchors.centerIn: parent
        onClicked: stackView.push(Qt.resolvedUrl("HomePage.qml"))
    }
}
