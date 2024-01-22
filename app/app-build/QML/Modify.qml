import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts

Popup {
    id: modify
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
            text: "X"
            width: 50
            background: null
            onClicked: {
                modify.close()
            }
        }
        /*Label {
                        text: "Current Price: " + itemModel.price
                    }
        Label {
                        text: "test: " + itemModel.item
                    }
        Label {
            text: "Item: " + (itemIndex !== -1 ? itemModel.get(itemIndex).item : "")
        }

        Label {
            text: "Category: " + (itemIndex !== -1 ? itemModel.get(itemIndex).categorie : "N/A")
        }*/

        TextField {
            id: itemInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Item"
            text: (itemIndex !== -1 ? itemModel.get(itemIndex).item : "")
        }

        TextField {
            id: categoryInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Category"
            text: (itemIndex !== -1 ? itemModel.get(itemIndex).categorie : "")
        }
        TextField {
            id: expiryDateInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Expiry Date"
            text: (itemIndex !== -1 ? itemModel.get(itemIndex).date : "")
        }
        TextField {
            id: quantityInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Quantity"
            text: (itemIndex !== -1 ? itemModel.get(itemIndex).quantity : "")
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
                    var indexToSell = modify.itemIndex;
                    if (indexToSell !== -1) {

                        var quantityToSet = quantityInput.text;
                        var itemToSet = itemInput.text;
                        var categoryToSet = categoryInput.text;
                        var expiryDateToSet = expiryDateInput.text;

                        itemModel.setProperty(indexToSell, "quantity", quantityToSet);
                        itemModel.setProperty(indexToSell, "item", itemToSet);
                        itemModel.setProperty(indexToSell, "category", categoryToSet);
                        itemModel.setProperty(indexToSell, "date", expiryDateToSet);

                        modify.close();
                    }
                }
            }
        }
    }
}
