.pragma library

function navigateTo(page) {
    stackView.replace(Qt.resolvedUrl(page + ".qml"));
}

function generateRandomIndex() {
        return Math.floor(Math.random() * 10);
    }
