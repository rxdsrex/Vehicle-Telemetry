import QtQuick 2.6

Rectangle {
    property int indicatorId
    property string indicatorColor: "#B3D9E4"
    id:indicatorId
    width: 25
    height: 15
    anchors.margins: 5

    state: "off"

    states: [
        State {
            name: "on"
            PropertyChanges { target:indicatorId; color:indicatorColor }
        },
        State {
            name: "off"
            PropertyChanges { target:indicatorId; color:"#B3D9E4" }
        }
    ]
    transitions : [
        Transition {
            from: "*"
            to: "*"
            ColorAnimation { duration:100 }
        }
    ]
}
