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
            id: recipename
            placeholderText: "Type in your recipe name please..."
            width: parent.width
        }

        TextField {
            id: diet
            placeholderText: "Type in any diet restriction (eq vegetarian, gluten free,...)..."
            width: parent.width
        }

        TextField {
            id: totalduration
            validator: IntValidator {bottom: 1; top: 999}
            placeholderText: "Type in the expected duration of the recipe"
            width: 640

        }


        Button {
            text: "Submit"
            onClicked: {
                var userText = recipename.text + "%" + diet.text //the % sign is used to slpit the string into different information - this is a temporary solution
                var time = totalduration.text

                if (userText.trim() !== "") {
                    console.log("User has typed: " + userText)

                    var res = MainController.submitText(recipename.text + diet.text) //C++ functions in the maincontroller.cpp file
                    var timer = MainController.changeTime(time)

                    diet.text = ""  //Reset all the text fields after submission
                    recipename.text = ""
                    totalduration.text = ""

                    outputText.text = "Recipe and diet restiction:" + res + "Time:" + timer + 20// Update the label
                    outputText.visible = true  // Make the label visible
                }


            }
        }

        Text {
            id: outputText
            visible: false
            text: ""
        }


        TextField {
            id: userInput2
            placeholderText: "Type something..."
            width: parent.width
        }

        Button {
            text: "Submit"
            onClicked: {
                var userText = userInput2.text
                if (userText.trim() !== "") {
                    console.log("User has typed: " + userText)
                    MainController.submitText(userInput2.text)
                    userInput2.text = ""
                    outputText2.text = "Hello, " + userText + "!"  // Update the label
                    outputText2.visible = true  // Make the label visible
                }


            }
        }

        Text {
            id: outputText2
            visible: false
            text: ""
        }
    }
}
