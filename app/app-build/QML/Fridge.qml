import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//colors: green #5E9F7C lightgreen #D7ECDE


Rectangle {

    Component.onCompleted: {
        console.log('hello fridge')
        // Your function code goes here
        var myfridge = fridgemanager.sort_ingredients_by_expiration_date();
        console.log('fridge downloaded')
        console.log('nb in fridge', myfridge.length)


        for (var q = 0; q < myfridge.length; q++) {
            console.log(q, "ingre", myfridge[q]);

            var newIngredient = {
                "index": q,
                "item": myfridge[q][0],
                "categorie": myfridge[q][3],
                "date": myfridge[q][1],
                "quantity": myfridge[q][2],
                "status": 0,
                "price": 0,
                "quantity2sell": 0,
                "pricestatus": -1,
                "visibility": 1
            };

            itemModel.append(newIngredient);
        }
    }

    property int currentIndex: 0
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        /*Column {

            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.05

            Button { text: "My Fridge"; enabled: false; onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
            Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
            //Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
            Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

        }*/

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
                    color: "transparent" // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            //fridgemanager.clear(itemModel.count)
                            stackView.replace(Qt.resolvedUrl("Recipes.qml"))
                        }

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

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = "transparent"; // Back to transparent when not hovered
                        }
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
        id: deux
        x: parent.width * 0.20
        width: parent.width * 0.6
        height: parent.height
        color: "#5E9F7C"

        /*Row{
            anchors.top: parent.top
            Button {
                id:buttonFridge
                enabled: false
                text: "My Fridge"
                width: parent.parent.width * 0.2
                onClicked: {
                    fridgePage.visible = true;
                    offerPage.visible = false;
                    buttonOffer.enabled = true;
                    buttonFridge.enabled = false;
                    addtofridgebutton.visible= true;
                }
            }
            Button {
                id:buttonOffer
                enabled: true
                text: "My Offers"
                width: parent.parent.width * 0.2
                onClicked: {
                    fridgePage.visible = false;
                    offerPage.visible = true;
                    buttonOffer.enabled = false;
                    buttonFridge.enabled = true;
                    addtofridgebutton.visible= false;
                }
            }
        }*/
        Rectangle {
            color: "white"
            radius:12.5
            height:parent.width * 0.04
            width: parent.width * 0.4 + 0.05
            x: parent.width * 0.01
            y: parent.width * 0.01


            Row {
                anchors.top: parent.top

                Rectangle {
                    id:fridgecolor
                    width: (parent.parent.width - 0.05) * 0.5
                    height: parent.parent.height
                    color: buttonFridge.enabled ? "white" : "#EEEEEE"
                    //color: "#EEEEEE" // Light grey color
                    radius: 12.5 // Add radius to the grey rectangle

                    Rectangle {
                        width: parent.parent.height *2/3
                        height: parent.parent.height *2/3
                        color: "#A3C995" // Updated color
                        radius: 2 // Updated radius
                        anchors.verticalCenter: parent.verticalCenter
                        x: parent.parent.height *1/6 // Additional property for the small rectangle
                        Label {
                           text: "🍅"
                           anchors.verticalCenter: parent.verticalCenter
                           anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Label {
                        text: "My Fridge"
                        anchors.verticalCenter: parent.verticalCenter
                        x: parent.parent.height // Additional property for the label
                    }

                    MouseArea {
                        id: buttonFridge
                        enabled : false
                        anchors.fill: parent
                        onClicked: {
                            fridgePage.visible = true;
                            offerPage.visible = false;
                            buttonOffer.enabled = true;
                            buttonFridge.enabled = false;
                            addtofridgebutton.visible = true;
                            parent.color=buttonFridge.enabled ? "white" : "#EEEEEE";
                            offercolor.color = buttonOffer.enabled ? "white" : "#EEEEEE";
                        }

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = buttonFridge.enabled ? "white" : "#EEEEEE"; // Back to white when not hovered
                        }
                    }
                }

                Rectangle {
                    width: 0.5
                    height: parent.parent.height // Height of the grey bar
                    color: "#D3D3D3" // Light grey color
                }

                Rectangle {
                    id:offercolor
                    width: (parent.parent.width - 0.05) * 0.5
                    height: parent.parent.height
                    color: buttonOffer.enabled ? "white" : "#EEEEEE"; // Transparent color
                    radius: 12.5 // Add radius to the transparent rectangle

                    MouseArea {
                        id: buttonOffer
                        anchors.fill: parent
                        onClicked: {
                            fridgePage.visible = false;
                            offerPage.visible = true;
                            buttonOffer.enabled = false;
                            buttonFridge.enabled = true;
                            addtofridgebutton.visible = false;
                            parent.color = buttonOffer.enabled ? "white" : "#EEEEEE";
                            fridgecolor.color = buttonFridge.enabled ? "white" : "#EEEEEE";
                        }

                        Rectangle {
                            width: parent.parent.height *2/3
                            height: parent.parent.height *2/3
                            color: "#A3C995" // Updated color
                            radius: 2 // Updated radius
                            anchors.verticalCenter: parent.verticalCenter
                            x: parent.parent.height *1/6 // Additional property for the small rectangle
                            Label {
                                text: "📣"
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }

                        Label {
                            text: "My Offers"
                            anchors.verticalCenter: parent.verticalCenter
                            x: parent.parent.height // Additional property for the label
                        }

                        hoverEnabled: true

                        onEntered: {
                            parent.color = "#D3D3D3"; // Light grey when hovered
                        }

                        onExited: {
                            parent.color = buttonOffer.enabled ? "white" : "#EEEEEE"; // Back to transparent when not hovered
                        }
                    }
                }
            }
        }


        Rectangle {
            id: offerPage
            visible: false
            y: parent.width * 0.06
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white"
            Column {
                spacing: 2.5
                width: parent.width
                padding:parent.width*0.01
                height:parent.height
                Rectangle {
                    radius: 12.5
                    width: parent.width *0.98
                    height: parent.width * 0.05
                    color:"#EEEEEE"

                    /*Label {
                        text: "My Fridge __ Hello, on this page \n The add product works, you can try it, (you need to put at least a name and a category)\nIf there are enough products the scroll bar will appear\nIf questions, ask Antoine"
                        anchors.top: parent.top
                    }*/

                    Row {
                        spacing: 10
                        padding:10
                        anchors.verticalCenter:parent.verticalCenter
                        TextField {
                            y:3
                            id: itemTextFieldOffer
                            placeholderText: "Search for a specific item"
                            //onTextChanged: newItemText = itemTextField.text // Update the newItemText on text change
                        }

                        Button {
                            text: "Category"
                            onClicked: {
                               //std::vector<Ingredient> sorted_fridge = sort_ingredient_by_category()
                            }
                        }

                        Button {
                            text: "Time left"
                            onClicked: {
                                //std::vector<Ingredient> sorted_fridge = sort_ingredient_by_expiration_date()
                            }
                        }

                        /*Button {
                            text: "Price"
                            onClicked: {
                                // Handle Price button click
                            }
                        }*/
                    }
                }
                Rectangle {
                    radius: 12.5
                    y: parent.height * 0.2
                    height: parent.height - 5 - parent.width*0.01 - parent.width * 0.05
                    width: parent.width * 0.99
                    color: "white"
                    ScrollView {
                        id: scrollViewOffer
                        anchors.fill: parent
                        width:parent.width
                        Column {
                            spacing: 2.5
                            width:parent.width
                            Repeater {
                                model: itemModel
                                Rectangle {
                                    visible: model.status
                                    radius: 12.5
                                    width: scrollViewOffer.contentHeight < 625 ? parent.width * 0.99 : parent.width
                                    height: 150
                                    color: "#EEEEEE"  // Adjust the color as needed

                                    Row {
                                        spacing:5
                                        padding:5
                                        width: parent.width
                                        height: parent.height
                                        Rectangle {
                                            radius: 12.5
                                            width: parent.height -10
                                            height: parent.height -10
                                            color: "lightblue"
                                            Label { text: "photo" }
                                        }
                                        Column {
                                            x: parent.height
                                            spacing: 1
                                            Label {
                                                text: "Item: " + model.item
                                            }
                                            Label {
                                                text: "Category: " + model.categorie
                                            }
                                            Label {
                                                text: "Expiration date: " + model.date
                                            }
                                            Label {
                                                text: "Quantity you are selling: " + model.quantity2sell
                                            }
                                            Label {
                                                text: "Quantity you have: " + model.quantity
                                            }
                                            Label {
                                                text: {
                                                    if (model.pricestatus === 0) {
                                                        return "Your item is set as Free";
                                                    } if (model.pricestatus === 1) {
                                                        return "Your item is set as Negociable";
                                                    } else {
                                                        return "Price: " + model.price;
                                                    }
                                                }
                                            }
                                        }
                                        Column {
                                            Button {
                                                text: "Remove Offer"
                                                onClicked: {
                                                    model.quantity2sell= 0
                                                    model.pricestatus= -1
                                                    model.status= 0
                                                    model.price= 0
                                                    scrollViewOffer.contentHeight-= 152.5

                                                }
                                            }
                                            Button {
                                                text: "Modify Offer"
                                                onClicked: {
                                                    modifyOffer.open()
                                                    itemIndex2 = itemModel.getIndexByPropertyValue("index", model.index);
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
        }
        Rectangle {
            id: fridgePage
            visible: true
            y: parent.width * 0.06
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white"
            property string newItemText: ""

            Column {
                height: parent.height
                width: parent.width
                padding: parent.width *0.01
                spacing: parent.width *0.01


                Rectangle {
                    radius: 12.5
                    width: parent.width *0.98
                    height: parent.width * 0.05
                    color:"#EEEEEE"

                    /*Label {
                        text: "My Fridge __ Hello, on this page \n The add product works, you can try it, (you need to put at least a name and a category)\nIf there are enough products the scroll bar will appear\nIf questions, ask Antoine"
                        anchors.top: parent.top
                    }*/

                    Row {
                        spacing: 10
                        padding:10
                        anchors.verticalCenter:parent.verticalCenter
                        TextField {
                            y:3
                            id: searchbarFridge
                            placeholderText: "🔎 Search"
                            //onTextChanged: newItemText = itemTextField.text // Update the newItemText on text change
                            onTextChanged: {
                                console.log("nb d'ingredients:", itemModel.count);

                                console.log("Search bar text:", searchbarFridge.text);
                                console.log("Search bar nb characters:", searchbarFridge.text.length);
                                if (searchbarFridge.text.length === 0) {
                                    for (var i = 0; i < itemModel.count; ++i) {
                                        itemModel.setProperty(i, "visibility", 1);
                                    }
                                }
                                else {
                                var big_qlist = fridgemanager.search_result(searchbarFridge.text)
                                var visible = big_qlist[0]
                                var invisible = big_qlist[1]

                                itemModel.clear()
                                for (var q = 0; q< visible.length; q++){
                                    console.log(q, "visible", visible[q][0])
                                    var newIngredient = {
                                        "index": q, "item": visible[q][0], "categorie": visible[q][3], "date": visible[q][1], "quantity": visible[q][2],
                                        "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 1
                                    };
                                    itemModel.append(newIngredient);
                                }
                                var m = visible.length
                                console.log(m+invisible.length)
                                for (var h = 0; h< invisible.length; h++){
                                    console.log(h, h+m, "invisible", invisible[h][0])
                                    var newIngredient_inv = {
                                        "index": (h+m), "item": invisible[h][0], "categorie": invisible[h][3], "date": invisible[h][1], "quantity": invisible[h][2],
                                        "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 0
                                    };
                                    itemModel.append(newIngredient_inv);
                                }
                                }
                            }
                        }

                        ComboBox {
                            id: categorieMenu
                            width: 200
                            model: ["All Categories", "Unspecified", "Fruit", "Vegetable", "Drink", "Dairy", "Canned",
                                "Meat", "Fish", "Sweet", "Nut", "Other"]
                            onCurrentIndexChanged: {
                                //searchbarFridge.text = ""
                                console.log("Selected option:", model[currentIndex]);
                                console.log("len itemmodel:", itemModel.count);
                                console.log("OK");
                                if (model[currentIndex] === "All Categories") {
                                    for (var i = 0; i < itemModel.count; ++i) {
                                        itemModel.setProperty(i, "visibility", 1);
                                    }
                                }
                                else {
                                    for (var j = 0; j < itemModel.count; ++j) {
                                        var itemCategory = itemModel.get(j).categorie;
                                        console.log(model[currentIndex], itemCategory);
                                        if (model[currentIndex] === itemCategory) {
                                            console.log("visibility set to 1");
                                            itemModel.setProperty(j, "visibility", 1);
                                        } else {
                                            console.log("visibility set to 0");
                                            itemModel.setProperty(j, "visibility", 0);
                                        }
                                    }
                                }
                            }
                        }

                        Button {
                            text: "Time left"
                            onClicked: {
                                if (itemModel.count !== 0) {
                                var sorted_fridge = fridgemanager.sort_ingredients_by_expiration_date()
                                itemModel.clear()
                                for (var j = 0; j< sorted_fridge.length; j++){
                                    var newIngredient = {
                                        "index": j,
                                        "item": sorted_fridge[j][0],
                                        "categorie": sorted_fridge[j][3],
                                        "date": sorted_fridge[j][1],
                                        "quantity": sorted_fridge[j][2],
                                        "status": 0,
                                        "price" : 0,
                                        "quantity2sell": 0,
                                        "pricestatus": -1,
                                        "visibility" : 1
                                    };

                                    itemModel.append(newIngredient);
                                    //itemModel.append({"name" : sorted_fridge[j]})//titles[j], "dietRestriction" : diets[j]})
                                }
                                }
                            }
                        }

                        /*Button {
                            text: "Price"
                            onClicked: {
                                // Handle Price button click
                            }
                        }*/
                    }
                }
                Rectangle {
                    radius: 12.5
                    y: parent.height * 0.2
                    height: parent.height - parent.width *0.08
                    width: parent.width *0.99
                    color:"white"
                    ScrollView {
                        id: scrollViewFridge
                        anchors.fill: parent
                        width:parent.width
                        Column {
                            spacing: 2.5
                            width:parent.width
                            Repeater {
                                model: itemModel
                                //property var modelData: model // Assuming each model item is an object
                                Rectangle {
                                    visible: model.visibility
                                    radius:12.5
                                    width: scrollViewFridge.contentHeight < 625 ? parent.width * 0.99 : parent.width
                                    height: 150
                                    color: "#EEEEEE"
                                    Row {
                                        spacing:5
                                        padding:5
                                        width: parent.width
                                        height: parent.height
                                        Rectangle {
                                            radius: 12.5
                                            x:5
                                            y:5
                                            width: parent.height -10
                                            height: parent.height -10
                                            color: "lightblue"
                                            Label { text: "photo" }
                                        }
                                        Column {
                                            x:parent.height+5
                                            y:5
                                            spacing:1
                                            Label {
                                                text: "Item: " + model.item // Access the "item" property of the model data
                                            }
                                            Label {
                                                text: "Categorie: " + model.categorie // Access the "categorie" property of the model data
                                            }
                                            /*Label {
                                                text: "Index: " + model.index
                                            }*/

                                            Label {
                                                text: "Expiration date: " + model.date
                                            }

                                            Label {
                                                text: "Quantity: " + model.quantity
                                            }
                                            Label {
                                                visible: model.status
                                                text: "You are selling this item"
                                            }
                                        }
                                        Column {
                                            width: parent.width * 0.4 // Set the width of the column as half of the parent width
                                            anchors.right: parent.right
                                            /*Button {
                                                text: "Price Settings"
                                                onClicked: {
                                                    var indexToSell = itemModel.getIndexByPropertyValue("index", model.index);
                                                    if (indexToSell !== -1) {
                                                        selling.itemIndex = indexToSell;
                                                        selling.open();
                                                    } else {
                                                        console.warn("No item available for sale.");
                                                    }
                                                }
                                            }*/
                                            Button {
                                                text: "Modify item"
                                                onClicked: {
                                                    modify.itemIndex3 = itemModel.getIndexByPropertyValue("index", model.index);
                                                    console.log(modify.itemIndex3)
                                                    modify.open();
                                                    //pop_elt(itemModel.getIndexByPropertyValue("index", model.index))
                                                }
                                            }
                                            Button {
                                                text: "Remove item"
                                                onClicked: {
                                                    if(true) {
                                                    scrollViewFridge.contentHeight -= 152.5;
                                                    if(model.status) {
                                                        scrollViewOffer.contentHeight = scrollViewOffer.contentHeight - 152.5;
                                                    };

                                                    //itemModel.remove(itemModel.getIndexByPropertyValue("index", model.index));
                                                    console.log("ok1")
                                                    console.log(itemModel.getIndexByPropertyValue("index", model.index))
                                                    fridgemanager.pop_elt(itemModel.getIndexByPropertyValue("index", model.index))
                                                    console.log("ok2")
                                                    itemModel.remove(itemModel.getIndexByPropertyValue("index", model.index))
                                                    console.log("ok3")

                                                    }
                                                }
                                            }

                                            Button {

                                                visible: !(model.status)
                                                text: "Put on sell"
                                                onClicked: {
                                                    selling.itemIndex = itemModel.getIndexByPropertyValue("index", model.index);
                                                    selling.open();
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
        }
        ListModel {
                id: itemModel
                function getIndexByPropertyValue(propertyName, propertyValue) {
                    for (var i = 0; i < count; i++) {
                        if (get(i)[propertyName] === propertyValue) {
                            return i;
                        }
                    }
                    return -1; // Return -1 if the item is not found
                }

                /*var myfridge = fridgemanager.myFridge
                for (var q = 0; q< myfridge.length; q++) {
                    console.log(q, "vingre", myfridge[0])
                    var newIngredient = {
                        "index": q, "item": visible[q][0], "categorie": visible[q][3], "date": visible[q][1], "quantity": visible[q][2],
                        "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 1
                    };
                    itemModel.append(newIngredient);
                }*/
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
            anchors.topMargin: deux.width * 0.06
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {
                id: basket
                anchors.fill: parent

                onClicked: {
                    var apple = {
                        "index": 0, "item": "apple", "categorie": "Fruit", "date": "01/05/2024", "quantity": "2", "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 1
                    };
                    var milk = {
                        "index": 1, "item": "milk", "categorie": "Drink", "date": "01/02/2024", "quantity": "1", "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 1
                    };
                    var carrot = {
                        "index": 2, "item": "carrot", "categorie": "Vegetable", "date": "01/03/2024", "quantity": "3", "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 1
                    };
                    var banana = {
                        "index": 3, "item": "banana", "categorie": "Fruit", "date": "01/04/2024", "quantity": "1", "status": 0, "price" : 0, "quantity2sell": 0, "pricestatus": -1, "visibility" : 1
                    };
                    itemModel.append(apple);
                    itemModel.append(milk);
                    itemModel.append(carrot);
                    itemModel.append(banana);
                    fridgemanager.add_elt(apple.item, apple.date, apple.quantity, apple.categorie);
                    fridgemanager.add_elt(milk.item, milk.date, milk.quantity, milk.categorie);
                    fridgemanager.add_elt(carrot.item, carrot.date, carrot.quantity, carrot.categorie);
                    fridgemanager.add_elt(banana.item, banana.date, banana.quantity, banana.categorie);
                    scrollViewFridge.contentHeight += 152.5*4;
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
                    text: "Demo Fridge"
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
            id: addtofridgebutton
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.5 - 100
            anchors.top: parent.top
            anchors.topMargin: deux.width * 0.06 + 100
            width: 200
            height: 50
            color: "white" // Transparent color
            radius: 12.5 // Add radius to the transparent rectangle

            MouseArea {

                anchors.fill: parent

                onClicked: {
                    addtofridge.open()
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
                    text: "Add a product"
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
                        property var textList: ["💁‍♀️", "🧜🏽", "👩🏾‍💼", "👨🏻‍🦰","🧕🏻", "👨🏻‍🎓", "👩‍🚀"]
                        text: textList[Math.ceil(Math.random() * 6)]
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
    property int itemIndex2: -1
    Popup {
        id: modifyOffer
        anchors.centerIn: parent
        width: 350
        height: 370
        closePolicy: "CloseOnEscape"
        background: Rectangle {
            color: "#EEEEEE"
            radius: 12.5
        }
        //property int itemIndex: -1

        Column {
            anchors.centerIn: parent
            spacing: 10

            Button {
                anchors.right: parent.right
                text: "X"
                width: 50
                background: null
                onClicked: {
                    modifyOffer.close()
                }
            }

            Label {
                text: "Enter the quantity you want to sell. Must be less than " + itemModel.get(itemIndex).quantity
            }

            TextField {
                id: quantity2sellInput
                width: 340
                height: 25
                padding: 5
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
                placeholderText: "Enter Quantity"
                text: itemModel.get(itemIndex2).quantity
            }

            ComboBox {
                id: priceType
                width: 200
                model: ["Free", "Negotiate", "Fixed Price"]

                onCurrentIndexChanged: {
                    priceInput.enabled = priceType.currentIndex === 2;
                }
            }

            TextField {
                id: priceInput
                width: 340
                height: 25
                padding: 5
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                    color: "#5E9F7C"
                    radius: 12.5
                }
                placeholderText: "Enter Price"
                enabled: priceType.currentIndex === 2
            }

            Label {
                id: errorQuantity
                visible: false
                text: "Quantity Invalid"
                color: "red"
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter

                Button {
                    text: "Validate"
                    width: 150
                    background: Rectangle {
                        color: "#5E9F7C"
                        radius: 12.5
                    }
                    onClicked: {
                        errorQuantity.visible = false;

                        itemModel.setProperty(itemIndex2, "pricestatus", priceType.currentIndex);
                        //itemModel.setProperty(itemIndex, "status", 1);
                        itemModel.setProperty(itemIndex2, "quantity2sell", quantity2sellInput.text);
                        itemModel.setProperty(itemIndex2, "price", priceInput.text);

                        quantity2sellInput.text = "";
                        priceInput.text = "";

                        modifyOffer.close();
                        /*if (quantity2sellInput.text <= itemModel.get(itemIndex).quantity) {
                            console.log("Button Clicked");
                            console.log("quantity2sellInput.text:", quantity2sellInput.text);
                            console.log("itemModel.get(itemIndex).quantity:", itemModel.get(itemIndex).quantity);

                            errorQuantity.visible = false;

                            itemModel.setProperty(itemIndex, "pricestatus", priceType.currentIndex);
                            itemModel.setProperty(itemIndex, "status", 1);
                            itemModel.setProperty(itemIndex, "quantity2sell", quantity2sellInput.text);
                            itemModel.setProperty(itemIndex, "price", priceInput.text);

                            quantity2sellInput.text = "";
                            priceInput.text = "";

                            modifyOffer.close();
                        } else {
                            errorQuantity.visible = true;
                            quantity2sellInput.text = "";
                        }*/
                    }
                }
            }
        }
    }

Profile {
    id: profile
}
Settings {
    id:settings
}
AddToFridge {
    id:addtofridge
}
Selling {
    id:selling
}
Modify {
    id: modify
}
}



//Under is old code from Martin
/*Item {


Item {

    // SETTINGS POPUP
    // currently a template, created by Antoine on the other branch (ty)

    Column {

        anchors.left: parent.left
        anchors.bottom: parent.verticalCenter
        anchors.leftMargin: parent.width * 0.05

        Button { text: "Fridge"; enabled: false; onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
        Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
        Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
        Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

    }

    // BOTTOM BUTTONS

    Profile {
        id: profile
    }

    Settings {
        id: settings
    }

    Column {


        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        Button {
            id: profilebutton
            text: "Profile"
            onClicked: {
                profile.open()
            }
        }

        Button {
            id: settingsbutton
            text: "Settings"
            onClicked: {
            settings.open()
            }
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

    // Adding connection from other pages

    Connections {
            target: signinLogic // Assuming signinLogic is accessible here

            onOpenFridgePage: {
                // Logic to display the Fridge page
                // For example:
                stackView.push(Qt.resolvedUrl("Fridge.qml"))
            }
        }
}
