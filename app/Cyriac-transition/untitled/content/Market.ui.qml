

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 2.15
import untitled 1.0
import FlowView 1.0

FlowView {
    width: Constants.width
    height: Constants.height
    property alias flowActionArea1: flowActionArea1
    property alias fridge1: fridge1
    property alias flowActionArea: flowActionArea
    property alias buyerpage1: buyerpage1
    flowTransitions: [
        FlowTransition {
            id: flowTransition
            to: buyerpage1
            from: fridge1
        },
        FlowTransition {
            id: flowTransition1
            to: fridge1
            from: buyerpage1
        }
    ]

    defaultTransition: FlowTransition {
        id: defaultTransition
    }

    EventListSimulator {
        id: eventListSimulator
        active: false
    }

    Buyerpage {
        id: buyerpage
    }

    Fridge {
        id: fridge
    }

    Buyerpage {
        id: buyerpage1
        forceActive: true

        FlowActionArea {
            id: flowActionArea
            target: flowTransition1
            x: 325
            y: 226
            width: 136
            height: 91
            eventType: 1
            goBack: true
        }
    }

    Fridge {
        id: fridge1
        forceActive: true

        FlowActionArea {
            id: flowActionArea1
            target: flowTransition
            x: 331
            y: 276
            width: 139
            height: 77
            eventType: 1
        }
    }
}

/*##^##
Designer {
    D{i:0}D{i:7;flowX:4312.387699173736;flowY:5026}D{i:9;flowX:4927.4082005508435;flowY:4406.728475296542}
}
##^##*/

