import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("HVAC Dashboard")

    MainForm {
        color:"#060606"
        anchors.fill: parent

        Text {
            text: qsTr("Hello World")
            color:"white";
            anchors.centerIn: parent
        }
    }
}
