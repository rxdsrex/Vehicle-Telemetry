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
       CentralPannel{}
       BackTemperaturePannel {id:b1}
       TemperatureButton{direction: "front"}
       Filler{}
       TemperatureButton{direction: "rear"}

       Filler{}
       Filler{}
       Filler{}
       MyDial{id:dial1;direction: "left"}
       ButtonPannel{}
       MyDial {id:dial2;direction: "right"}
}

   }

