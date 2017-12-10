import QtQuick 2.6

Rectangle {
    id: acButton
    objectName: "acButtonObject"
    signal acSignal(var value)
    width: 70
    height: 70
    color: "#282828"
    border.color: "#282828"
    border.width: 2

    property bool acButtonValue: false

    Image {
        width: parent.width
        height: parent.height
        id: image
        source: "./images/fan_control_ac_" + (acButtonValue ? "on" : "off") + ".png"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            acButtonValue = !acButtonValue
            acSignal(acButton.acButtonValue.toString())
        }
    }
}
