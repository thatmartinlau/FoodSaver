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
        Rectangle {
            width: 200
            height: 151
            color: "white"
            radius: 12.5
            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.5 - 100

            Column {
                Rectangle {
                    width: 200
                    height: 50
                    color: "transparent" // Light grey color
                    radius: 12.5 // Add radius to the grey rectangle

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.replace(Qt.resolvedUrl("Fridge.qml")) // Handle click event if needed
                        }

                        Rectangle {
                            width: 24
                            height: 24
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: 13 // Additional property for the small rectangle
                        }

                        Label {
                            text: "Fridge"
                            anchors.verticalCenter: parent.verticalCenter
                            x: 50 // Additional property for the label
                        }

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = "transparent"; // Back to white when not hovered
                        }
                    }
                }

                Rectangle {
                    width: 200
                    height: 0.5 // Height of the grey bar
                    color: "#D3D3D3" // Light grey color
                }

                Rectangle {
                    width: 200
                    height: 50
                    color: "#EEEEEE" // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    Rectangle {
                        width: 24
                        height: 24
                        color: "#A3C995" // Updated color
                        radius: 2 // Updated radius
                        anchors.verticalCenter: parent.verticalCenter
                        x: 13 // Additional property for the small rectangle
                    }

                    Label {
                        text: "Markets"
                        anchors.verticalCenter: parent.verticalCenter
                        x: 50 // Additional property for the label
                    }
                }

                Rectangle {
                    width: 200
                    height: 0.5 // Height of the grey bar
                    color: "#D3D3D3" // Light grey color
                }

                Rectangle {
                    width: 200
                    height: 50
                    color: "transparent" // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    MouseArea {
                        anchors.fill: parent
                        onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml"))

                        Rectangle {
                            width: 24
                            height: 24
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: 13 // Additional property for the small rectangle
                        }

                        Label {
                            text: "Recipes"
                            anchors.verticalCenter: parent.verticalCenter
                            x: 50 // Additional property for the label
                        }

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = "transparent"; // Back to transparent when not hovered
                        }
                    }
                }
            }
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

    Rectangle {
        x: parent.width * 0.20
        width: parent.width * 0.6
        height: parent.height
        color: "#5E9F7C"

    // Main content area for the marketplace
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


                Rectangle {
                    radius: 12.5
                    width: parent.width *0.98
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
                Rectangle {
                    radius: 12.5
                    y: parent.height * 0.2
                    height: parent.height * 0.8
                    width: parent.width
                    ScrollView {
                        id: scrollViewMarket
                        anchors.fill: parent
                        width:parent.width
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

        /*Button {
            y: parent.height * 0.25
            text: "Add to Fridge"
            onClicked: {
                addtofridge.open()
            }
        }*/

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

