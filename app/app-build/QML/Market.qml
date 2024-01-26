import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//colors: green #5E9F7C lightgreen #D7ECDE

Row {
    property int currentIndex: 0
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        Column {

            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.05

                Button { text: "Fridge";  onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
                Button { text: "Market"; enabled: false; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
                Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
                Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

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
    }

    // Main content area for the marketplace
    Rectangle {
        x: parent.width * 0.20
        width: parent.width * 0.6
        height: parent.height
        color: "#5E9F7C"

        // Sorting buttons
        Rectangle {
            visible: true
            y: parent.height * 0.05
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white"
            property string newItemText: ""

            Column {
                height: parent.height
                width: parent.width
                padding: parent.width *0.01
                spacing: parent.width *0.01

                // Main title of page
                Label {
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    text: "Market Place"
                    font.bold: true
                    color: "#1C6F30"
                    font.pixelSize: 50
                    padding: 10
                }

                Rectangle {
                    radius: 12.5
                    width: parent.width * 0.98
                    height: parent.width * 0.05
                    color:"#EEEEEE"

                    Row {
                        spacing: 10
                        padding:10
                        anchors.verticalCenter:parent.verticalCenter
                        TextField {
                            y:3
                            id: itemTextFieldFridge
                            placeholderText: "Search for a specific item"
                            //onTextChanged: newItemText = itemTextField.text // Update the newItemText on text change
                        }

                        Button {
                            text: "Category"
                            onClicked: {
                               //std::vector<Ingredient> sorted_fridge = sort_ingredient_by_category()
                            }
                        }

                        Button {
                            text: "Time left"
                            onClicked: {
                                //std::vector<Ingredient> sorted_fridge = sort_ingredient_by_expiration_date()
                            }
                        }

                        Button {
                            text: "Price"
                            onClicked: {
                                //std::vector<Ingredient> sorted_fridge = sort_ingredient_by_price()
                            }
                        }
                    }
                }

                // Items display with scroll

                Rectangle {
                    radius: 12.5
                    y: parent.height * 0.2
                    height: parent.height * 0.8
                    width: parent.width
                    color:"transparent"

                    Rectangle{
                        width: parent.width -25
                        height: parent.height * 0.8
                        color: "white"

                        ListView{
                            id: marketListView
                            anchors.fill: parent
                            spacing: 10
                            // width: parent.width
                            //height: parent.height * 0.8
                            model: ListModel {

                                // Manually added items to test display
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}
                                ListElement{name: "Item"}

                                // Function to add items goes here
                            }
                            delegate: Item {
                                width: marketListView.width
                                height: 125

                                Rectangle{
                                    width: parent.width - 25
                                    height: 125
                                    color: "#EEEEEE"
                                    radius: 5

                                    // Display for each item

                                    Row{
                                        spacing: 5
                                        anchors.leftMargin: 10
                                        anchors.topMargin: 10
                                        anchors.fill: parent

                                        Rectangle{
                                            radius: 12.5
                                            width: parent.height - 10
                                            height: parent.height - 10
                                            color: "#D7ECDE"
                                            Label{
                                                text: "Photo"
                                                font.bold: true
                                                anchors.centerIn: parent
                                            }
                                        }

                                        Column{
                                            spacing: 5
                                            anchors.leftMargin: 120
                                            anchors.fill: parent

                                            Text {
                                                text: model.name
                                                font.bold: true
                                                font.pixelSize: 18
                                                anchors.margins: 10
                                            }

                                            Text {
                                                text: "Category: " + model.category
                                                font.pixelSize: 16
                                                anchors.margins: 10
                                            }

                                            Text {
                                                text: "Time left: " + model.timeLeft
                                                font.pixelSize: 16
                                                anchors.margins: 10
                                            }

                                            Text {
                                                text: "Price: " + model.price
                                                font.pixelSize: 16
                                                anchors.margins: 10
                                            }

                                        }
                                    }
                                }

                            }
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
            onClicked: {
                myBasket.open()
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

    Basket {
        id: myBasket
    }

    Selling {
        id: selling
    }
}

