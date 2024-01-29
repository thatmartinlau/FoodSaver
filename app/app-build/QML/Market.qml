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
        color: "#5E9F7C" // background

        // Sorting buttons
        Rectangle {
            id:mainrectangle
            visible: true
            y: parent.height * 0.05
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white" // main important rectangle
            property string newItemText: ""

            Column {
                height: parent.height
                width: parent.width
                padding: parent.width *0.01
                spacing: parent.width *0.01

                // Main title of page
                Label {
                    Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                    text: "Market Place 🛒"
                    font.bold: true
                    color: "#1C6F30"
                    font.pixelSize: 50
                    padding: 10
                }

                Rectangle {
                    radius: 12.5
                    width: parent.width * 0.98
                    height: parent.width * 0.05
                    color:"#EEEEEE" // search bar

                    //update with options!
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
                    id:scrollrectangle
                    radius: 12.5
                    y: mainrectangle.y
                    height: 710
                    width: parent.width
                    color: "transparent" // main scroll rectangle
                    //clip: true
                    // visible: true

                    ScrollView {
                        id: scrollMarket
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        //clip: true

                        //contentHeight: columnLayout.implicitHeight

                        ColumnLayout{
                            id:columnLayout
                            spacing: 10
                            anchors.fill: parent

                            // Model to add items
                            Repeater{
                                model: ListModel{
                                    ListElement{name: "Banana"; category: "Fruits"; timeLeft: "2 days"; price: "$2.00"; emoji: "🍌"; user: "User BX25"; quantity: "2"}
                                    ListElement{name: "Apple"; category: "Fruits"; timeLeft: "1 day"; price: "$1.50"; emoji: "🍎"; user: "User BX25"; quantity: "3"}
                                    ListElement{name: "Milk"; category: "Dairy"; timeLeft: "3 days"; price: "$3.00"; emoji: "🥛"; user: "User BX25"; quantity: "1"}
                                    ListElement { name: "Eggs"; category: "Dairy"; timeLeft: "4 days"; price: "$2.50" ; emoji: "🥚"; user: "User BX25"; quantity: "6"}
                                    ListElement { name: "Carrot"; category: "Vegetables"; timeLeft: "2 days"; price: "$1.00"; emoji: "🥕" ; user: "User BX25"; quantity: "2"}
                                    ListElement { name: "Onions"; category: "Vegetables"; timeLeft: "3 days"; price: "$1.20" ; emoji: "🧅"; user: "User BX25"; quantity: "3"}
                                    ListElement { name: "Spinach"; category: "Vegetables"; timeLeft: "1 day"; price: "$1.80"; emoji: "🥬" ; user: "User BX25"; quantity: "1"}
                                    ListElement { name: "Avocado"; category: "Fruits"; timeLeft: "2 days"; price: "$2.50"; emoji: "🥑"; user: "User BX25" ; quantity: "2"}
                                }


                                delegate: Rectangle{
                                    width: scrollrectangle.width - 25
                                    height: 150
                                    color: "#D7ECDE"
                                    radius: 5

                                    // Display information for each item
                                    Row{
                                        spacing: 5
                                        anchors.leftMargin: 10
                                        anchors.topMargin: 10
                                        anchors.fill: parent

                                        Rectangle{
                                            radius: 12.5
                                            width: parent.height - 10
                                            height: parent.height - 10
                                            color: "white"

                                            Label{
                                                text: "Photo"
                                                font.bold: true
                                                font.pixelSize: 18
                                                anchors.centerIn: parent
                                            }
                                        }

                                    // info on each item
                                    Column{
                                        spacing: 5
                                        anchors.leftMargin: 140
                                        anchors.fill: parent
                                        padding: 5

                                        Text {
                                            text: model.name
                                            font.bold: true
                                            font.pixelSize: 20
                                        }

                                        Text {
                                            text: "Category: " + model.category
                                            font.pixelSize: 16
                                        }

                                        Text {
                                            text: "Quantity: " + model.quantity
                                            font.pixelSize: 16
                                        }

                                        Text {
                                            text: "Time left: " + model.timeLeft
                                            font.pixelSize: 16
                                        }

                                        Text {
                                            text: "Price: " + model.price
                                            font.pixelSize: 16
                                        }

                                    }

                                    Row{
                                        spacing: 5
                                        anchors.leftMargin: parent.width/2
                                        anchors.fill: parent
                                        padding: 10

                                        Button {
                                            text: "Add to Basket"
                                            //anchors.centerIn: parent
                                            anchors.verticalCenter: parent.verticalCenter

                                            MouseArea {
                                                anchors.fill: parent
                                                onClicked: {
                                                    myBasket.open() // need to change so that it adds it actually to the basket
                                                }
                                            }
                                        }
                                    }
                                }

                                }


                            }
                        }
                    height: 710
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

