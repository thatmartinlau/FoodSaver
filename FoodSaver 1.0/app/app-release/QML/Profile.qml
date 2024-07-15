import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3


//MENU FOR THE PREFERENCES MENU
//Shall include the following features:
//Ability to change what their food diets and allergies are
//Ability to change their display name and 103 address
//Ability to add a photo, potentially (future update)

//Future update: make the window load the user's settings when open initially

Popup {
    id: profilewindow
    anchors.centerIn: parent
    width: Screen.width / 2.5
    height: Screen.height / 1.5
    focus: true
    closePolicy: Popup.CloseOnEscape
    modal: true

    background: Rectangle {
        color: "#F0F0F0" // Light grey background
        radius: 12.5
        border.color: "#CCCCCC" // Light border color
        border.width: 1
    }

    //Column containing all the settings options
    Column {
        width: parent.width
        spacing: 20
        padding: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:parent.top

        //Title bar
        Label {
            text: "Profile"
            leftPadding: 20
            rightPadding: 20
            font.pixelSize: 32
            color: "#1C6F30" // Dark color for the title
            horizontalAlignment: Text.AlignHCenter
        }

        //Separator line
        Rectangle {
                  width: parent.width * 0.8
                  height: 1 // Adjust the height for border thickness
                  color: "#A0A0A0" // Border color
          }

        Label {
            text: "Personal details"
            color: "#1C6F30"
            font.pixelSize: 25
        }

        GridLayout {
            id: personalinfo
            columns: 4
            width: parent.width
            columnSpacing: 5
            rowSpacing: 20

            //ON LINE 1 OF GRID
            Text {text: "Display name"; color: "#28A745"; Layout.preferredWidth: 75}
            TextField {
                Layout.preferredWidth: 150
                id: displaynametext
                width: parent.width
                placeholderText: "Name                  "
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
                }
            }

            Text {text: "Gender" ; color: "#28A745"; Layout.preferredWidth: 75}
            ComboBox {
                    id: genderMenu
                    width: 200
                    model: ["Male", "Female", "Prefer not to say"]

                    onCurrentIndexChanged: {
                        //console.log("Selected option:", model[currentIndex]);
                    }
                }


            //ON LINE 2 OF GRID
            Text { text: "Building address"; color: "#28A745"; Layout.preferredWidth: 75}
            TextField {
                Layout.preferredWidth: 150
                id: buildingaddressinput
                width: parent.width
                placeholderText: "103 room number"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
                }
            }

            Text {text:"Promotion"; color: "#28A745"; Layout.preferredWidth: 75}
            ComboBox {
                    id: choiceMenu
                    width: 200
                    model: ["BX2026", "BX2025", "BX2024"]

                    onCurrentIndexChanged: {
                        //console.log("Selected option:", model[currentIndex]);
                    }
                }

            //ON LINE 3 OF GRID
            Text {text: "Phone number"; color: "#28A745"}
            TextField {
                Layout.preferredWidth: 150
                id: phonenumInput
                width: parent.width
                placeholderText: "Phone number"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
                background: Rectangle {
                    color: "#D9E8FF" // Light blue for text field
                    radius: 8
                }
            }




        }

        //Separator line
        Rectangle {
                  width: parent.width * 0.8
                  height: 1 // Adjust the height for border thickness
                  color: "#A0A0A0" // Border color
          }

        Label {
            text: "Food and dietary restrictions"
            color: "#1C6F30"
            font.pixelSize: 25
        }


        GridLayout {
            id: dietrestrictionsgrid
            columns: 3
            width: parent.width
            columnSpacing: 5
            rowSpacing: 20

            CheckBox {
                id: vegetarianCheck
                text: "<font color=\"#28A745\">Vegetarian</font>"

                // Customizing the indicator
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: vegetarianCheck.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 26
                    height: 26
                    radius: 6
                    border.color: vegetarianCheck.down ? "#E0E0E0" : "#BDBDBD"
                    border.width: 2
                    color: "white"

                    Rectangle {
                        visible: vegetarianCheck.checked
                        anchors.fill: parent
                        anchors.margins: 6
                        color: "green"
                    }
                }
            }

            CheckBox {
                id: veganCheck
                text: "<font color=\"#28A745\">Vegan diet</font>"

                // Customizing the indicator
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: veganCheck.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 26
                    height: 26
                    radius: 6
                    border.color: veganCheck.down ? "#E0E0E0" : "#BDBDBD"
                    border.width: 2
                    color: "white"

                    Rectangle {
                        visible: veganCheck.checked
                        anchors.fill: parent
                        anchors.margins: 6
                        color: "green"
                    }
                }
            }

            CheckBox {
                id: glutenCheck
                text: "<font color=\"#28A745\">Gluten allergy</font>"

                // Customizing the indicator
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: glutenCheck.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 26
                    height: 26
                    radius: 6
                    border.color: glutenCheck.down ? "#E0E0E0" : "#BDBDBD"
                    border.width: 2
                    color: "white"

                    Rectangle {
                        visible: glutenCheck.checked
                        anchors.fill: parent
                        anchors.margins: 6
                        color: "green"
                    }
                }
            }

            CheckBox {
                id: lactoseCheck
                text: "<font color=\"#28A745\">Lactose intolerant</font>"

                // Customizing the indicator
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: lactoseCheck.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 26
                    height: 26
                    radius: 6
                    border.color: lactoseCheck.down ? "#E0E0E0" : "#BDBDBD"
                    border.width: 2
                    color: "white"

                    Rectangle {
                        visible: lactoseCheck.checked
                        anchors.fill: parent
                        anchors.margins: 6
                        color: "green"
                    }
                }
            }

            CheckBox {
                id: pescatarianCheck
                text: "<font color=\"#28A745\">Pescatarian</font>"

                // Customizing the indicator
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: pescatarianCheck.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 26
                    height: 26
                    radius: 6
                    border.color: pescatarianCheck.down ? "#E0E0E0" : "#BDBDBD"
                    border.width: 2
                    color: "white"

                    Rectangle {
                        visible: pescatarianCheck.checked
                        anchors.fill: parent
                        anchors.margins: 6
                        color: "green"
                    }
                }
            }

            CheckBox {
                id: halalCheck
                text: "<font color=\"#28A745\">Halal</font>"

                // Customizing the indicator
                indicator: Rectangle {
                    implicitWidth: 26
                    implicitHeight: 26
                    x: halalCheck.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 26
                    height: 26
                    radius: 6
                    border.color: halalCheck.down ? "#E0E0E0" : "#BDBDBD"
                    border.width: 2
                    color: "white"

                    Rectangle {
                        visible: halalCheck.checked
                        anchors.fill: parent
                        anchors.margins: 6
                        color: "green"
                    }
                }
            }

        }


    }

    //Bottom buttons
    Row {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Button {
            text: "Cancel"
            background: Rectangle {
                color: "#6C757D" // Grey for neutral/cancel actions
                radius: 8
            }
            onClicked: {
                    displaynametext.text = ""
                    buildingaddressinput.text = ""
                    phonenumInput.text = ""
                    genderMenu.currentIndex = -1
                    choiceMenu.currentIndex = -1
                    vegetarianCheck.checked = false
                    veganCheck.checked = false
                    glutenCheck.checked = false
                    lactoseCheck.checked = false
                    pescatarianCheck.checked = false
                    halalCheck.checked = false
                    profilewindow.close()
                }
        }

        Button {
            text: "Apply"
            background: Rectangle {
                color: "#28A745" // Blue for apply/confirm actions
                radius: 8
            }
            onClicked: {
                    profileManager.applyChanges(displaynametext.text, genderMenu.currentText, buildingaddressinput.text,
                                                choiceMenu.currentText, phonenumInput.text, vegetarianCheck.checked,
                                                veganCheck.checked, glutenCheck.checked, lactoseCheck.checked,
                                                pescatarianCheck.checked, halalCheck.checked)
                    profilewindow.close()
                }
        }
    }

}


