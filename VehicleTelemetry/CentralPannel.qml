import QtQuick 2.6
import QtQuick.Layouts 1.3

ColumnLayout{
    AmbientTempDisplay{anchors.bottomMargin: 120; objectName: "ambientDisplay"}
    FanSpeedIndicator{objectName: "fanSpeedIndicator"}
}
