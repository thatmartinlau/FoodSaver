import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: personalCookBook
    anchors.centerIn: parent
    width: 700
    height: 600
    closePolicy: "CloseOnEscape"
    background: Rectangle {
        color: "#EEEEEE"
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
            personalCookBook.close()
        }
    }

    Repeater {
        model: itemModel
        Rectangle {
            radius: 12.5
            width: parent.width * 0.98
            height: 80
            border.color: "#28A745"
            color: "#EEEEEE"

            Rectangle {
                radius: 12.5
                width: parent.height * 0.9
                height: parent.height * 0.9
                x: 5
                anchors.verticalCenter: parent.verticalCenter
                color: "lightblue"

                Label {
                    text: "photo"
                }
            }

            GridLayout {
                id: repeated
                columns: 3
                width: parent.width
                columnSpacing: 2
                rowSpacing: 10
                height: parent.height * 0.2
                x: parent.height

                // ON LINE 1 OF GRID
                Text {
                    text: model.name
                    color: "#28A745"
                    Layout.preferredWidth: 75
                }

                Button {
                    text: "Try it out"
                    width: 100
                    onClicked: {
                        var buildup = RecipeController.sendTitleForVis(model.name)
                        open_title = buildup[0]
                        open_diet = buildup[1]
                        open_time = buildup[2]
                        open_ingredients = RecipeController.sendIngredientsForVis(model.name)

                        readIngredients.clear()
                        for (var i = 0; i < open_ingredients.length; i++) {
                            readIngredients.append({"name": open_ingredients[i]})
                            scroller_vis.contentHeight = scroller_vis.contentHeight + 32.5;
                        }

                        open_instructions = RecipeController.sendInstructionsForVis(model.name)

                        readInstructions.clear()
                        for (var i = 0; i < open_instructions.length; i++) {
                            readInstructions.append({"name": open_instructions[i]})
                            scroller_vis2.contentHeight = scroller_vis.contentHeight + 32.5;
                        }

                        viewRecipePopup.open()
                    }
                }
                Button { // Ellie :)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    text: "LIKE"
                    width: 100
                    height: 100
                    onClicked: {
                        if (RecipeController.getLikedRecipes().indexOf(model.name) === -1) {
                            RecipeController.likeRecipe(model.name);
                        } else {
                            RecipeController.unlikeRecipe(model.name);
                        }
                        personalCookBook.open()
                    }
                }

                // ON LINE 2
                Text {
                    text: model.dietRestriction
                    color: "#28A745"
                    Layout.preferredWidth: 75
                }

                Button {
                    text: "Give a rating"
                    width: 100
                    onClicked: {
                        RecipeController.submitTitleForRating(model.name)
                        myPopup.open()
                    }
                }

                Text {
                    text: model.grade
                    color: "#28A745"
                    Layout.preferredWidth: 75
                }
            }
        }
    }
}


/*import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Popup {
    id: personalCookBook
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
            personalCookBook.close()
        }
    }


                Repeater {
            model: itemModel
            Rectangle {
                radius:12.5
                width: parent.width*0.98
                height: 80
                border.color: "#28A745"
                color: "#EEEEEE"

                Rectangle {
                    radius:12.5
                    width: parent.height*0.9
                    height: parent.height*0.9
                    x : 5
                    anchors.verticalCenter: parent.verticalCenter
                    color:"lightblue"

                    Label {text:"photo"}
                }
                GridLayout{
                    id: repeated
                    columns: 3
                    width: parent.width
                    columnSpacing: 2
                    rowSpacing: 10
                    height: parent.height*0.2
                    x: parent.height

                //ON LINE 1 OF GRID
                    Text {text: model.name; color: "#28A745"; Layout.preferredWidth: 75}

                    Button {
                        text: "Try it out"
                        width: 100
                        //anchors.horizontalCenter: parent.horizontalCenter

                        onClicked: {
                            //viewRecipePopup.grid1.
                            var buildup = RecipeController.sendTitleForVis(model.name)
                            open_title = buildup[0]
                            open_diet = buildup[1]
                            open_time = buildup[2]
                            //open_ingredients.clear()
                            open_ingredients = RecipeController.sendIngredientsForVis(model.name)

                            readIngredients.clear()
                            for(var i = 0; i<open_ingredients.length; i++){
                                readIngredients.append({"name" : open_ingredients[i]});
                                scroller_vis.contentHeight = scroller_vis.contentHeight + 32.5;
                            }

                            //open_instructions.clear()

                            open_instructions = RecipeController.sendInstructionsForVis(model.name)

                            readInstructions.clear()
                            for(var i = 0; i<open_instructions.length; i++){
                                readInstructions.append({"name" : open_instructions[i]});
                                scroller_vis2.contentHeight = scroller_vis.contentHeight + 32.5;
                            }


                            viewRecipePopup.open()
                        }
                    }
                    Button { // Ellie :)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        text: "LIKE"
                        width: 100
                        height: 100
                        //anchors.horizontalCenter: parent.horizontalCenter

                        onClicked: {
                            // Check if the recipe is already liked
                            if (RecipeController.getLikedRecipes().indexOf(model.name) === -1) {
                                // If not liked, call likeRecipe
                                RecipeController.likeRecipe(model.name);
                            } else {
                                // If liked, call unlikeRecipe
                                RecipeController.unlikeRecipe(model.name);
                            }
                            addFavoriteRecipe.open()
                        }
                    }


                //ON LINE 2
                    Text {text: model.dietRestriction; color: "#28A745"; Layout.preferredWidth: 75}

                    Button {
                        text: "Give a rating"
                        width: 100
                        //anchors.horizontalCenter: parent.horizontalCenter

                        onClicked: {
                            RecipeController.submitTitleForRating(model.name)
                            myPopup.open()
                        }
                    }

                    Text {text: model.grade ; color: "#28A745"; Layout.preferredWidth: 75}


                }

            }
        }

                OpenRecipePopup{
                    id: openRecipe
                }

    }*/






