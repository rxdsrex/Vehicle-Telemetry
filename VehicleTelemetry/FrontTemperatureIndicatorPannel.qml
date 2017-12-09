import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    id:frontTemperatureIndicatorPannel
    VerticalIndicator { id:vi1}
    VerticalIndicator { id:vi2;anchors.top:vi1.bottom}
    VerticalIndicator { id:vi3;anchors.top:vi2.bottom}
    VerticalIndicator { id:vi4;anchors.top:vi3.bottom}
    VerticalIndicator { id:vi5;anchors.top:vi4.bottom}
    VerticalIndicator { id:vi6;anchors.top:vi5.bottom}
    VerticalIndicator { id:vi7;anchors.top:vi6.bottom}
    VerticalIndicator { id:vi8;anchors.top:vi7.bottom}
    VerticalIndicator { id:vi9;anchors.top:vi8.bottom}
    VerticalIndicator { id:vi10;anchors.top:vi9.bottom}
}

