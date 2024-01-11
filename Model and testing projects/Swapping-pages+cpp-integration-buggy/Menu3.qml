import QtQuick 2.12
import QtQuick.Controls 2.12
Row {
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        Column{
            y: parent.height * 0.2
            Button {
                width: parent.width
                text: "Market"
                onClicked: stackView.pop()
            }
            Button {
                width: parent.width
                text: "My Fridge"
            }
            Button {
                //width: parent.width
                text: "Favorites"
                onClicked: {stackView.pop();stackView.push("Menu2.qml")}
            }
            Button {
                width: parent.width
                text: "Recipes"
                onClicked: stackView.pop()
            }
        }
        Button {
                anchors.bottom: parent.bottom
                text: "Settings"
                onClicked: stackView.pop()
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
                        text: "My Fridge"
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
                                    height: 80
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
                                                text: model.item // Access the "item" property of the model data
                                            }
                                            Label {
                                                text: model.categorie // Access the "categorie" property of the model data
                                            }
                                        }
                                        Column {
                                            width: parent.width * 0.4 // Set the width of the column as half of the parent width
                                            anchors.right: parent.right
                                            Button {
                                                text: "Put to Sell"
                                                // onClicked: handlePutToSell() // Define the function to handle the button click
                                                // Other properties of the button
                                            }

                                            Button {
                                                text: "Remove from Fridge"
                                                // onClicked: handleRemoveFromFridge() // Define the function to handle the button click
                                                // Other properties of the button
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
            }
    }


    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "blue"
        anchors.right: parent.right

        Button {
            y: parent.height * 0.05
            id: basket
            text: "My Basket"
        }
        Button {
            y: parent.height * 0.25
            id: addtofridge
            text: "Add to Fridge"
            onClicked: {
                myPopup.open()
            }
        }
        Button {
            y: parent.height * 0.75
            id: profil
            height: 100
            width: 100
            onClicked: {
                myPopup.open()
            }
            background: Rectangle {
                        color: "#5E9F7C"
                        radius:12.5
                    }


        }
    }
Popup {
        id: myPopup
        anchors.centerIn: parent
        width: 200
        height: 220
        closePolicy: "CloseOnEscape"
        background: Rectangle {
                color:"#EEEEEE"
                radius: 12.5
            }
        Column {
            anchors.centerIn: parent
            spacing: 10
            Button {
                anchors.right: parent.right
                //anchors.top: parent.top
                text: "X"
                width: 50
                background: null
                onClicked: {
                    myPopup.close()
                }
            }
            TextField {
                padding: 5
                id: iteminput
                width: 190
                height: 25
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                        color: "#5E9F7C"
                        radius: 12.5
                    }
                placeholderText: "Item"
            }
            TextField {
                id: categorieinput
                width: 190
                height: 25
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                        color: "#5E9F7C"
                        radius: 12.5
                    }
                placeholderText: "Categorie"
            }
            TextField {
                padding: 5
                id: dateinput
                width: 190
                height: 25
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                        color: "#5E9F7C"
                        radius: 12.5
                    }
                placeholderText: "Expiration Date"
            }
            TextField {
                padding: 5
                id: quantityinput
                width: 190
                height: 25
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                        color: "#5E9F7C"
                        radius: 12.5
                    }
                placeholderText: "Quantity"
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Button {
                    text: "Validate"
                    width: 100
                    //anchors.horizontalCenter: parent.horizontalCenter
                    background: Rectangle {
                                color: "#5E9F7C"
                                radius:12.5
                    }
                    onClicked: {
                        if (iteminput.text.trim() !== "" &categorieinput.text.trim() !== "") { // Check if the text is not empty or only whitespace
                            //itemModel.append({ "item": iteminput.text, "categorie": categorieinput.text, "date": dateinput.text, "quantity": quantityinput.text});
                            itemModel.append({ "item": iteminput.text, "categorie": categorieinput.text, "date": dateinput.text, "quantity": quantityinput.text });
                            iteminput.text = "";
                            categorieinput.text = "";
                            scrollView.contentHeight = scrollView.contentHeight + 82.5;
                            myPopup.close()
                        }
                    }
                }
            }
        }
    }
}

