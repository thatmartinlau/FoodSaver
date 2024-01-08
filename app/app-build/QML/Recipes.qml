import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//colors: green #5E9F7C lightgreen #D7ECDE

Row {
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#EEEEEE"
        Column {

            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.05

            Button { text: "Fridge";  onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
            Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
            Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
            Button { text: "Recipes"; enabled: false; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

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
    }
    Rectangle {
        x: parent.width * 0.20
        width: parent.width * 0.6
        height: parent.height
        color: "#EEEEEE"

        Rectangle {
            y: parent.height * 0.05
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            border.color: "#1C6F30"
            color: "white"
            property string newItemText: ""

            Column {
                height: parent.height
                width: parent.width

                Rectangle {
                    radius: 12.5
                    width: parent.width
                    height: parent.height * 0.2
                    color: "transparent"
                    Label {
                        text: "My Recipies, you can see existing recipues in the bachelor Cookbook in the center, and you can add your own \n recipies by clicking add recipe on the side -- ask Cyriac if questions "
                        anchors.top: parent.top
                    }

                    GridLayout{
                        id: majorGrid
                        columns: 5
                        width: parent.width
                        columnSpacing: 2
                        rowSpacing: 10
                        height: parent.height*0.2
                        y : parent.height*0.7

                        //ON LINE 1 OF GRID
                        TextField {
                            Layout.preferredWidth: 400
                            id: searchbar
                            width: parent.width
                            placeholderText: "Search for a specific recipe"
                            placeholderTextColor: "#A0A0A0"
                            color: "#544E3D"
                            background: Rectangle {
                                color: "#D9E8FF" // Light blue for text field
                                radius: 8
                            }
                            onTextChanged: {
                            //onEditingFinished: {
                                //var counter = itemModel.count
                                for (var i = 0; i < itemModel.count; i++) {
                                    MainController.submit(itemModel.get(i).name)
                                }
                                var to_display = MainController.search_res(searchbar.text)

                                itemModel.clear()
                                //itemModel.append({"name": to_display})
                                //itemModel.append({"name": to_display[1]})

                                for (var j = 0; j< to_display.length; j++){
                                    itemModel.append({"name" : to_display[j]})
                                }

                                //searchbar.text = ""

                            }
                        }

                        Text {text: "Sort by:"; color: "#28A745"; Layout.preferredWidth: 75}

                        ComboBox {
                                id: priority
                                width: 200
                                model: ["None","Cook time", "Vegetarian", "Gluten-free"]

                                onCurrentIndexChanged: {
                                    console.log("Selected option:", model[currentIndex]);
                                }
                            }

                        Button {
                            text: "Sort"
                            width: 50
                            palette.buttonText: "white"
                            //anchors.horizontalCenter: parent.horizontalCenter
                            background: Rectangle {
                                        color: "#1C6F30"
                                        radius:12.5
                            }
                            onClicked: {
                                //
                            }
                        }


                        Button {
                            text: "Reset"
                            width: 50
                            palette.buttonText: "white"
                            //anchors.horizontalCenter: parent.horizontalCenter
                            background: Rectangle {
                                        color: "#1C6F30"
                                        radius:12.5
                            }
                            onClicked: {
                                for (var i = 0; i < itemModel.count; i++) {
                                    MainController.submit(itemModel.get(i).name)
                                }
                                //var counter = itemModel.count
                                itemModel.clear()
                                var len = MainController.getTotalLength()
                                //itemModel.append({"name": "Try" + len})
                                //itemModel.append({"name": MainController.gett(0)})
                                for (var j = 0; j < len; j++) {
                                    itemModel.append({"name": MainController.gett(j)})
                                }
                                scrollView.contentHeight = len*82.5;
                                //itemModel = save
                            }
                        }
                    }


                }
                Rectangle {
                    radius: 12.5
                    y: parent.height * 0.2
                    height: parent.height * 0.8
                    width: parent.width
                    color: "transparent"
                    ScrollView {
                        id: scrollView
                        anchors.fill: parent
                        width:parent.width
                        Column {
                            spacing: 2.5
                            width:parent.width
                            Repeater {
                                model: itemModel
                                //property var modelData: model // Assuming each model item is an object
                                Rectangle {
                                    radius:12.5
                                    width: parent.width
                                    height: 80
                                    border.color: "#28A745"
                                    color: "#EEEEEE"
                                    Rectangle {
                                        radius:12.5
                                        width: parent.height
                                        height: parent.height
                                        color:"lightblue"
                                        Label {text:"photo"}
                                    }
                                    GridLayout{
                                        //anchors.horizontalCenter: parent.horizontalCenter
                                        id: repeated
                                        columns: 3
                                        width: parent.width
                                        columnSpacing: 2
                                        rowSpacing: 10
                                        height: parent.height*0.2
                                        x: parent.height
                                        //y : parent.height*0.7

                                    //ON LINE 1 OF GRID
                                        Text {text: model.name; color: "#28A745"; Layout.preferredWidth: 75}

                                        Button {
                                            text: "Try it out"
                                            width: 100
                                            palette.buttonText: "white"
                                            //anchors.horizontalCenter: parent.horizontalCenter
                                            background: Rectangle {
                                                        color: "#1C6F30"
                                                        radius:12.5
                                            }
                                            onClicked: {
                                                openRecipe.open()
                                            }
                                        }
                                        Button { // Ellie :)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                            text: "LIKE"
                                            width: 100
                                            palette.buttonText: "white"
                                            //anchors.horizontalCenter: parent.horizontalCenter
                                            background: Rectangle {
                                                        color: "#1C6F30"
                                                        radius:12.5
                                            }
                                            onClicked: {
                                                //myPopup.open()
                                            }
                                        }
                                    //ON LINE 2
                                        Text {text: model.dietRestriction; color: "#28A745"; Layout.preferredWidth: 75}

                                        Button {
                                            text: "Give a rating"
                                            width: 100
                                            palette.buttonText: "white"
                                            //anchors.horizontalCenter: parent.horizontalCenter
                                            background: Rectangle {
                                                        color: "#1C6F30"
                                                        radius:12.5
                                            }
                                            onClicked: {
                                                myPopup.open()
                                            }
                                        }

                                        Button {
                                            text: "BLANK"
                                            width: 100
                                            palette.buttonText: "white"
                                            //anchors.horizontalCenter: parent.horizontalCenter
                                            background: Rectangle {
                                                        color: "#1C6F30"
                                                        radius:12.5
                                            }
                                            onClicked: {
                                                //myPopup.open()
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
        ListModel {
                id: itemModel
            }
    }


    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#EEEEEE"
        anchors.right: parent.right

        Button {
            y: parent.height * 0.05
            id: basket
            text: "My Personal Cookbook"
            palette.buttonText: "white"
            //anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                        color: "#1C6F30"
                        radius:12.5
            }
            onClicked: {
                //cookBook.open()
                //for(var i = 0; i<10;i++){
                //    itemModel.append(MainController.getJsonRTitle(i))
                //}
                var temp_title = MainController.getJsonRTitle(0)
                itemModel.append({"name" : "Vegetarian Lasagna"})
                itemModel.append({"name" : "Eggs Benedict"})
                itemModel.append({"name" : "Noodle Soup"})
                itemModel.append({"name" : temp_title})
                scrollView.contentHeight = scrollView.contentHeight + 3*82.5;
            }
        }
        Button {
            y: parent.height * 0.25
            id: addtofridge
            text: "Add to Cookbook"
            palette.buttonText: "white"
            //anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                        color: "#1C6F30"
                        radius:12.5
            }
            onClicked: {
                addRecipe.open()
            }
        }
        Button {
            y: parent.height * 0.75
            x: parent.width * 0.5 - 50
            id: profil
            height: 100
            width: 100
            text: "Profil"
            onClicked: {
                //
            }
            background: Rectangle {
                        color: "#D7ECDE"
                        radius:12.5
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

    Popup {
        id: myPopup
        anchors.centerIn: parent
        width: 500
        height: 80
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

        GridLayout{
            id: rating
            columns: 3
            width: parent.width
            columnSpacing: 2
            rowSpacing: 10
            height: parent.height
            //x: parent.height
            //y : parent.height*0.7

        //ON LINE 1 OF GRID
            Text {text: "Enter your rating from 0 to 5:"; color: "#28A745"; Layout.preferredWidth: 250}

            TextField {
                Layout.preferredWidth: 75
                id: recipeName
                width: parent.width
                validator: DoubleValidator {bottom: 0; top: 5.0}
                placeholderText: "rating"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
                }
                onEditingFinished: {
                    myPopup.close()
                    recipeName.text = ""
                }
            }

            Button {
                text: "submit"
                width: 75
                palette.buttonText: "white"
                //anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                            color: "#1C6F30"
                            radius:12.5
                }
                onClicked: {
                    myPopup.close()
                    recipeName.text = ""
                }
            }
        }
    }

    CookBook{
        id: cookBook
    }

    AddRecipePopup{
        id: addRecipe
    }

    OpenRecipePopup{
        id: openRecipe
    }
}
