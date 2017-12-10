import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4

Rectangle {
    property string direction: "left"
    height: 100
    width: 100
    radius: 50
    color: "transparent"
    Text {
        id: mytext
        color: "red"
    }

    Dial {
        id:dial1
        signal leftDialSignal(var value)
        objectName: "leftHeatDial"
        from:0
        to:3
        stepSize: 1
        snapMode: Dial.SnapAlways
        height: 100
        width: 100
        background: Rectangle {
            color:"#B3D9E4"
            anchors.fill:parent
            radius: parent.width / 2
            Image {
                id: logo
                source: "qrc:/images/" + direction + "_heat.png"
                anchors.fill:parent
            }
        }
        onMoved: {
            mytext.text=dial1.value.toString()
            leftDialSignal(dial1.value.toString())
        }
    }
}
