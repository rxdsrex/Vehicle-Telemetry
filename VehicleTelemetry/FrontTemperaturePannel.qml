import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    id: mygb
    FrontTemperatureIndicatorPannel {
        id:fTI
        VerticalIndicator { id:vi1;indicatorColor:"#b30000"}
        VerticalIndicator { id:vi2;anchors.top:vi1.bottom;indicatorColor:"red"}
        VerticalIndicator { id:vi3;anchors.top:vi2.bottom;indicatorColor:"#ff0000"}
        VerticalIndicator { id:vi4;anchors.top:vi3.bottom;indicatorColor:"#ff3333"}
        VerticalIndicator { id:vi5;anchors.top:vi4.bottom;indicatorColor:"#ff4d4d"}
        VerticalIndicator { id:vi6;anchors.top:vi5.bottom;indicatorColor:"#ffffff"}
        VerticalIndicator { id:vi7;anchors.top:vi6.bottom;indicatorColor:"#ccccff"}
        VerticalIndicator { id:vi8;anchors.top:vi7.bottom;indicatorColor:"#3333ff"}
        VerticalIndicator { id:vi9;anchors.top:vi8.bottom;indicatorColor:"#0000cc"}
        VerticalIndicator { id:vi10;anchors.top:vi9.bottom;indicatorColor:"#000080"}
    }
    MySlider {
        id:slider1;
        anchors.left: fTI.right;
        minimumValue: 15
        maximumValue: 30
        value: 15
        orientation: Qt.Vertical
        stepSize: 0.5
        onValueChanged: {
            mygb.state = slider1.value.toString()
        }
    }
    states: [
        State {
            name: "15"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"off" }
            PropertyChanges { target: vi6; state:"off" }
            PropertyChanges { target: vi7; state:"off" }
            PropertyChanges { target: vi8; state:"off" }
            PropertyChanges { target: vi9; state:"off" }
            PropertyChanges { target: vi10; state:"off" }
        },
        State {
            name: "16.5"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"off" }
            PropertyChanges { target: vi6; state:"off" }
            PropertyChanges { target: vi7; state:"off" }
            PropertyChanges { target: vi8; state:"off" }
            PropertyChanges { target: vi9; state:"off" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "18"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"off" }
            PropertyChanges { target: vi6; state:"off" }
            PropertyChanges { target: vi7; state:"off" }
            PropertyChanges { target: vi8; state:"off" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "19.5"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"off" }
            PropertyChanges { target: vi6; state:"off" }
            PropertyChanges { target: vi7; state:"off" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "21"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"off" }
            PropertyChanges { target: vi6; state:"off" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "22.5"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"off" }
            PropertyChanges { target: vi6; state:"on" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "24"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"off" }
            PropertyChanges { target: vi5; state:"on" }
            PropertyChanges { target: vi6; state:"on" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "25.5"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"off" }
            PropertyChanges { target: vi4; state:"on" }
            PropertyChanges { target: vi5; state:"on" }
            PropertyChanges { target: vi6; state:"on" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "27"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"off" }
            PropertyChanges { target: vi3; state:"on" }
            PropertyChanges { target: vi4; state:"on" }
            PropertyChanges { target: vi5; state:"on" }
            PropertyChanges { target: vi6; state:"on" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "28.5"
            PropertyChanges { target: vi1; state:"off" }
            PropertyChanges { target: vi2; state:"on" }
            PropertyChanges { target: vi3; state:"on" }
            PropertyChanges { target: vi4; state:"on" }
            PropertyChanges { target: vi5; state:"on" }
            PropertyChanges { target: vi6; state:"on" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        },
        State {
            name: "30"
            PropertyChanges { target: vi1; state:"on" }
            PropertyChanges { target: vi2; state:"on" }
            PropertyChanges { target: vi3; state:"on" }
            PropertyChanges { target: vi4; state:"on" }
            PropertyChanges { target: vi5; state:"on" }
            PropertyChanges { target: vi6; state:"on" }
            PropertyChanges { target: vi7; state:"on" }
            PropertyChanges { target: vi8; state:"on" }
            PropertyChanges { target: vi9; state:"on" }
            PropertyChanges { target: vi10; state:"on" }
        }
    ]
}
