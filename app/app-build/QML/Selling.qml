import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts

Popup {
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
            /*Label {
                text: "Index: " + selling.itemIndex
            }
            Label {
                text: "Current Price: " + itemModel.price
            }*/
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
