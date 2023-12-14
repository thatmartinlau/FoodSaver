import QtQuick 2.15
import QtQuick.Controls

Item {
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: "#30000000" // alpha 80 black
    }

    AnimatedImage {
        id: loadingGif
        width: 100
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: 0.764 * parent.verticalCenter
        x: parent.width * 0.618 - width / 2
        y: parent.height * 0.618 - height / 2
        source: "../assets/loading.gif"
    }

    Label {
        id: loadingLabel
        text: "App is starting up..."
        font.pixelSize: 20
        anchors.top: loadingGif.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Connections {
        target: wsClient
        onMountLoadingMask: function(text) {
            loadingLabel.text = text
        }
    }
}