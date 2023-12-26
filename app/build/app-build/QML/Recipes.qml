import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Column {

        anchors.left: parent.left
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: parent.width * 0.05

        Button { text: "Fridge";  onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
        Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
        Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
        Button { text: "Recipes"; enabled: false; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

    }
    // BOTTOM BUTTONS

    Settings {
        id: settings
    }

    Button {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        id: button
        text: "Settings"
        onClicked: {
        settings.open()
        }
    }

    Button {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.bottomMargin: 10

        text: "Logout"
        onClicked: stackView.pop() // need to add a function which logs the user out of the server, then deletes all active data from the instance.
    }

}
