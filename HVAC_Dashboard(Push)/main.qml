import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 600
    height: 550

    Image {
        id: background
        source: "qrc:/images/background.jpg"
    }

    title: qsTr("HVAC Dashboard")

    GridLayout {
        id:gridLayout
        width: 500
        rows:3
        columns:3
        anchors.horizontalCenter: parent.horizontalCenter

        Filler{}
        Filler{}
        Filler{}

        FrontTemperaturePannel {id:f1; objectName: "frontPanel"}
        CentralPannel{objectName: "centralPanel"}
        BackTemperaturePannel {id:b1; objectName: "backPanel"}
        TemperatureButton{direction: "front"}
        Filler{}
        TemperatureButton{direction: "rear"}

        Filler{}
        Filler{}
        Filler{}

        LeftDial{id:dial1; objectName: "leftDial"}
        ButtonPannel{objectName: "buttonPanel"}
        RightDial{id:dial2; objectName: "rightDial";}
    }
}
