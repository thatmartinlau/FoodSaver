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
        background: Rectangle {
                    color: "red"
                    radius: 50
        }
        onClicked: {
            myPopup.close()
        }
    }
    GridLayout{
        id: grid1
        columns: 2
        width: parent.width
        columnSpacing: 20
        rowSpacing: 10
        height: parent.height*0.1333333333

        //ON LINE 1 OF GRID
        Text {text: "Recipe Name"; color: "#28A745"; Layout.preferredWidth: 75}
        TextField {
            Layout.preferredWidth: 400
            id: recipeName
            width: parent.width
            placeholderText: "Name"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            background: Rectangle {
                color: "#D9E8FF" // Light blue for text field
                radius: 8
            }
        }



        //ON LINE 2 OF GRID
        Text {text: "Dietary Restriction"; color: "#28A745"; Layout.preferredWidth: 125}

        ComboBox {
                id: diet
                width: 200
                model: ["None","Vegetarian", "Gluten-free", "Other"]

                onCurrentIndexChanged: {
                    console.log("Selected option:", model[currentIndex]);
                }
            }
    }


    GridLayout{
        id: grid2
        columns: 3
        width: parent.width
        columnSpacing: 20
        rowSpacing: 10
        y: parent.height*0.155
        height: parent.height*0.033333


        //ON LINE 1 OF GRID
        Text {text: "Total time"; color: "#28A745"; Layout.preferredWidth: 65}

        TextField {
            Layout.preferredWidth: 100
            id: hours
            width: parent.width
            validator: IntValidator {bottom: 0; top: 999}
            placeholderText: "Hours"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            background: Rectangle {
                color: "#D9E8FF" // Light blue for text field
                radius: 8
            }
        }

        TextField {
            Layout.preferredWidth: 100
            anchors.left: hours.right
            id: minutes
            width: parent.width
            validator: IntValidator {bottom: 0; top: 999}
            placeholderText: "Minutes"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            background: Rectangle {
                color: "#D9E8FF" // Light blue for text field
                radius: 8
            }
        }


    }

    GridLayout{
        id: grid3
        columns: 4
        width: parent.width
        columnSpacing: 20
        rowSpacing: 10
        y: parent.height*0.23
        height: parent.height*0.033333


        //ON LINE 1 OF GRID
        Text {text: "Ingredients"; color: "#28A745"; Layout.preferredWidth: 135}

        TextField {
            Layout.preferredWidth: 400
            id: ingredient1
            width: parent.width
            placeholderText: "Ingredient 1"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            background: Rectangle {
                color: "#D9E8FF" // Light blue for text field
                radius: 8
            }
            onEditingFinished: {
                if(ingredient1.text.trim() != ""){
                    inputModel.append({"name":ingredient1.text});
                    ingredient1.text = "";
                    scroller.contentHeight = scroller.contentHeight + 32.5;
                    //}
                }
            }
        }

        Button {
            text: "+"
            width: 20
            //palette.buttonText: "white"
            //anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#28A745" // Green for positive actions
                radius: 8
            }
            onClicked: {
                if(ingredient1.text.trim() != ""){
                    inputModel.append({"name":ingredient1.text});
                    ingredient1.text = "";
                    scroller.contentHeight = scroller.contentHeight + 32.5;
                }
            }
        }

    }
    Rectangle{
        radius: 20
        y: parent.height * 0.30
        height: parent.height * 0.2
        width: parent.width
        color: "#EEEEEE"
        border.color:"#CCCCCC"
        ScrollView{
            id: scroller
            anchors.fill: parent
            width:parent.width
            Column{
                spacing: 2.5
                width:parent.width
                Repeater{
                    model: inputModel
                    Rectangle{
                        radius:10
                        width: parent.width
                        height: 30
                        color: "#EEEEEE"
                        Row{
                            width:parent.width
                            height: parent.height
                            TextField {
                                readOnly: true

                                padding: 5
                                id: ingr
                                Layout.preferredWidth: 400
                                width: parent.width
                                anchors.left: parent.left
                                height: 30
                                background: Rectangle {
                                        color: "#D9E8FF"
                                        radius: 20
                                    }
                                placeholderText: model.name
                            }
                        }
                    }
                }
            }
        }
    }

    ListModel{
        id: inputModel

    }

    GridLayout{
        id: grid4
        columns: 3
        width: parent.width
        columnSpacing: 20
        rowSpacing: 10
        y: parent.height*0.505

        //ON LINE 1 OF GRID
        Text {text: "Instructions"; color: "#28A745"; Layout.preferredWidth: 135}
        TextField {
            Layout.preferredWidth: 400
            id: instruction1
            width: parent.width
            placeholderText: "Instruction 1"
            placeholderTextColor: "#A0A0A0"
            color: "#544E3D"
            background: Rectangle {
                color: "#D9E8FF" // Light blue for text field
                radius: 8
            }
            onEditingFinished: {
                if(instruction1.text.trim() != ""){
                    instructionModel.append({"name":instruction1.text});
                    instruction1.text = "";
                    scroller2.contentHeight = scroller2.contentHeight + 32.5;
                }
            }
        }

        Button {
            text: "+"
            width: 20
            background: Rectangle {
                color: "#28A745" // Green for positive actions
                radius: 8
            }
            onClicked: {
                if(instruction1.text.trim() != ""){
                    instructionModel.append({"name":instruction1.text});
                    instruction1.text = "";
                    scroller2.contentHeight = scroller2.contentHeight + 32.5;
                }
            }
        }
    }

    Rectangle{
        //anchors.top: parent.top
        radius: 20
        y: parent.height * 0.6
        height: parent.height * 0.3
        width: parent.width
        color: "#EEEEEE"
        border.color:"#CCCCCC"
        ScrollView{
            id: scroller2
            anchors.fill: parent
            width:parent.width
            Column{
                spacing: 2.5
                width:parent.width
                Repeater{
                    model: instructionModel
                    Rectangle{
                        radius:10
                        width: parent.width
                        height: 30
                        color: "#EEEEEE"
                        Row{
                            width:parent.width
                            height: parent.height
                            TextField {
                                readOnly: true
                                padding: 5
                                id: instr
                                width: parent.width
                                height: 30
                                anchors.horizontalCenter: parent.horizontalCenter
                                background: Rectangle {
                                        color: "#D9E8FF"
                                        radius: 20
                                    }
                                placeholderText: model.name
                            }
                        }
                    }
                }
            }
        }
    }

    ListModel{
        id: instructionModel
    }

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        Button {
            text: "Publish"
            width: 500
            background: Rectangle {
                color: "#28A745" // Green for positive actions
                radius: 8
            }
            onClicked: {
                for (var i = 0; i < itemModel.count; i++) {
                    RecipeController.submit(itemModel.get(i).name)
                }

                if (recipeName.text.trim() !== "" && instructionModel.count != 0 &&  inputModel.count != 0 && RecipeController.checkTitle(recipeName.text.trim()) != false) { // Check if the text is not empty or only whitespace
                    for(var index = 0; index < inputModel.count; index++){
                        RecipeController.submitIngredients(inputModel.get(index).name)
                    }

                    for(var index = 0; index < instructionModel.count; index++){
                        RecipeController.submitInstructions(instructionModel.get(index).name)
                    }
                    if(hours.text.trim() == ""){hours.text = 0;}
                    if(minutes.text.trim() == ""){minutes.text = 0;}
                    var res = RecipeController.submitAll(recipeName.text, diet.currentValue, hours.text, minutes.text)//, ingredient1.text, instruction1.text)



                    var no_Value = RecipeController.get_ingr()

                    itemModel.append({"name": recipeName.text, "dietRestriction": diet.currentValue, "grade": "None" , "date": "Test1", "quantity": "Test1" });

                    recipeName.text = "";
                    ingredient1.text = "";
                    instruction1.text = "";
                    diet.currentIndex = 0 ;
                    hours.text = "";
                    minutes.text = "";
                    scrollView.contentHeight = scrollView.contentHeight + 82.5;
                    inputModel.clear()
                    instructionModel.clear()
                    myPopup.close()
                }
            }
        }
    }
}
