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

    // Control the loading screen with variable isLoading
    property bool isLoading: true;

    Loader { // Switch between Home.qml and Login.qml
        id: pageLoader
        anchors.fill: parent
        enabled: !isLoading
        source: "qml_components/Login.qml"
    }

    // Loader for the loading screen
    Loader {
        id: loadingMask
        anchors.fill: parent
        active: isLoading
        source: "qml_components/Loading.qml"

        // Intercept mouse event, not actually needed cuz we have disabled pageLoader
        MouseArea {
            anchors.fill: parent
            propagateComposedEvents: false
            onClicked: function(clickEvent){
                clickEvent.accepted = true
            }
        }
    }

    Connections {
        target: wsClient
        onLoadHomePage: function(){
            pageLoader.source = "qml_components/Home.qml"
        }
        onLoadLoginPage: function(){
            pageLoader.source = "qml_components/Login.qml"
        }
        onMountLoadingMask: function(){
            isLoading = true
        }
        onUnmountLoadingMask: function(){
            isLoading = false
        }
    }
}
