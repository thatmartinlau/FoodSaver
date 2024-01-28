.pragma library

function navigateTo(page) {
    stackView.replace(Qt.resolvedUrl(page + ".qml"));
}
