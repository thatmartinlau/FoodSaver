import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Window 2.2
import QtQuick.Effects

Popup {

        //Fridge {
            //ListModel {
            //    id :itemModel
            //}
            //ScrollView {
            //    id : scrollViewFridge
            //}

        //}
        //property ListModel itemModel
        //property var scrollViewFridge

        id: addtofridge
        anchors.centerIn: parent
        width: 210
        height: 220
        closePolicy: "CloseOnEscape"

        background: MultiEffect {
                source: rect
                anchors.fill: rect
                shadowBlur: 1.0
                shadowColor: 'white'
                shadowEnabled: true
            }

            Rectangle {
                id: rect
                property int rectHeight: 210
                property int rectWidth: 200
                property int rectRadius: 12
                property int shadowSize: 10
                height: rectHeight
                width: rectWidth
                radius: rectRadius
                color: '#EEEEEE'
            }
        Column {
            anchors.centerIn: parent
            spacing: 10
            Button {
                anchors.right: parent.right
                //anchors.top: parent.top
                text: "╳"
                width: 50
                background: null
                onClicked: {
                    errordate.visible = false
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
            ComboBox {
                id: categorieMenu
                width: 200
                model: ["Unspecified", "Fruit", "Vegetable", "Drink", "Dairy", "Canned",
                    "Meat", "Fish", "Sweet", "Nut", "Other"]

                onCurrentIndexChanged: {
                    console.log("Selected option:", categorieMenu.currentText);
                }
            }
            Label {
                id:errordate
                visible: false
                color: "red"
                text: "Wrong format: dd/mm/yyyy"
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
                    onClicked:
                        /*if (dateinput.text.lenght !== 10) {
                            errordate.visible = true
                            dateinput.text = ""
                        }*/
                        if (iteminput.text.trim() !== "" && quantityinput.text.trim() !== "") { // Check if the text is not empty or only whitespace
                                   // Create a new Ingredient object
                                   var newIngredient = {
                                       "index": currentIndex,
                                       "item": iteminput.text,
                                       "categorie": categorieMenu.currentText,
                                       "date": dateinput.text,
                                       "quantity": quantityinput.text,
                                       "status": 0,
                                       "price" : 0,
                                       "quantity2sell": 0,
                                       "pricestatus": -1,
                                       "visibility" : 1
                                   };

                                   itemModel.append(newIngredient);
                                   // Append the new Ingredient object to the fridge
                                   fridgemanager.add_elt(iteminput.text, dateinput.text, quantityinput.text, categorieMenu.currentText);

                                   // Increment the index for the next item
                                   currentIndex++;

                                   // Clear input fields
                                   iteminput.text = "";
                                   //categorieinput.text = "";
                                   dateinput.text = "";
                                   quantityinput.text = "";
                                   scrollViewFridge.contentHeight += 152.5;
                                   errordate.visible = false;
                                   addtofridge.close();
                               }

                    /*{
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
                            fridge.add_elt(elem)

                            addtofridge.close()
                        }*/
                    }
                }
            }

        }

