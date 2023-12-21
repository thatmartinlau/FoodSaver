import QtQuick 2.15
import QtQuick.Controls
Item {
    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: fridgeModel

            delegate: Item { // Template for each food item

                height: 160

                Row {
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 20
                    Text {
                        text: "UID: " + uid
                    }
                    Text {
                        text: "Food: " + name
                    }
                }
            }
        }

        ListModel {
            id: fridgeModel
            Component.onCompleted: wsClient.requestUpdateFridge();
        }

        Connections {
            target: wsClient
            function onUpdateFridgeModel(data){
                console.log("QML Fridge: onUpdateFridge()")
                fridgeModel.clear() // Clear existing food items
                for(var i=0;i<data.length;i++){
                    fridgeModel.append({"uid":data[i][0], "name":data[i][2]})
                }
            }
        }
    }
}
