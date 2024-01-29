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
            color:"#EEEEEE"
            radius: 12.5
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
                /////research on how to make the button a heart or a star:
                    /*width: 50
                    height: 50 // Adjust the size as needed

                    Item {
                        width: parent.width
                        height: parent.height
                    Path {
                        id: heartPath
                        fillColor: "transparent"
                        strokeColor: "red"
                        strokeWidth: 2

                        startX: 50
                        startY: 95

                        PathLine { x: 80; y: 60 }
                        PathArc {
                            x: 50; y: 30
                            radiusX: 30; radiusY: 30
                            useLargeArc: true
                            direction: PathArc.Clockwise
                        }
                        PathArc {
                            x: 20; y: 60
                            radiusX: 30; radiusY: 30
                            useLargeArc: true
                            direction: PathArc.Clockwise
                        }

                        PathLine { x: 50; y: 95 }
                    }


                    onClicked:{
                        fillColor: "red"
                        //stackView.push(Qt.resolvedUrl("CookBookPopup.qml"))
                    }
                    /*Shape {
                        ShapePath {
                            fillColor: "transparent"
                            strokeColor: "yellow"
                            strokeWidth: 2 // Adjust the border width as needed

                            PathPolyline {
                                path: [
                                    Qt.point(parent.width, parent.height),
                                    Qt.point(parent.width * 0.8, parent.height * 0.8),
                                    Qt.point(parent.width, parent.height * 0.6),
                                    Qt.point(parent.width * 0.6, parent.height * 0.6),
                                    Qt.point(parent.width * 0.5, parent.height * 0.4),
                                    Qt.point(parent.width * 0.4, parent.height * 0.6),
                                    Qt.point(0, parent.height * 0.6),
                                    Qt.point(parent.width * 0.2, parent.height * 0.8),
                                    Qt.point(0, parent.height),
                                    Qt.point(parent.width * 0.5, parent.height * 0.7) // Center point for symmetry
                                ]
                            }
                        }
                        anchors.fill: parent
                        onClicked: {
                            // Handle the click event
                            fillColor = "yellow";
                            // Additional actions can be added here
                        }
                        /*MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                // Handle the click event
                                fillColor = "yellow";
                                // Additional actions can be added here
                            }*/
                    //    }

                   // }
                   /*Shape {
                            ShapePath {
                                fillColor: "transparent"
                                strokeColor: "yellow"
                                strokeWidth: 2 // Adjust the border width as needed

                                PathPolyline {
                                    path: [
                                        Qt.point(parent.width, parent.height),
                                        Qt.point(0, parent.height),
                                        Qt.point(parent.width, parent.height/2),
                                        Qt.point(0, parent.height/2),
                                        Qt.point(parent.width/2, 0)
                                        /*Qt.point(100,  20),
                                        Qt.point(150, 180),
                                        Qt.point( 20,  75),
                                        Qt.point(180,  75),
                                        Qt.point( 50, 180),
                                        Qt.point(100,  20),
                                    ]
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        // Handle the click event
                                        fillColor = "yellow";
                                        // Additional actions can be added here
                                    }
                                }
                                // Define the star shape
                                startX: parent.width / 2
                                startY: 0
                                PathLine { x: parent.width; y: parent.height }
                                PathLine { x: 0; y: parent.height }
                                PathLine { x: parent.width; y: parent.height / 2 }
                                PathLine { x: 0; y: parent.height / 2 }
                                PathLine { x: parent.width / 2; y: 0 }
                                //closePath: true
                            }
                    /*Rectangle {
                            width: parent.width
                            height: parent.height

                            border.color: "yellow"
                            border.width: 2 // Adjust the border width as needed
                            radius: 12.5 // Adjust the corner radius as needed

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    // Handle the click event
                                    color = "yellow";
                                    // Additional actions can be added here
                                }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    // Handle the click event
                                    fillColor = "yellow";
                                    // Additional actions can be added here
                                }
                            }
                       }
                    }
                } */

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
    OpenRecipePopup{
        id: openRecipe
    }


}


