import QtQuick
import QtQuick.Controls
import QtWebSockets

Window {
    width: 720
    height: 1280
    visible: true
    title: qsTr("App")
    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent
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
