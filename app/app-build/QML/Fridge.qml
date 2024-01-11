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

            Button { text: "My Fridge"; enabled: false; onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
            Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
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
            property string newItemText: ""

            Column {
                height: parent.height
                width: parent.width

                Rectangle {
                    radius: 12.5
                    width: parent.width
                    height: parent.height * 0.2

                    Label {
                        text: "My Fridge __ Hello, on this page \n The add product works, you can try it, (you need to put at least a name and a category)\nIf there are enough products the scroll bar will appear\nIf questions, ask Antoine"
                        anchors.top: parent.top
                    }

                    Row {
                        anchors.bottom: parent.bottom
                        TextField {
                            id: itemTextField
                            placeholderText: "Search for a specific item"
                            //onTextChanged: newItemText = itemTextField.text // Update the newItemText on text change
                        }

                        Button {
                            text: "Category"
                            onClicked: {
                                // Handle Category button click
                            }
                        }

                        Button {
                            text: "Time left"
                            onClicked: {
                                // Handle Time left button click
                            }
                        }

                        Button {
                            text: "Price"
                            onClicked: {
                                // Handle Price button click
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
                        id: scrollView
                        anchors.fill: parent
                        width:parent.width
                        Column {
                            spacing: 2.5
                            width:parent.width
                            Repeater {
                                model: itemModel
                                //property var modelData: model // Assuming each model item is an object
                                Rectangle {
                                    radius:12.5
                                    width: parent.width
                                    height: 200
                                    color: "red"
                                    Row {
                                        width:parent.width
                                        height: parent.height
                                        Rectangle {
                                            radius:12.5
                                            width:parent.height
                                            height: parent.height
                                            color:"lightblue"
                                            Label {text:"photo"}
                                        }
                                        Column {
                                            x:parent.height
                                            spacing:1
                                            Label {
                                                text: "Item: " + model.item // Access the "item" property of the model data
                                            }
                                            Label {
                                                text: "Categorie: " + model.categorie // Access the "categorie" property of the model data
                                            }
                                            /*Label {
                                                text: "Index: " + model.index
                                            }*/
                                            Label {
                                                text: (model.status === 0) ? "Not for sale" : (model.price === -1) ? "Negotiate" : "Price: " + model.price
                                            }
                                            Label {
                                                text: "Expiration date: " + model.date
                                            }

                                            Label {
                                                text: "Quantity: " + model.quantity
                                            }
                                        }
                                        Column {
                                            width: parent.width * 0.4 // Set the width of the column as half of the parent width
                                            anchors.right: parent.right
                                            Button {
                                                text: "Price Settings"
                                                onClicked: {
                                                    var indexToSell = itemModel.getIndexByPropertyValue("index", model.index);
                                                    if (indexToSell !== -1) {
                                                        selling.itemIndex = indexToSell;
                                                        selling.open();
                                                    } else {
                                                        console.warn("No item available for sale.");
                                                    }
                                                }
                                            }

                                            Button {
                                                text: "Remove from Fridge"
                                                onClicked: {
                                                    itemModel.remove(itemModel.getIndexByPropertyValue("index", model.index));
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
        ListModel {
                id: itemModel
                function getIndexByPropertyValue(propertyName, propertyValue) {
                    scrollView.contentHeight -= 202.5;
                    for (var i = 0; i < count; i++) {
                        if (get(i)[propertyName] === propertyValue) {
                            return i;
                        }
                    }
                    return -1; // Return -1 if the item is not found
                }
        }
    }


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
            //id: addtofridge
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
                        radius:12.5
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
Profile {
    id: profile
}
Settings {
    id:settings
}
AddToFridge {
    id:addtofridge
}
Selling {
    id:selling
}
}



//Under is old code from Martin
/*Item {

    // SETTINGS POPUP
    // currently a template, created by Antoine on the other branch (ty)

    Column {

        anchors.left: parent.left
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: parent.width * 0.05

        Button { text: "Fridge"; enabled: false; onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
        Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
        Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
        Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

    }

    // BOTTOM BUTTONS

    Profile {
        id: profile
    }

    Settings {
        id: settings
    }

    Column {


        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        Button {
            id: profilebutton
            text: "Profile"
            onClicked: {
                profile.open()
            }
        }

        Button {
            id: settingsbutton
            text: "Settings"
            onClicked: {
            settings.open()
            }
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


}*/
