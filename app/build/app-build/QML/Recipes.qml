import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Column {

        anchors.left: parent.left
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: parent.width * 0.05

        Button { text: "Fridge";  onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
        Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
        Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
        Button { text: "Recipes"; enabled: false; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

    }
    // BOTTOM BUTTONS

    Column {
        anchors.right: parent.right
        anchors.bottom: parent.verticalCenter
        anchors.rightMargin: parent.width * 0.5

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

        Button { text: "yellow";
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
            visible: true
            text: "test"
        }

    }


    Settings {
        id: settings
    }

    Button {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        id: button
        text: "Settings"
        onClicked: {
        settings.open()
        }
    }

    Button {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.bottomMargin: 10

        text: "Logout"
        onClicked: stackView.pop() // need to add a function which logs the user out of the server, then deletes all active data from the instance.
    }

}
