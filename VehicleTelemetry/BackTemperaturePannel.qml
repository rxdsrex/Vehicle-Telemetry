import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    id:mygb
    BackTemperatureIndicatorPannel {
        id:bTI
        anchors.left: bslider.right

        VerticalIndicator { id:vi11;indicatorColor:"#b30000"}
        VerticalIndicator { id:vi12;anchors.top:vi11.bottom;indicatorColor:"red"}
        VerticalIndicator { id:vi13;anchors.top:vi12.bottom;indicatorColor:"#ff0000"}
        VerticalIndicator { id:vi14;anchors.top:vi13.bottom;indicatorColor:"#ff3333"}
        VerticalIndicator { id:vi15;anchors.top:vi14.bottom;indicatorColor:"#ff4d4d"}
        VerticalIndicator { id:vi16;anchors.top:vi15.bottom;indicatorColor:"#ffffff"}
        VerticalIndicator { id:vi17;anchors.top:vi16.bottom;indicatorColor:"#ccccff"}
        VerticalIndicator { id:vi18;anchors.top:vi17.bottom;indicatorColor:"#3333ff"}
        VerticalIndicator { id:vi19;anchors.top:vi18.bottom;indicatorColor:"#0000cc"}
        VerticalIndicator { id:vi20;anchors.top:vi19.bottom;indicatorColor:"#000080"}
    }
    MySlider {
        sid:"bslider";
        id:bslider
        minimumValue: 15
        maximumValue: 30
        value: 15
        orientation: Qt.Vertical
        stepSize: 1.5
        onValueChanged: {
            mygb.state = bslider.value.toString()
        }   
    }

    states: [
        State {
            name: "15"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"off" }
            PropertyChanges { target: vi16; state:"off" }
            PropertyChanges { target: vi17; state:"off" }
            PropertyChanges { target: vi18; state:"off" }
            PropertyChanges { target: vi19; state:"off" }
            PropertyChanges { target: vi20; state:"off" }
        },
        State {
            name: "16.5"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"off" }
            PropertyChanges { target: vi16; state:"off" }
            PropertyChanges { target: vi17; state:"off" }
            PropertyChanges { target: vi18; state:"off" }
            PropertyChanges { target: vi19; state:"off" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "18"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"off" }
            PropertyChanges { target: vi16; state:"off" }
            PropertyChanges { target: vi17; state:"off" }
            PropertyChanges { target: vi18; state:"off" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "19.5"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"off" }
            PropertyChanges { target: vi16; state:"off" }
            PropertyChanges { target: vi17; state:"off" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "21"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"off" }
            PropertyChanges { target: vi16; state:"off" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "22.5"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"off" }
            PropertyChanges { target: vi16; state:"on" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "24"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"off" }
            PropertyChanges { target: vi15; state:"on" }
            PropertyChanges { target: vi16; state:"on" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "25.5"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"off" }
            PropertyChanges { target: vi14; state:"on" }
            PropertyChanges { target: vi15; state:"on" }
            PropertyChanges { target: vi16; state:"on" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "27"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"off" }
            PropertyChanges { target: vi13; state:"on" }
            PropertyChanges { target: vi14; state:"on" }
            PropertyChanges { target: vi15; state:"on" }
            PropertyChanges { target: vi16; state:"on" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "28.5"
            PropertyChanges { target: vi11; state:"off" }
            PropertyChanges { target: vi12; state:"on" }
            PropertyChanges { target: vi13; state:"on" }
            PropertyChanges { target: vi14; state:"on" }
            PropertyChanges { target: vi15; state:"on" }
            PropertyChanges { target: vi16; state:"on" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        },
        State {
            name: "30"
            PropertyChanges { target: vi11; state:"on" }
            PropertyChanges { target: vi12; state:"on" }
            PropertyChanges { target: vi13; state:"on" }
            PropertyChanges { target: vi14; state:"on" }
            PropertyChanges { target: vi15; state:"on" }
            PropertyChanges { target: vi16; state:"on" }
            PropertyChanges { target: vi17; state:"on" }
            PropertyChanges { target: vi18; state:"on" }
            PropertyChanges { target: vi19; state:"on" }
            PropertyChanges { target: vi20; state:"on" }
        }
    ]
}
