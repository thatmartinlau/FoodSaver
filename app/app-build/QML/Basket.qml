import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: myBasket
    anchors.centerIn: parent
    width: 700
    height: 600
    closePolicy: Popup.CloseOnPressOutside
    background: Rectangle {
            color:"#EEEEEE"
            radius: 12.5
        }

    ColumnLayout {
        anchors.fill: parent

        //title
        Label {
            Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            text: "My Basket"
            font.bold: true
            color: "#1C6F30"
            font.pixelSize: 30
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
                    model: 10 // test only! should be the amount of items saved

                    Rectangle{
                        width: myBasket.width - 25
                        height: 125
                        color: "#D7ECDE"
                        radius: 5

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

