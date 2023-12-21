import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    spacing: 10

    Button {
        text: "Back to Home"
        onClicked: stackView.pop()
    }
    Button {
        text: "Open Popup"
        onClicked: backend.openPopupWindow("qrc:/ChangePrice.qml")
    }

}
