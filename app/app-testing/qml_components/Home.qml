import QtQuick
import QtQuick.Controls
import QtWebSockets
import app.foodsaver 0.1

Item {

    // Test for instantiating Test Class in QML, now commented
    Test {
        id: testClass
    }

    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent
        Item {
            Button {
                id: btn
                text: "TRY"
                onClicked: {
                    testClass.clickTest();
                }
                anchors.fill: parent
            }
        }
        Fridge {
            id: fridgeView
        }
        Share {
            id: shareView
        }
        Account {
            id: accountView
        }
    }

    TabBar {
        id: menuTab
        width: parent.width

        currentIndex: view.currentIndex

        anchors.bottom: parent.bottom

        TabButton {
            id: fridgeTabbtn
            text: qsTr("Fridge")
        }
        TabButton {
            id: shareTabbtn
            text: qsTr("Share")
        }
        TabButton {
            id: accountTabbtn
            text: qsTr("Account")
        }

        onCurrentIndexChanged: {
            print("menuTab currentIndex change to ", currentIndex)
            view.setCurrentIndex(currentIndex)
        }
    }
}
