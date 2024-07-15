import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: myPopup
    anchors.centerIn: parent
    width: 700
    height: 600
    closePolicy: "CloseOnEscape"
    background: Rectangle {
            color:"#EEEEEE"
            radius: 12.5
        }
    Button {
        anchors.right: parent.right
        anchors.top: parent.top
        text: "X"
        width: 20
        height: 20
        //height: 50
        background: Rectangle {
                    color: "red"
                    radius: 50
        }
        onClicked: {
            myPopup.close()
        }
    }
}
