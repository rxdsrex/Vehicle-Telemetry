import QtQuick 2.6

Rectangle {
    id: recirculationButton
    width: 70
    height: 70
    color: "#282828"
    border.color: "#282828"
    border.width: 2

    property bool value: false

    Image {
        width: parent.width
        height: parent.height
        id: image
        source: "./images/fan_control_circ_" + (value ? "on" : "off") + ".png"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: value = !value
    }
}

