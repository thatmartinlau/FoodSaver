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
        id: grid1
        columns: 2
        width: parent.width
        columnSpacing: 20
        rowSpacing: 10
        height: parent.height*0.1333333333

        //ON LINE 1 OF GRID
        //Text {text: "Recipe Name"; color: "#28A745"; Layout.preferredWidth: 75}

        Button {
            text: "Add also to my cookbook"
            width: 250
            palette.buttonText: "white"
            //anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                        color: "#1C6F30"
                        radius:12.5
            }
            onClicked: {
                var temp = MainController.getTitleForVis()[0];
                text = temp;
            }
        }

        Text {text: MainController.getTitleForVis()[0]; color: "blue"; Layout.preferredWidth: 75}



        //ON LINE 2 OF GRID
        Text {text: "Dietary Restriction"; color: "#28A745"; Layout.preferredWidth: 125}

        Text {text: "Dietary Restriction"; color: "blue"; Layout.preferredWidth: 125}
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

        Text {text: "Total time"; color: "blue"; Layout.preferredWidth: 65}
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


    Rectangle{
        //anchors.top: parent.top
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
                                padding: 5
                                id: ingr
                                width: parent.width*0.64
                                anchors.left: parent.left
                                height: 30
                                placeholderTextColor: "#A0A0A0"
                                //anchors.horizontalCenter: parent.horizontalCenter
                                background: Rectangle {
                                        color: "#D9E8FF"
                                        radius: 20
                                    }
                                placeholderText: model.name
                            }
                            TextField {
                                padding: 5
                                id: quant
                                width: parent.width*0.34
                                anchors.right: parent.right
                                height: 30
                                placeholderTextColor: "#A0A0A0"
                                //anchors.horizontalCenter: parent.horizontalCenter
                                background: Rectangle {
                                        color: "#D9E8FF"
                                        radius: 20
                                    }
                                placeholderText: "Quantity"
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
        columns: 1
        width: parent.width
        columnSpacing: 20
        rowSpacing: 10
        y: parent.height*0.505
        //anchors.bottom: parent.bottom

        //ON LINE 1 OF GRID
        Text {text: "Instructions"; color: "#28A745"; Layout.preferredWidth: 150}
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
                                padding: 5
                                id: instr
                                width: parent.width
                                height: 30
                                anchors.horizontalCenter: parent.horizontalCenter
                                placeholderTextColor: "#A0A0A0"
                                background: Rectangle {
                                        color: "#D9E8FF"
                                        radius: 20
                                    }
                                placeholderText: "1: "+ model.name
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
}
