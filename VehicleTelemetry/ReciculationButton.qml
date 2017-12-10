import QtQuick 2.6

Rectangle {
    id: recirculationButton
    objectName: "rcButtonObject"
    signal rcSignal(var value)
    width: 70
    height: 70
    color: "#282828"
    border.color: "#282828"
    border.width: 2

    property bool rcButtonValue: false

    Image {
        width: parent.width
        height: parent.height
        id: image
        source: "./images/fan_control_circ_" + (rcButtonValue ? "on" : "off") + ".png"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            rcButtonValue = !rcButtonValue
            rcSignal(recirculationButton.rcButtonValue.toString())
        }
    }
}

