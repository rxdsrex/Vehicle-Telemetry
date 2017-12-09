import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    MySlider { sid:"bslider";id:bslider}
    BackTemperatureIndicatorPannel {id:bTI;anchors.left: bslider.right}
}
