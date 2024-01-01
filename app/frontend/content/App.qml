// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.2
import frontend

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Counter Example"

    // Include the logic from counterhandler.qml
    CounterHandler {
        id: counterHandler
    }

    // Column layout to arrange items vertically
    ColumnLayout {
        anchors.centerIn: parent

        // Button connected to the logic in CounterHandler
        Button {
            text: "Increment Counter"
            onClicked: counterHandler.incrementCounter()
        }

        // Text item to display the counter value
        Text {
            text: "Counter Value: " + counterHandler.counter
            font.pointSize: 16
        }
    }
}
