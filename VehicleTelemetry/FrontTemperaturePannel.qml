import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    FrontTemperatureIndicatorPannel {id:fTI}
    MySlider { sid:"slider1"; anchors.left: fTI.right}
}
