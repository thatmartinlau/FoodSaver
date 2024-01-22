import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: profilewindow
    anchors.centerIn: parent
    width: Screen.width / 2.5
    height: Screen.height / 1.5
    focus: true

    //Column containing whole page
    Column {
        width: parent.width
        spacing: 20
        padding: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:parent.top

        //TITLE
        Label {
            text: "Profile"
            leftPadding: 20
            rightPadding: 20
            font.pixelSize: 32
            color: "#1C6F30" // Dark color for the title
            horizontalAlignment: Text.AlignHCenter
        }

        Text{
            id: noNameAndTelegramError
            visible: false // Initially hidden
            text: "You need to fill in a display name and telegram username"
            color: "red"
        }


        //Separator line
        Rectangle {
            width: parent.width * 0.8
            height: 1 // Adjust the height for border thickness
            color: "#A0A0A0" // Border color
          }

        // PERSONAL DETAIL SECTION
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
            }

            Text {text: "Phone number"; color: "#28A745"}
            TextField {
                Layout.preferredWidth: 150
                id: phonenumInput
                width: parent.width
                placeholderText: "Phone number"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
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
            }

            Text {text:"Promotion"; color: "#28A745"; Layout.preferredWidth: 75}
            ComboBox {
                    id: choiceMenu
                    width: 200
                    model: ["BX2026", "BX2025", "BX2024"]
                }

            //ON LINE 3 OF GRID

            Text {text: "Telegram username"; color: "#28A745"}
            TextField {
                Layout.preferredWidth: 150
                id: telegramInput
                width: parent.width
                placeholderText: "Telegram username"
                placeholderTextColor: "#A0A0A0"
                color: "#544E3D"
            }

            Text {text: "Gender" ; color: "#28A745"; Layout.preferredWidth: 75}
            ComboBox {
                id: genderMenu
                width: 200
                model: ["Male", "Female", "Prefer not to say"]
            }
        }
        // END OF PERSONAL INFO GRID

        //Separator line
        Rectangle {
            width: parent.width * 0.8
            height: 1 // Adjust the height for border thickness
            color: "#A0A0A0" // Border color
          }

        //DIETARY RESTRICTIONS
        Label {
            text: "Food and dietary restrictions"
            color: "#1C6F30"
            font.pixelSize: 25
        }

        //All checkboxes to select food restriction
        GridLayout {
            id: dietrestrictionsgrid
            columns: 3
            width: parent.width
            columnSpacing: 5
            rowSpacing: 20

            CheckBox {
                id: glutenCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: glutenCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: glutenCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Gluten Intolerance</font>"
                        color: glutenCheck.down ? "#28A745" : "#BDBDBD"
                        font: glutenCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }

            CheckBox {
                id: lactoseCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: lactoseCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: lactoseCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Lactose Intolerance</font>"
                        color: lactoseCheck.down ? "#28A745" : "#BDBDBD"
                        font: lactoseCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }



            CheckBox {
                id: nutsCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: nutsCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: nutsCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Nut allergy</font>"
                        color: nutsCheck.down ? "#28A745" : "#BDBDBD"
                        font: nutsCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }

            CheckBox {
                id: veganCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: veganCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: veganCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Vegan</font>"
                        color: veganCheck.down ? "#28A745" : "#BDBDBD"
                        font: veganCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }

            CheckBox {
                id: vegetarianCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: vegetarianCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: vegetarianCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Vegetarian</font>"
                        color: vegetarianCheck.down ? "#28A745" : "#BDBDBD"
                        font: vegetarianCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }

            CheckBox {
                id: pescatarianCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: pescatarianCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: pescatarianCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Pescatarian</font>"
                        color: pescatarianCheck.down ? "#28A745" : "#BDBDBD"
                        font: pescatarianCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }

            CheckBox {
                id: halalCheck
                RowLayout {
                    spacing: 10
                    Rectangle {
                        width: 26
                        height: 26
                        radius: 6
                        border.color: halalCheck.down ? "#E0E0E0" : "#BDBDBD"
                        border.width: 2
                        color: halalCheck.checked ? "green" : "white"
                    }
                    Text {
                        text: "<font color=\"#28A745\">Halal</font>"
                        color: halalCheck.down ? "#28A745" : "#BDBDBD"
                        font: halalCheck.font
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                    }
                }
            }
        }

        //Separator line
        Rectangle {
            width: parent.width * 0.8
            height: 1 // Adjust the height for border thickness
            color: "#A0A0A0" // Border color
          }

        Rectangle {
            id: customButton
            width: 60
            height: 20
            color: "#1C6F30"
            radius: 4

            Text {
                text: "Next"
                color: "white"
                anchors.centerIn: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    // Extracting values from UI components
                            var displayName = displaynametext.text;
                            var gender = genderMenu.currentText;
                            var address = buildingaddressinput.text;
                            var promotion = choiceMenu.currentText;
                            var phone = phonenumInput.text;
                            var telegram = telegramInput.text;

                            // Extracting checkbox states
                            var gluten = !(glutenCheck.checked);
                            var lactose = !lactoseCheck.checked;
                            var meat = !(pescatarianCheck.checked || vegetarianCheck.checked || vegetarianCheck.checked || halalCheck.checked);
                            var halal_meat = !(pescatarianCheck.checked || vegetarianCheck.checked || vegetarianCheck.checked);
                            var fish = !(pescatarianCheck.checked || vegetarianCheck.checked || veganCheck.checked);
                            var nuts = !nutsCheck.checked;
                            var eggs = !veganCheck.checked;

                            // Calling the setUserInfo function
                            signinInfo.setUserInfo(displayName, gender, address, promotion, phone,
                                                   telegram, gluten, lactose, meat, halal_meat, fish, nuts, eggs)
                }
            }
        }

        Connections {
            target: signinInfo

            function onOpenMarketPage() {
                stackView.push(Qt.resolvedUrl("Market.qml"))
            }
            function onOpenPreviousPage() {
                stackView.push(Qt.resolvedUrl("SigninPage.qml"))
            }
            function onOpenNameAndTelegramError() {
                noNameAndTelegramError.visible = true;
            }

            function onCloseNameAndTelegramError() {
                noNameAndTelegramError.visible = false;
            }
        }
    }
}


