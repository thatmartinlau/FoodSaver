import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//colors: green #5E9F7C lightgreen #D7ECDE

Rectangle {
    property int currentIndex: 0
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        /*Column {

            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.05

            Button { text: "My Fridge"; enabled: false; onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
            Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
            //Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
            Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

        }*/

        // New side buttons
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
                    color: "transparent" // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            stackView.replace(Qt.resolvedUrl("Fridge.qml"))
                        }

                        Rectangle {
                            width: 24
                            height: 24
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: 13 // Additional property for the small rectangle
                            Label {
                                text: "🗄️"
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
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
                            parent.color = "transparent"; // Back to transparent when not hovered
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
                    color: "#EEEEEE" // Light grey color
                    radius: 12.5 // Add radius to the grey rectangle

                    Rectangle {
                        width: 24
                        height: 24
                        color: "#A3C995" // Updated color
                        radius: 2 // Updated radius
                        anchors.verticalCenter: parent.verticalCenter
                        x: 13 // Additional property for the small rectangle
                        Label {
                            text: "🛒"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Label {
                        text: "Market"
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
                        onClicked: {stackView.replace(Qt.resolvedUrl("Recipes.qml"))}

                        Rectangle {
                            width: 24
                            height: 24
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: 13 // Additional property for the small rectangle
                            Label {
                                text: "🍳"
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
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
        // End of side buttons



        // Settings button
        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.05



            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                id: button
                anchors.fill: parent
                onClicked: {
                settings.open()
                }

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "⚙️"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "Settings"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
        }
    }

    Rectangle {
        id: deux
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

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.05
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                id: basket
                anchors.fill: parent

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "🧾"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "My Basket"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
        }
        Rectangle {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom:parent.bottom
            anchors.bottomMargin: parent.height * 0.1 +50
            //y: parent.height * 0.75
            //x: parent.width * 0.5 - 50
            width: 75
            height: 95
            color: "white"
            radius:12.5


            MouseArea {
                anchors.fill: parent
                onClicked: {
                    profile.open()
                }

                Rectangle {
                    id:centerprofile
                    y:parent.parent.height * 0.15
                    //x:parent.parent.height * 0.15
                    width: parent.width * 0.7
                    height: parent.width * 0.7
                    color: "#A3C995"
                    radius: 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    //anchors.verticalCenter: parent.verticalCenter
                    //anchors.bottom: parent.bottom
                    //anchors.bottomMargin:  parent.parent.height * 1/2// Adjust the margin as needed

                    Label {
                        property var textList: ["💁‍♀️", "🧜🏽", "👩🏾‍💼", "👨🏻‍🦰","🧕🏻","👨🏻‍🎓"]
                        text: textList[Math.ceil(Math.random() * 5)]
                        font.pixelSize: parent.height *0.7
                        anchors.bottom: parent.bottom
                        //anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
                Label {
                    text: "Profile"
                    font.bold: true
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        bottom: parent.bottom
                        bottomMargin: 5 // Adjust the margin as needed
                    }
                }
                hoverEnabled: true

                onEntered: {
                    centerprofile.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    centerprofile.color = "#A3C995"; // Back to transparent when not hovered
                }

            }
        }

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.05
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                anchors.fill: parent

                onClicked: {stackView.push(Qt.resolvedUrl("LoginPage.qml"))}

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "👋"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "Logout"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
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

