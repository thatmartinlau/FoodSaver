import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//colors: green #5E9F7C lightgreen #D7ECDE

Row {
    property int currentIndex: 0

    // Sidebar with navigation buttons
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
            // left column with option  to navigate pages
            Column {

                anchors.left: parent.left
                anchors.bottom: parent.verticalCenter
                anchors.leftMargin: parent.width * 0.05

                Button { text: "Fridge";  onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
                Button { text: "Market"; enabled: false; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
                Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
                Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

            }
            // Down-left settings button
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
        }


    // Main content area for the marketplace
    Rectangle {
        x: parent.width * 0.20
        width: parent.width * 0.6
        height: parent.height
        color: "#5E9F7C"

        Rectangle {
            y: parent.height * 0.05
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white"

            // Content for the marketplace
            Column {

                Row {
                    anchors.bottom: parent.bottom
                    TextField {
                        id: itemTextField
                        placeholderText: "Search for a specific item"
                    }

                    Button {
                        text: "Category"
                        onClicked: {
                        }
                    }

                    Button {
                        text: "Time left"
                        onClicked: {
                        }
                    }

                    Button {
                        text: "Price"
                        onClicked: {
                        }
                    }
                }
            }
        }
    Rectangle{
        radius: 12.5
        y: parent.height*0.2
        height: parent.height*0.8
        width: parent.width
        ScrollView{
            id: scrollView
            anchors.fill: parent
            width:parent.width
        Column{
            spacing: 2.5
            width: parent.width
            Repeater{
                model:itemModel
                Rectangle{
                    radius: 12.5
                    width: parent.width
                    height: 200
                    color: "yellow"

                }

            }
        }
        }
    }

}


    // Sidebar with additional buttons
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        anchors.right: parent.right

        Button {
            y: parent.height * 0.05
            id: basket
            text: "My Basket"
        }

        Button {
            y: parent.height * 0.25
            text: "Add to Fridge"
            onClicked: {
                addtofridge.open()
            }
        }

        Button {
            y: parent.height * 0.75
            x: parent.width * 0.5 - 50
            id: profil
            height: 100
            width: 100
            text: "Profile"
            onClicked: {
                profile.open()
            }
            background: Rectangle {
                color: "#D7ECDE"
                radius: 12.5
            }
        }

        // Example of a logout button with modified text
        Button {
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 10
            anchors.bottomMargin: 10

            text: "Logout"
            onClicked: stackView.pop() // need to add a function which logs the user out of the server, then deletes all active data from the instance.
        }
    }

    // Additional components
    Profile {
        id: profile
    }

    Settings {
        id: settings
    }

    AddToFridge {
        id: addtofridge
    }

    Selling {
        id: selling
    }
}