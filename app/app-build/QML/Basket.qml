import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: myBasket
    anchors.centerIn: parent
    width: 600
    height: 700
    closePolicy: Popup.CloseOnPressOutside
    background: Rectangle {
            color:"white"
            radius: 12.5
        }

    ColumnLayout {
        anchors.fill: parent

        //title
        Label {
            Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            text: "My Basket 🧾"
            font.bold: true
            color: "#1C6F30"
            font.pixelSize: 35
            padding: 10
        }


        // Scrollable area for items
        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout{
                spacing: 10
                anchors.fill: parent

                // Model to add items
                Repeater{
                    model: ListModel{
                        ListElement{name: "Banana"; category: "Fruits"; timeLeft: "2 days"; price: "$2.00"; emoji: "🍌"; user: "User BX25"}
                        ListElement{name: "Apple"; category: "Fruits"; timeLeft: "1 day"; price: "$1.50"; emoji: "🍎"; user: "User BX25"}
                        ListElement{name: "Milk"; category: "Dairy"; timeLeft: "3 days"; price: "$3.00"; emoji: "🥛"; user: "User BX25"}
                        ListElement { name: "Eggs"; category: "Dairy"; timeLeft: "4 days"; price: "$2.50" ; emoji: "🥚"; user: "User BX25"}
                        ListElement { name: "Carrot"; category: "Vegetables"; timeLeft: "2 days"; price: "$1.00"; emoji: "🥕" ; user: "User BX25"}
                        ListElement { name: "Onions"; category: "Vegetables"; timeLeft: "3 days"; price: "$1.20" ; emoji: "🧅"; user: "User BX25"}
                        ListElement { name: "Spinach"; category: "Vegetables"; timeLeft: "1 day"; price: "$1.80"; emoji: "🥬" ; user: "User BX25"}
                        ListElement { name: "Avocado"; category: "Fruits"; timeLeft: "2 days"; price: "$2.50"; emoji: "🥑"; user: "User BX25" }
                    }


                    delegate: Rectangle{
                        width: myBasket.width - 25
                        height: 125
                        color: "#D7ECDE"
                        radius: 5

                        // display information for each item
                        Row{
                            spacing: 5
                            anchors.leftMargin: 10
                            anchors.topMargin: 10
                            anchors.fill: parent

                            Rectangle{
                                radius: 12.5
                                width: parent.height - 10
                                height: parent.height - 10
                                color: "#D7ECDE"

                                Label{
                                    text: model.emoji
                                    font.bold: true
                                    font.pixelSize: 70
                                    anchors.centerIn: parent
                                }
                            }

                        // info on each item
                        Column{
                            spacing: 5
                            anchors.leftMargin: 120
                            anchors.fill: parent
                            padding: 5

                            Text {
                                text: model.name
                                font.bold: true
                                font.pixelSize: 20
                            }

                            Text {
                                text: "Category: " + model.category
                                font.pixelSize: 16
                            }

                            Text {
                                text: "Time left: " + model.timeLeft
                                font.pixelSize: 16
                            }

                            Text {
                                text: "Price: " + model.price
                                font.pixelSize: 16
                            }

                        }

                        Row{
                            spacing: 5
                            anchors.leftMargin: parent.width/2
                            anchors.fill: parent
                            padding: 10

                            Text {
                                text: "Item sold by: \n" + model.user
                                font.bold: true
                                font.pixelSize: 16
                                anchors.verticalCenter: parent.verticalCenter
                            }

                            Button {
                                text: "Contact to Buy"
                                //anchors.centerIn: parent
                                anchors.verticalCenter: parent.verticalCenter

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        // URL contact link
                                        Qt.openUrlExternally("https://t.me")
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

    //Close button
    Button {
        anchors.right: parent.right
        anchors.top: parent.top
        text: "X"
        width: 20
        height: 20
        background: Rectangle {
                    radius: 50
        }
        onClicked: {
            myBasket.close()
        }
    }
}
