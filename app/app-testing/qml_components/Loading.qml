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
        width: 200
        height: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        x: parent.width * 0.618 - width / 2
        y: 0.764 * parent.height - height / 2
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
        function onMountLoadingMask(text) {
            loadingLabel.text = text
        }
    }
}
