import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    width: 320
    height: 480

    ColumnLayout {
        anchors.centerIn: parent
        Button { text: "Menu 1"; onClicked: stackView.push(Qt.resolvedUrl("Menu1.qml")) }
        Button { text: "Menu 2"; onClicked: stackView.push(Qt.resolvedUrl("Menu2.qml")) }
        Button { text: "Menu 3"; onClicked: stackView.push(Qt.resolvedUrl("Menu3.qml")) }
        Button { text: "Menu 4"; onClicked: stackView.push(Qt.resolvedUrl("menu4.qml")) }
    }
}
