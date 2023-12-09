import QtQuick
import QtQuick.Controls
import QtWebSockets
import app.foodsaver 0.1
import "qml_components" // Importing all qml files under qml_components/

Window {
    width: 720
    height: 1280
    visible: true
    title: qsTr("App")

    Loader { // Switch between Home.qml and Login.qml
        id: pageLoader
        anchors.fill: parent
        source: "qml_components/Login.qml"
    }

    Connections {
        target: wsClient
        onLoadHomePage: {
            pageLoader.source = "qml_components/Home.qml"
        }
        onLoadLoginPage: {
            pageLoader.source = "qml_components/Login.qml"
        }
    }
}
