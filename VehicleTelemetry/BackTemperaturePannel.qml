import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    BackTemperatureIndicatorPannel { id:bTI; anchors.left: bslider.right }
    MySlider {
        sid:"bslider";
        id:bslider
        minimumValue: 15
        maximumValue: 30
        value: 15
        orientation: Qt.Vertical
        stepSize: 0.5
        onValueChanged: {
            mytext.text=bslider.value.toString()
        }

        Text{
            id:mytext
            color: "white"
        }
    }
}
