import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts

Popup {
        id: addtofridge
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
                    addtofridge.close()
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
                            //itemModel.append({ "item": iteminput.text, "categorie": categorieinput.text, "date": dateinput.text, "quantity": quantityinput.text });
                            itemModel.append({ "index": currentIndex,
                                                 "item": iteminput.text,
                                                 "categorie": categorieinput.text,
                                                 "date": dateinput.text,
                                                 "quantity": quantityinput.text,
                                                 "status": 0,
                                                 "price" : 0,
                                                 "quantity2sell": 0,
                                                 "pricestatus": -1 });

                            // Increment the index for the next item
                            currentIndex++;

                            iteminput.text = "";
                            categorieinput.text = "";
                            dateinput.text = "";
                            quantityinput.text = "";
                            scrollViewFridge.contentHeight = scrollViewFridge.contentHeight + 202.5;

                            //Ingredient elem(itemimput.text, dateinput.text, quantityinput.text, categorieinput.text)
                            //add_elt(elem)

                            addtofridge.close()
                        }
                    }
                }
            }
        }
    }
