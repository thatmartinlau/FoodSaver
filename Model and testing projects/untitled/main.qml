import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Simple Qt Quick App"

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: userInput
            placeholderText: "Type something..."
            width: parent.width
        }

        Button {
            text: "Submit"
            onClicked: {
                var userText = userInput.text
                if (userText.trim() !== "") {
                    console.log("User has typed: " + userText)
                    MainController.submitText(userInput.text)
                    userInput.text = ""
                    outputText.text = "Hello, " + userText + "!"  // Update the label
                    outputText.visible = true  // Make the label visible
                }


            }
        }

        Text {
            id: outputText
            visible: false
            text: ""
        }
    }
}
