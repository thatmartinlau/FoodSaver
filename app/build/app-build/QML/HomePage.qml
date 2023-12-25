import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Item {

    ColumnLayout {

        anchors.left: parent.left
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: parent.width * 0.05

        Button { text: "Menu 1"; onClicked: stackView.push(Qt.resolvedUrl("Menu1.qml")) }
        Button { text: "Menu 2"; onClicked: stackView.push(Qt.resolvedUrl("Menu2.qml")) }
        Button { text: "Menu 3"; onClicked: stackView.push(Qt.resolvedUrl("Menu3.qml")) }
        Button { text: "Menu 4"; onClicked: stackView.push(Qt.resolvedUrl("menu4.qml")) }

        Button {
            id: button
            text: "Settings"
            onClicked: {
            myPopup.open()
            }
        }
        Popup {
                id: myPopup
                anchors.centerIn: parent
                width: 200
                height: 300
                closePolicy: "CloseOnEscape"
                background: Rectangle {
                        color:"#EEEEEE"
                        radius: 12.5
                        border.color: "black"
                        border.width: 1
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
                        //id: ItemInput
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
                        //id: CategorieInput
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
                        //id: DateInput
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
                        //id: QuantityInput
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
                                myPopup.close()
                            }
                        }
                    }
                }
            }
    }

    Button {
        text: "Logout"
    }


}