import QtQuick
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.6 //eli
//colors: green #5E9F7C lightgreen #D7ECDE

Rectangle {
    property string open_title: ""
    property string open_diet: ""
    property string open_time: ""
    property var open_ingredients
    property var open_instructions
    property bool nothing_found: false
    property string sorter_box : ""
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"

        Rectangle {
            width: 200
            height: 151
            color: "white"
            radius: 12.5
            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.5 - 100

            Column {
                Rectangle {
                    width: 200
                    height: 50
                    color: "transparent" // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            //fridgemanager.clear(itemModel.count)
                            stackView.replace(Qt.resolvedUrl("Fridge.qml"))
                        }

                        Rectangle {
                            width: 24
                            height: 24
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: 13 // Additional property for the small rectangle
                            Label {
                                text: "🗄️"
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }

                        Label {
                            text: "Fridge"
                            anchors.verticalCenter: parent.verticalCenter
                            x: 50 // Additional property for the label
                        }

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = "transparent"; // Back to transparent when not hovered
                        }
                    }
                }
                Rectangle {
                    width: 200
                    height: 0.5 // Height of the grey bar
                    color: "#D3D3D3" // Light grey color
                }

                Rectangle {
                    width: 200
                    height: 50
                    color: "transparent" // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            //fridgemanager.clear(itemModel.count)
                            stackView.replace(Qt.resolvedUrl("Market.qml"))
                        }

                        Rectangle {
                            width: 24
                            height: 24
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: 13 // Additional property for the small rectangle
                            Label {
                                text: "🛒"
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }

                        Label {
                            text: "Market"
                            anchors.verticalCenter: parent.verticalCenter
                            x: 50 // Additional property for the label
                        }

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = "transparent"; // Back to transparent when not hovered
                        }
                    }
                }

                Rectangle {
                    width: 200
                    height: 0.5 // Height of the grey bar
                    color: "#D3D3D3" // Light grey color
                }
                Rectangle {
                    width: 200
                    height: 50
                    color: "#EEEEEE" // Light grey color
                    radius: 12.5 // Add radius to the grey rectangle

                    Rectangle {
                        width: 24
                        height: 24
                        color: "#A3C995" // Updated color
                        radius: 2 // Updated radius
                        anchors.verticalCenter: parent.verticalCenter
                        x: 13 // Additional property for the small rectangle
                        Label {
                            text: "🍳"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Label {
                        text: "Recipes"
                        anchors.verticalCenter: parent.verticalCenter
                        x: 50 // Additional property for the label
                    }
                }

            }
        }

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.bottom: parent.bottom
            anchors.bottomMargin: deux.width * 0.04



            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                id: button
                anchors.fill: parent
                onClicked: {
                settings.open()
                }

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "⚙️"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "Settings"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
        }
    }
    Rectangle {
        id:deux
        x: parent.width * 0.20
        width: parent.width * 0.6
        height: parent.height
        color: "#5E9F7C"

        Rectangle {
            y: parent.height * 0.05
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white"
            property string newItemText: ""

            Label {
                text: "Nothing Corresponds to the current search, finish your word"
                color: "grey"
                font.pixelSize: 15
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                visible: nothing_found
            }

            Column {
                height: parent.height
                width: parent.width

                Rectangle {
                    radius: 12.5
                    y: parent.height*0.05
                    height: parent.height * 0.9
                    width: parent.width
                    color: "transparent"

                    ScrollView {
                        id: scrollView
                        anchors.fill: parent
                        width:parent.width
                        Column {
                            spacing: 2.5
                            width:parent.width
                            padding: parent.width*0.01

                            Rectangle {
                                radius: 12.5
                                width: parent.width *0.98
                                height: parent.width * 0.05
                                color:"#EEEEEE"



                                Row {
                                    spacing: 10
                                    padding:10
                                    anchors.verticalCenter:parent.verticalCenter
                                    width: parent.width
                                    TextField {
                                        y:3
                                        id: searchbar
                                        placeholderText: "🔎 Search"
                                        Layout.preferredWidth: 5000
                                        onTextChanged: {
                                            for (var i = 0; i < itemModel.count; i++) {
                                                RecipeController.submit(itemModel.get(i).name)
                                            }
                                            var to_display = RecipeController.search_res(searchbar.text)
                                            //var titles = RecipeController.titleOrDiet(to_display,0)
                                            var diets = RecipeController.titleOrDiet(to_display,1)

                                            itemModel.clear()

                                            if(to_display[0] == "NOTHING FOUND"){
                                                nothing_found = true;
                                            }
                                            else if(searchbar.text == "" && to_display[0] == "NOTHING FOUND"){
                                                nothing_found = false;
                                            }else{
                                                nothing_found = false;
                                                for (var j = 0; j< to_display.length; j++){
                                                    itemModel.append({"name" : to_display[j], "dietRestriction": diets[j], "grade": RecipeController.sendRatingForVis(to_display[j])});//titles[j], "dietRestriction" : diets[j]})
                                                }
                                            }
                                        }
                                    }
                                    Text {text: "Sort by:"; Layout.preferredWidth: 75; anchors.verticalCenter:parent.verticalCenter}

                                    ComboBox {
                                            //y:2
                                            id: priority
                                            width: 100
                                            model: ["None", "Vegetarian", "Gluten-free", "other"] //add "Vegan", "Dairy free"

                                            onCurrentIndexChanged: {
                                                console.log("Selected option:", model[currentIndex]);
                                                sorter_box = model[currentIndex];
                                            }
                                        }

                                    Button {
                                        text: "Sort"
                                        onClicked: {
                                            if(sorter_box != "None"){
                                                for (var i = 0; i < itemModel.count; i++) {
                                                    RecipeController.submit(itemModel.get(i).name)
                                                }
                                                var to_display = RecipeController.search_res(sorter_box)
                                                var diets = RecipeController.titleOrDiet(to_display,1)

                                                itemModel.clear()

                                                if(to_display[0] == "NOTHING FOUND"){
                                                    nothing_found = true;
                                                }
                                                else if(searchbar.text == "" && to_display[0] == "NOTHING FOUND"){
                                                    nothing_found = false;
                                                }else{
                                                    nothing_found = false;
                                                    for (var j = 0; j< to_display.length; j++){
                                                        itemModel.append({"name" : to_display[j], "dietRestriction": diets[j], "grade": RecipeController.sendRatingForVis(to_display[j])});//titles[j], "dietRestriction" : diets[j]})
                                                    }
                                                }
                                            }else{
                                                for (var i = 0; i < itemModel.count; i++) {
                                                    RecipeController.submit(itemModel.get(i).name)
                                                }

                                                nothing_found = false
                                                itemModel.clear()
                                                var len = RecipeController.getTotalLength()
                                                for (var j = 0; j < len; j++) {
                                                    var see = [RecipeController.gett(j)]
                                                    itemModel.append({"name": RecipeController.gett(j), "dietRestriction":RecipeController.titleOrDiet(see,1)[0], "grade": RecipeController.sendRatingForVis(RecipeController.gett(j))})
                                                }
                                                scrollView.contentHeight = len*82.5;
                                                searchbar.text = ""
                                            }
                                        }
                                    }

                                    Button {
                                        text: "Reset"
                                        onClicked: {
                                            for (var i = 0; i < itemModel.count; i++) {
                                                RecipeController.submit(itemModel.get(i).name)
                                            }

                                            nothing_found = false
                                            itemModel.clear()
                                            var len = RecipeController.getTotalLength()
                                            for (var j = 0; j < len; j++) {
                                                var see = [RecipeController.gett(j)]
                                                itemModel.append({"name": RecipeController.gett(j), "dietRestriction":RecipeController.titleOrDiet(see,1)[0], "grade": RecipeController.sendRatingForVis(RecipeController.gett(j))})
                                            }
                                            scrollView.contentHeight = len*82.5;
                                            searchbar.text = ""
                                        }
                                    }
                                }
                            }

                            Repeater {
                                model: itemModel
                                Rectangle {
                                    radius:12.5
                                    width: parent.width*0.98
                                    height: 80
                                    //border.color: "#28A745"
                                    color: "#EEEEEE"

                                    Rectangle {
                                        radius:12.5
                                        width: parent.height*0.9
                                        height: parent.height*0.9
                                        x : 5
                                        anchors.verticalCenter: parent.verticalCenter
                                        color:"lightblue"

                                        //Label {text:"photo"}
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
        color: "#5E9F7C"
        anchors.right: parent.right
        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.top: parent.top
            anchors.topMargin: deux.width * 0.05
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                id: basket
                //id: addtofridge
                anchors.fill: parent

                onClicked: {
                //cookBook.open()
                //for(var i = 0; i<10;i++){
                //    itemModel.append(RecipeController.getJsonRTitle(i))
                //}
                //var temp_title = RecipeController.getJsonRTitle(0)
                //itemModel.append({"name" : "Vegetarian Lasagna"})
                //itemModel.append({"name" : "Eggs Benedict"})
                //itemModel.append({"name" : "Noodle Soup"})
                //itemModel.append({"name" : temp_title})
                //scrollView.contentHeight = scrollView.contentHeight + 3*82.5;
                RecipeController.initial()
                addRecipe.open()
                }

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "➕"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "Add A Recipe"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
        }
        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.top: parent.top
            anchors.topMargin: deux.width * 0.1+50
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {

                //id: addtofridge
                anchors.fill: parent

                onClicked: {
                RecipeController.initial()
                addFavoriteRecipe.open()
                }

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "🧑‍🍳"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "My Personal Cookbook"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
        }

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.top: parent.top
            anchors.topMargin: deux.width * 0.20 +50
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                id: demo_recipe
                //id: addtofridge
                anchors.fill: parent

                onClicked: {
                    // Append 3 recipes for the demontrastion

                    RecipeController.submitIngredients("2 carrot");
                    RecipeController.submitIngredients("2 celery");
                    RecipeController.submitIngredients("500g pasta");

                    RecipeController.submitInstructions("peel vegetables")
                    RecipeController.submitInstructions("boil them")
                    RecipeController.submitInstructions("enjoy!")


                    //if(hours.text.trim() == ""){hours.text = 0;}
                    //if(minutes.text.trim() == ""){minutes.text = 0;}
                    var res = RecipeController.submitAll("Lasagna", "None", "0", "30")//, ingredient1.text, instruction1.text)



                    var no_Value = RecipeController.get_ingr()

                    itemModel.append({"name": "Lasagna", "dietRestriction": "None", "grade": "None" , "date": "0" , "quantity": "30"});


                    // RECIPE 2

                    RecipeController.submitIngredients("2 apple");
                    RecipeController.submitIngredients("2 banana");
                    RecipeController.submitIngredients("200g flour");
                    RecipeController.submitIngredients("100g sugar");
                    RecipeController.submitIngredients("3 eggs");


                    RecipeController.submitInstructions("cut fruits")
                    RecipeController.submitInstructions("mix everything")
                    RecipeController.submitInstructions("bake in the oven for 1h")


                    //if(hours.text.trim() == ""){hours.text = 0;}
                    //if(minutes.text.trim() == ""){minutes.text = 0;}
                    var res = RecipeController.submitAll("Apple Banana Cake", "Vegetarian", "1", "0")//, ingredient1.text, instruction1.text)



                    var no_Value = RecipeController.get_ingr()

                    itemModel.append({"name": "Apple Banana Cake", "dietRestriction": "Vegetarian", "grade": "None" , "date": "1" , "quantity": "0"});

                    //RECIPE 3

                    RecipeController.submitIngredients("1 onion");
                    RecipeController.submitIngredients("3 eggs");
                    RecipeController.submitIngredients("3 potatoes");
                    RecipeController.submitIngredients("salt");
                    RecipeController.submitIngredients("pepper");


                    RecipeController.submitInstructions("cut the potatoes")
                    RecipeController.submitInstructions("grill them in a pan")
                    RecipeController.submitInstructions("add the eggs and flip")


                    //if(hours.text.trim() == ""){hours.text = 0;}
                    //if(minutes.text.trim() == ""){minutes.text = 0;}
                    var res = RecipeController.submitAll("Tortillas", "Vegetarian", "0", "20")//, ingredient1.text, instruction1.text)



                    var no_Value = RecipeController.get_ingr()

                    itemModel.append({"name": "Tortillas", "dietRestriction": "Vegetarian", "grade": "None" , "date": "0" , "quantity": "20"});

                }

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "💾"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "Recipies Demo"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
        }

        Rectangle {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom:parent.bottom
            anchors.bottomMargin: parent.height * 0.1 +50
            //y: parent.height * 0.75
            //x: parent.width * 0.5 - 50
            width: 75
            height: 95
            color: "white"
            radius:12.5


            MouseArea {
                anchors.fill: parent
                onClicked: {
                    profile.open()
                }

                Rectangle {
                    id:centerprofile
                    y:parent.parent.height * 0.15
                    //x:parent.parent.height * 0.15
                    width: parent.width * 0.7
                    height: parent.width * 0.7
                    color: "#A3C995"
                    radius: 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    //anchors.verticalCenter: parent.verticalCenter
                    //anchors.bottom: parent.bottom
                    //anchors.bottomMargin:  parent.parent.height * 1/2// Adjust the margin as needed

                    Label {
                        property var textList: ["💁‍♀️", "🧜🏽", "👩🏾‍💼", "👨🏻‍🦰","🧕🏻","👨🏻‍🎓"]
                        text: textList[Math.ceil(Math.random() * 5)]
                        font.pixelSize: parent.height *0.7
                        anchors.bottom: parent.bottom
                        //anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
                Label {
                    text: "Profile"
                    font.bold: true
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        bottom: parent.bottom
                        bottomMargin: 5 // Adjust the margin as needed
                    }
                }
                hoverEnabled: true

                onEntered: {
                    centerprofile.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    centerprofile.color = "#A3C995"; // Back to transparent when not hovered
                }

            }
        }

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.bottom: parent.bottom
            anchors.bottomMargin: deux.width * 0.04
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                anchors.fill: parent

                onClicked: {stackView.push(Qt.resolvedUrl("LoginPage.qml"))}

                Rectangle {
                    width: 24
                    height: 24
                    color: "#A3C995" // Updated color
                    radius: 2 // Updated radius
                    anchors.verticalCenter: parent.verticalCenter
                    x: 13 // Additional property for the small rectangle
                    Label {
                        text: "👋"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Label {
                    text: "Logout"
                    anchors.verticalCenter: parent.verticalCenter
                    x: 50 // Additional property for the label
                }

                hoverEnabled: true

                onEntered: {
                    parent.color = "#D3D3D3"; // Light grey when hovered
                }

                onExited: {
                    parent.color = "white"; // Back to transparent when not hovered
                }
            }
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

        //ON LINE 1 OF GRID
            Text {text: "Enter your rating from 0 to 5:"; color: "#28A745"; Layout.preferredWidth: 250}

            TextField {
                Layout.preferredWidth: 75
                id: user_rating
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
                    var rating = RecipeController.submitRating(user_rating.text)

                    for (var i = 0; i < itemModel.count; i++) {
                        RecipeController.submit(itemModel.get(i).name)
                    }

                    nothing_found = false
                    itemModel.clear()
                    var len = RecipeController.getTotalLength()
                    for (var j = 0; j < len; j++) {
                        var see = [RecipeController.gett(j)]
                        itemModel.append({"name":RecipeController.gett(j) , "dietRestriction":RecipeController.titleOrDiet(see,1)[0], "grade": RecipeController.sendRatingForVis(RecipeController.gett(j)) })
                    }
                    user_rating.text = ""
                    myPopup.close()
                }
            }

            Button {
                text: "submit"
                width: 75

                onClicked: {
                    myPopup.close()
                    user_rating.text = ""
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

    PersonalCookBook{ //eli
        id: addFavoriteRecipe
    }

    Settings {
        id: settings
    }
    Profile {
        id: profile
    }

    Popup {
        id: viewRecipePopup
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
                viewRecipePopup.close()

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
            Text {text: "Recipe Name:"; color: "#28A745"; Layout.preferredWidth: 75}

            Text {text: open_title; color: "blue"; Layout.preferredWidth: 75}



            //ON LINE 2 OF GRID
            Text {text: "Dietary Restriction:"; color: "#28A745"; Layout.preferredWidth: 125}

            Text {text: open_diet; color: "blue"; Layout.preferredWidth: 125}
        }


        GridLayout{
            id: grid2
            columns: 2
            width: parent.width
            columnSpacing: 20
            rowSpacing: 10
            y: parent.height*0.155
            height: parent.height*0.033333


            //ON LINE 1 OF GRID
            Text {text: "Total time"; color: "#28A745"; Layout.preferredWidth: 65}

            Text {text: open_time + " hours"; color: "blue"; Layout.preferredWidth: 65}
        }

        GridLayout{
            id: grid3
            columns: 1
            width: parent.width
            columnSpacing: 20
            rowSpacing: 10
            y: parent.height*0.23
            height: parent.height*0.033333


            //ON LINE 1 OF GRID
            Text {text: "Ingredients"; color: "#28A745"; Layout.preferredWidth: 155}
        }
        ListModel{
            id: readIngredients
        }


        Rectangle{
            radius: 20
            y: parent.height * 0.30
            height: parent.height * 0.2
            width: parent.width
            color: "#EEEEEE"
            border.color:"#CCCCCC"
            ScrollView{
                id: scroller_vis
                anchors.fill: parent
                width:parent.width
                Column{
                    spacing: 2.5
                    width:parent.width
                    Repeater{
                        model: readIngredients
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
                                    width: parent.width
                                    Layout.preferredWidth: 400
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
            id: readInstructions

        }

        GridLayout{
            id: grid4
            columns: 1
            width: parent.width
            columnSpacing: 20
            rowSpacing: 10
            y: parent.height*0.505

            //ON LINE 1 OF GRID
            Text {text: "Instructions"; color: "#28A745"; Layout.preferredWidth: 150}
        }

        Rectangle{
            radius: 20
            y: parent.height * 0.6
            height: parent.height * 0.3
            width: parent.width
            color: "#EEEEEE"
            border.color:"#CCCCCC"
            ScrollView{
                id: scroller_vis2
                anchors.fill: parent
                width:parent.width
                Column{
                    spacing: 2.5
                    width:parent.width
                    Repeater{
                        model: readInstructions
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
    }

}
