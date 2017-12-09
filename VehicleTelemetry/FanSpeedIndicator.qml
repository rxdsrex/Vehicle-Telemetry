import QtQuick 2.6
import QtQuick.Controls 1.4


GroupBox {
    id:frontTemperatureIndicatorPannel
    Image {
        id: fanimage
        source: "qrc:/images/fan_icon_off.png"
    }
    VerticalIndicator { id:fs1; height:50; width:15;anchors.left: fanimage.right}
    VerticalIndicator { id:fs2; height:50; width:15;anchors.left: fs1.right}
    VerticalIndicator { id:fs3; height:50; width:15;anchors.left: fs2.right}
    VerticalIndicator { id:fs4;height:50; width:15;anchors.left: fs3.right}
    VerticalIndicator { id:fs5;height:50; width:15;anchors.left: fs4.right}
    VerticalIndicator { id:fs6;height:50; width:15;anchors.left: fs5.right}
    VerticalIndicator { id:fs7;height:50; width:15;anchors.left: fs6.right}
    VerticalIndicator { id:fs8;height:50; width:15;anchors.left: fs7.right}
    VerticalIndicator { id:fs9;height:50; width:15;anchors.left: fs8.right}
    VerticalIndicator { id:fs10;height:50; width:15;anchors.left: fs9.right}

    Slider {
        id:horizontalslider
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
                mytext.text=horizontalslider.value.toString()
            }

            Text{
                id:mytext
                color: "white"
            }
    }
}
