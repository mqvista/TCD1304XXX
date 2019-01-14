import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        anchors.topMargin: 50
        anchors.fill: parent
        anchors.margins: 8
        spacing: 20

        GroupBox {
            id: groupBoxSenser01
            width: parent.width
            height: parent.height * 0.45
            title: qsTr("Senser 1")

            Text {
                id: deviceNameSenser01
                text: qsTr("Device:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
            }

            ComboBox {
                id: comboBoxSenser01
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: deviceNameSenser01.right
                anchors.leftMargin: 10
                model: UserInterfaceModule.senser01List
                onPressedChanged: {
                    if (!comboBoxSenser01.pressed)
                    {
                        UserInterfaceModule.getSenser01List();
                    }

                }
            }

            Button {
                id: buttonOpenSenser01
                objectName: "buttonOpenSenser01"
                text: "Open"
                font.pointSize: 22
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: comboBoxSenser01.right
                anchors.leftMargin: 10
                onReleased: {
                    if (comboBoxSenser01.currentText != "" && buttonOpenSenser01.text == "Open")
                    {
                        console.log(comboBoxSenser01.currentIndex)
                        UserInterfaceModule.openSenser01(comboBoxSenser01.currentIndex);
                    }
                    else if (buttonOpenSenser01.text == "Close")
                    {
                        UserInterfaceModule.closeSenser01();
                    }
                }
            }

            Text {
                id: intergralTimeSenser01
                text: qsTr("Intergral:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: buttonOpenSenser01.right
                anchors.leftMargin: 40
            }

            SpinBox {
                id: spinBoxSenser01
                value: 1
                font.pointSize: 22
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: intergralTimeSenser01.right
                anchors.leftMargin: 10
                onValueChanged: {
                    UserInterfaceModule.setSenser01Intergral(spinBoxSenser01.value)
                }

            }

            Text {
                id: textSenser01CostTime
                text: qsTr("CostTime:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
            }

            Text {
                id: textSenser01CostTimeValue
                text: UserInterfaceModule.senser01CostTime + "ms"
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser01CostTime.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser01CostMaxTime
                text: qsTr("CostMaxTime:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser01CostTime.right
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser01CostMaxTimeValue
                text: UserInterfaceModule.senser01MaxCostTime + "ms"
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser01CostMaxTime.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser01ValueName
                text: qsTr("Value:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser01CostMaxTime.right
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser01ValueShow
                text: UserInterfaceModule.senser01PixelLength
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser01ValueName.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser01CostTimesName
                text: qsTr("ErrorTimes:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser01CostTimesValue
                text: UserInterfaceModule.senser01ErrorTimes
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: textSenser01CostTimesName.right
                anchors.leftMargin: 10
            }

        }

        GroupBox {
            id: groupBoxSenser02
            width: parent.width
            height: parent.height * 0.45
            title: qsTr("Senser 2")

            Text {
                id: deviceNameSenser02
                text: qsTr("Device:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
            }

            ComboBox {
                id: comboBoxSenser02
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: deviceNameSenser02.right
                anchors.leftMargin: 10
                model: UserInterfaceModule.senser02List
                onPressedChanged: {
                    if (!comboBoxSenser02.pressed)
                    {
                        UserInterfaceModule.getSenser02List();
                    }
                    if (comboBoxSenser02.pressed)
                    {
                        if (comboBoxSenser01.currentIndex == comboBoxSenser02.currentIndex)
                        {
                            comboBoxSenser02.currentIndex = -1
                        }
                    }

                }

            }

            Button {
                id: buttonOpenSenser02
                objectName: "buttonOpenSenser02"
                text: "Open"
                font.pointSize: 22
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: comboBoxSenser02.right
                anchors.leftMargin: 10
                onReleased: {
                    if (comboBoxSenser02.currentText != "" && buttonOpenSenser02.text == "Open")
                    {
                        console.log(comboBoxSenser02.currentIndex)
                        UserInterfaceModule.openSenser02(comboBoxSenser02.currentIndex);
                    }
                    else if (buttonOpenSenser02.text == "Close")
                    {
                        UserInterfaceModule.closeSenser02()
                    }
                }
            }

            Text {
                id: intergralTimeSenser02
                text: qsTr("Intergral:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: buttonOpenSenser02.right
                anchors.leftMargin: 40
            }

            SpinBox {
                id: spinBoxSenser02
                value: 1
                font.pointSize: 22
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: intergralTimeSenser02.right
                anchors.leftMargin: 10
                onValueChanged: {
                    UserInterfaceModule.setSenser02Intergral(spinBoxSenser01.value)
                }

            }



            Text {
                id: textSenser02CostTime
                text: qsTr("CostTime:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
            }

            Text {
                id: textSenser02CostTimeValue
                text: UserInterfaceModule.senser02CostTime + "ms"
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser02CostTime.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser02CostMaxTime
                text: qsTr("CostMaxTime:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser02CostTime.right
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser02CostMaxTimeValue
                text: UserInterfaceModule.senser02MaxCostTime + "ms"
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser02CostMaxTime.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser02ValueName
                text: qsTr("Value:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser02CostMaxTime.right
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser02ValueShow
                text: UserInterfaceModule.senser02PixelLength
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser02ValueName.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser02CostTimesName
                text: qsTr("ErrorTimes:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser02CostTimesValue
                text: UserInterfaceModule.senser02ErrorTimes
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: textSenser02CostTimesName.right
                anchors.leftMargin: 10
            }
        }
    }
}









/*##^## Designer {
    D{i:159;invisible:true}D{i:160;invisible:true}D{i:161;invisible:true}D{i:162;invisible:true}
D{i:163;invisible:true}
}
 ##^##*/
