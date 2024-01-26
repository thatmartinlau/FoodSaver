import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: myBasket
    anchors.centerIn: parent
    width: 700
    height: 600
    closePolicy: "CloseOnEscape"
    background: Rectangle {
            color:"#EEEEEE"
            radius: 12.5
        }
}
