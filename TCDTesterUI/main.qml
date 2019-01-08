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
                model: ListModel{
                    ListElement {test: "123"}
                }
                onPressedChanged: {
                    if (!comboBoxSenser01.pressed)
                    {
                        UserModule.getSenser1List();
                    }

                }
            }

            Button {
                id: buttonOpenSenser01
                text: "Open"
                font.pointSize: 22
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: comboBoxSenser01.right
                anchors.leftMargin: 10
                onReleased: {

                }
            }

            Text {
                id: textSenser01ValueName
                text: qsTr("Value:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: buttonOpenSenser01.right
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser01ValueShow
                text: qsTr("0")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: textSenser01ValueName.right
                anchors.leftMargin: 10
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
                text: qsTr("0")
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
                text: qsTr("0")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser01CostMaxTime.right
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

            }

            Button {
                id: buttonOpenSenser02
                text: "Open"
                font.pointSize: 22
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: comboBoxSenser02.right
                anchors.leftMargin: 10
            }

            Text {
                id: textSenser02ValueName
                text: qsTr("Value:")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: buttonOpenSenser02.right
                anchors.leftMargin: 100
            }

            Text {
                id: textSenser02ValueShow
                text: qsTr("0")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * -0.3
                anchors.left: textSenser02ValueName.right
                anchors.leftMargin: 10
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
                text: qsTr("0")
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
                text: qsTr("0")
                font.pointSize: 22
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: parent.height * 0.3
                anchors.left: textSenser02CostMaxTime.right
                anchors.leftMargin: 10
            }
        }
    }
}
