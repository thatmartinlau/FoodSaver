import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts

/*Popup {
        id: selling
        anchors.centerIn: parent
        width: 200
        height: 220
        closePolicy: "CloseOnEscape"
        background: Rectangle {
                color:"#EEEEEE"
                radius: 12.5
            }
        property int itemIndex: -1
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
                    selling.close()
                }
            }
            CheckBox {
                id: negotiateCheckBox
                text: "Negotiate"
            }
            TextField {
                id: priceInput
                width: 190
                height: 25
                padding: 5
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                        color: "#5E9F7C"
                        radius: 12.5
                    }
                placeholderText: "Enter Price"
                enabled: !negotiateCheckBox.checked
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
                        var indexToSell = selling.itemIndex;
                        if (indexToSell !== -1) {
                            var priceToSet = negotiateCheckBox.checked ? -1 : priceInput.text;
                            itemModel.setProperty(indexToSell, "status", 1);
                            itemModel.setProperty(indexToSell, "price", priceToSet);
                            selling.close();
                        }
                    }
                }
            }
        }
    }

Popup {
    id: selling
    anchors.centerIn: parent
    width: 300
    height: 320
    closePolicy: "CloseOnEscape"
    background: Rectangle {
        color:"#EEEEEE"
        radius: 12.5
    }
    property int itemIndex: -1

    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            anchors.right: parent.right
            text: "X"
            width: 50
            background: null
            onClicked: {
                selling.close()
            }
        }

        CheckBox {
            id: negotiateCheckBox
            text: "Negotiate"
        }

        TextField {
            id: priceInput
            width: 290
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Price"
            enabled: !negotiateCheckBox.checked
        }

        TextField {
            id: quantityInput
            width: 290
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Quantity"
        }

        TextField {
            id: itemInput
            width: 290
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Item"
        }

        TextField {
            id: categoryInput
            width: 290
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Category"
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                text: "Validate"
                width: 150
                background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
                onClicked: {
                    var indexToSell = selling.itemIndex;
                    if (indexToSell !== -1) {
                        var priceToSet = negotiateCheckBox.checked ? -1 : priceInput.text;
                        var quantityToSet = quantityInput.text;
                        var itemToSet = itemInput.text;
                        var categoryToSet = categoryInput.text;

                        itemModel.setProperty(indexToSell, "status", 1);
                        itemModel.setProperty(indexToSell, "price", priceToSet);
                        itemModel.setProperty(indexToSell, "quantity", quantityToSet);
                        itemModel.setProperty(indexToSell, "item", itemToSet);
                        itemModel.setProperty(indexToSell, "categorie", categoryToSet);


                        selling.close();
                    }
                }
            }
        }
    }
}*/
Popup {
    id: selling
    anchors.centerIn: parent
    width: 350
    height: 370
    closePolicy: "CloseOnEscape"
    background: Rectangle {
        color:"#EEEEEE"
        radius: 12.5
    }
    property int itemIndex: -1

    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            anchors.right: parent.right
            text: "╳"
            width: 50
            background: null
            onClicked: {
                selling.close()
            }
        }
        /*Label {
                        text: "Current Price: " + itemModel.price
                    }
        Label {
                        text: "test: " + itemModel.categorie
                    }

        CheckBox {
            id: negotiateCheckBox
            text: "Negotiate"
        }*/
        Label {
            text: "Enter the quantity you want to sell. Must be less than " + itemModel.get(itemIndex).quantity
        }
        TextField {
            id: quantity2sellInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Quantity"
            text: itemModel.get(itemIndex).quantity
        }
        ComboBox {
                id: priceType
                width: 200
                model: ["Free", "Negociate", "Fixed Price"]

                onCurrentIndexChanged: {
                    console.log("Selected option:", model[currentIndex]);
                }
            }
        TextField {
            enabled:priceType.currentIndex === 2
            id: priceInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Price"
        }
        Label {
            id:errorQuantity
            visible: false
            text: "Quantity Invalid"
            color: "red"
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                text: "Validate"
                width: 150
                background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
                onClicked: {
                    if (quantity2sellInput.text <= itemModel.get(itemIndex).quantity) {

                        errorQuantity.visible = false
                        itemModel.setProperty(itemIndex, "pricestatus", priceType.currentIndex);
                        itemModel.setProperty(itemIndex, "status", 1);
                        itemModel.setProperty(itemIndex, "quantity2sell", quantity2sellInput.text);
                        itemModel.setProperty(itemIndex, "price", priceInput.text);
                        quantity2sellInput.text=""
                        priceInput.text=""
                        /*itemModel.get(itemIndex).status=1
                        itemModel.get(itemIndex).quanity2sell=quantity2sellInput.text
                        itemModel.get(itemIndex).price=priceInput.text
                        itemModel.get(itemIndex).pricestatus=priceType.currentIndex*/
                        scrollViewOffer.contentHeight += 152.5
                        selling.close();
                    }
                    else {
                        errorQuantity.visible = true
                        quantity2sellInput.text=""
                    }
                }
            }
        }
    }
}


