import QtQuick 2.6
import QtQuick.Controls 1.4


GroupBox {
    id:mygb
    Image {
        id: fanimage
        source: "qrc:/images/fan_icon_off.png"
    }
    VerticalIndicator { id:fs1; height:50; width:15;anchors.left: fanimage.right;indicatorColor:"#000080"}
    VerticalIndicator { id:fs2; height:50; width:15;anchors.left: fs1.right;indicatorColor:"#0000cc"}
    VerticalIndicator { id:fs3; height:50; width:15;anchors.left: fs2.right;indicatorColor:"#3333ff"}
    VerticalIndicator { id:fs4;height:50; width:15;anchors.left: fs3.right;indicatorColor:"#ccccff"}
    VerticalIndicator { id:fs5;height:50; width:15;anchors.left: fs4.right;indicatorColor:"#ffffff"}
    VerticalIndicator { id:fs6;height:50; width:15;anchors.left: fs5.right;indicatorColor:"#ff4d4d"}
    VerticalIndicator { id:fs7;height:50; width:15;anchors.left: fs6.right;indicatorColor:"#ff3333"}
    VerticalIndicator { id:fs8;height:50; width:15;anchors.left: fs7.right;indicatorColor:"#ff0000"}
    VerticalIndicator { id:fs9;height:50; width:15;anchors.left: fs8.right;indicatorColor:"red"}
    VerticalIndicator { id:fs10;height:50; width:15;anchors.left: fs9.right;indicatorColor:"#b30000"}

    Slider {
        id:horizontalslider
        signal fanSpeedSliderSignal(var value)
        objectName: "fanSpeedSlider"
        anchors.top:fs1.bottom
        anchors.left: fanimage.right
        minimumValue: 0
        maximumValue: 5
        value: 0
        stepSize: 1
        width: 200
        anchors.topMargin: 5
        anchors.bottomMargin: 150
        onValueChanged: {
                mygb.state=horizontalslider.value.toString()
                fanSpeedSliderSignal(horizontalslider.value.toString())
            }
    }

    states: [
        State {
            name: "1"
            PropertyChanges { target: fs1; state:"on" }
            PropertyChanges { target: fs2; state:"on" }
            PropertyChanges { target: fs3; state:"off" }
            PropertyChanges { target: fs4; state:"off" }
            PropertyChanges { target: fs5; state:"off" }
            PropertyChanges { target: fs6; state:"off" }
            PropertyChanges { target: fs7; state:"off" }
            PropertyChanges { target: fs8; state:"off" }
            PropertyChanges { target: fs9; state:"off" }
            PropertyChanges { target: fs10; state:"off" }
        },
        State {
            name: "2"
            PropertyChanges { target: fs1; state:"on" }
            PropertyChanges { target: fs2; state:"on" }
            PropertyChanges { target: fs3; state:"on" }
            PropertyChanges { target: fs4; state:"on" }
            PropertyChanges { target: fs5; state:"off" }
            PropertyChanges { target: fs6; state:"off" }
            PropertyChanges { target: fs7; state:"off" }
            PropertyChanges { target: fs8; state:"off" }
            PropertyChanges { target: fs9; state:"off" }
            PropertyChanges { target: fs10; state:"off" }
        },
        State {
            name: "3"
            PropertyChanges { target: fs1; state:"on" }
            PropertyChanges { target: fs2; state:"on" }
            PropertyChanges { target: fs3; state:"on" }
            PropertyChanges { target: fs4; state:"on" }
            PropertyChanges { target: fs5; state:"on" }
            PropertyChanges { target: fs6; state:"on" }
            PropertyChanges { target: fs7; state:"off" }
            PropertyChanges { target: fs8; state:"off" }
            PropertyChanges { target: fs9; state:"off" }
            PropertyChanges { target: fs10; state:"off" }
        },
        State {
            name: "4"
            PropertyChanges { target: fs1; state:"on" }
            PropertyChanges { target: fs2; state:"on" }
            PropertyChanges { target: fs3; state:"on" }
            PropertyChanges { target: fs4; state:"on" }
            PropertyChanges { target: fs5; state:"on" }
            PropertyChanges { target: fs6; state:"on" }
            PropertyChanges { target: fs7; state:"on" }
            PropertyChanges { target: fs8; state:"on" }
            PropertyChanges { target: fs9; state:"off" }
            PropertyChanges { target: fs10; state:"off" }
        },
        State {
            name: "5"
            PropertyChanges { target: fs1; state:"on" }
            PropertyChanges { target: fs2; state:"on" }
            PropertyChanges { target: fs3; state:"on" }
            PropertyChanges { target: fs4; state:"on" }
            PropertyChanges { target: fs5; state:"on" }
            PropertyChanges { target: fs6; state:"on" }
            PropertyChanges { target: fs7; state:"on" }
            PropertyChanges { target: fs8; state:"on" }
            PropertyChanges { target: fs9; state:"on" }
            PropertyChanges { target: fs10; state:"on" }
        }
    ]
}
