import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    spacing: 10

    Button {
        text: "Back to Home"
        onClicked: stackView.pop()
    }
    Label {
        id: sumLabel
        text: "Sum: " + backend.sum
    }

    Button {
        text: "Generate Random Number"
        onClicked: backend.generateRandomNumber()
    }

    Connections {
        target: backend
        onSumChanged: sumLabel.text = "Sum: " + backend.sum
    }


}
