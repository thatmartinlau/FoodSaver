import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts

Popup {
    id: modify
    anchors.centerIn: parent
    width: 350
    height: 370
    closePolicy: Popup.CloseOnEscape
    background: Rectangle {
        color:"#EEEEEE"
        radius: 12.5
    }
    property int itemIndex3

    Column {
        anchors.centerIn: parent
        spacing: 10


        Button {
            anchors.right: parent.right
            text: "╳"
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
            text: (itemIndex3 !== -1 ? itemModel.get(itemIndex3).item : "")
        }

        /*TextField {
            id: categorieInput
            width: 340
            height: 25
            padding: 5
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#5E9F7C"
                radius: 12.5
            }
            placeholderText: "Enter Category"
            text: (itemIndex3 !== -1 ? itemModel.get(itemIndex3).categorie : "")
        }*/
        ComboBox {
            id: categoryInput
            width: 200
            model: ["Unspecified", "Fruit", "Vegetable", "Drink", "Dairy", "Canned",
                "Meat", "Fish", "Sweet", "Nut", "Other"]

            onCurrentIndexChanged: {
                console.log("Selected option:", categoryInput.currentText);
                console.log(itemModel)
            }
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
            text: (itemIndex3 !== -1 ? itemModel.get(itemIndex3).date : "")
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
            text: (itemIndex3 !== -1 ? itemModel.get(itemIndex3).quantity : "")
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
                    var indexToSell = modify.itemIndex3;
                    if (indexToSell !== -1) {

                        var quantityToSet = quantityInput.text;
                        var itemToSet = itemInput.text;
                        var categoryToSet = categoryInput.currentText;
                        var expiryDateToSet = expiryDateInput.text;
                        fridgemanager.pop_elt(indexToSell)
                        quantityInput.text = "";
                        itemInput.text= "";
                        expiryDateInput.text= "";


                        itemModel.setProperty(indexToSell, "quantity", quantityToSet);
                        itemModel.setProperty(indexToSell, "item", itemToSet);
                        itemModel.setProperty(indexToSell, "categorie", categoryToSet);
                        itemModel.setProperty(indexToSell, "date", expiryDateToSet);
                        fridgemanager.add_elt(itemToSet, expiryDateToSet, quantityToSet, categoryToSet);
                        modify.close();
                    }
                }
            }
        }
    }
}
