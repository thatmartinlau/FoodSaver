import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//colors: green #5E9F7C lightgreen #D7ECDE

Row {
    property int currentIndex: 0
    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        Column {

            anchors.left: parent.left
            anchors.bottom: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.05

            Button { text: "My Fridge"; enabled: false; onClicked: stackView.push(Qt.resolvedUrl("Fridge.qml")) }
            Button { text: "Market"; onClicked: stackView.replace(Qt.resolvedUrl("Market.qml")) }
            Button { text: "My Favorites"; onClicked: stackView.replace(Qt.resolvedUrl("Favorites.qml")) }
            Button { text: "Recipes"; onClicked: stackView.replace(Qt.resolvedUrl("Recipes.qml")) }

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
        color: "#5E9F7C"

        Row{
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

                        }
                    }
        }

        Rectangle {
            id: offerPage
            visible: false
            y: parent.height * 0.05
            height: parent.height * 0.9
            width: parent.width
            radius: 12.5
            color: "white"

            ScrollView {
                    anchors.fill: parent
                    Column {
                        spacing: 2.5
                        width: parent.width
                        padding:parent.width*0.01
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
                            height: parent.height * 0.8
                            width: parent.width *0.98
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
                                            width: parent.width * 0.98
                                            height: 200
                                            color: "green"  // Adjust the color as needed

                                            Row {
                                                width: parent.width
                                                height: parent.height
                                                Rectangle {
                                                    radius: 12.5
                                                    width: parent.height
                                                    height: parent.height
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
                                                        }
                                                    }
                                                    Button {
                                                        text: "Modify Offer"
                                                        onClicked: {
                                                            modifyOffer.open()
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
        }
        Rectangle {
            id: fridgePage
            visible: true
            y: parent.height * 0.05
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
                            id: itemTextFieldFridge
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
                    height: parent.height * 0.8
                    width: parent.width
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
                                    radius:12.5
                                    width: parent.width *0.98
                                    height: 200
                                    color: "red"
                                    Row {
                                        width:parent.width
                                        height: parent.height
                                        Rectangle {
                                            radius:12.5
                                            width:parent.height
                                            height: parent.height
                                            color:"lightblue"
                                            Label {text:"photo"}
                                        }
                                        Column {
                                            x:parent.height
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
                                                    modify.itemIndex = itemModel.getIndexByPropertyValue("index", model.index);
                                                    modify.open();
                                                    //pop_elt(itemModel.getIndexByPropertyValue("index", model.index))
                                                }
                                            }
                                            Button {
                                                text: "Remove item"
                                                onClicked: {
                                                    itemModel.remove(itemModel.getIndexByPropertyValue("index", model.index));
                                                    //pop_elt(itemModel.getIndexByPropertyValue("index", model.index))
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
                    scrollViewFridge.contentHeight -= 202.5;
                    for (var i = 0; i < count; i++) {
                        if (get(i)[propertyName] === propertyValue) {
                            return i;
                        }
                    }
                    return -1; // Return -1 if the item is not found
                }
        }
    }


    Rectangle {
        width: parent.width * 0.20
        height: parent.height
        color: "#5E9F7C"
        anchors.right: parent.right

        Button {
            y: parent.height * 0.05
            id: basket
            text: "My Basket"
        }
        Button {
            y: parent.height * 0.25
            //id: addtofridge
            text: "Add to Fridge"
            onClicked: {
                addtofridge.open()
            }
        }
        Button {
            y: parent.height * 0.75
            x: parent.width * 0.5 - 50
            id: profil
            height: 100
            width: 100
            text: "Profile"
            onClicked: {
                profile.open()
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
        id: modifyOffer
        anchors.centerIn: parent
        width: 350
        height: 370
        closePolicy: "CloseOnEscape"
        background: Rectangle {
            color: "#EEEEEE"
            radius: 12.5
        }
        property int itemIndex: -1

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
                text: itemModel.get(itemIndex).quantity
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

                        itemModel.setProperty(itemIndex, "pricestatus", priceType.currentIndex);
                        //itemModel.setProperty(itemIndex, "status", 1);
                        itemModel.setProperty(itemIndex, "quantity2sell", quantity2sellInput.text);
                        itemModel.setProperty(itemIndex, "price", priceInput.text);

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


}*/
