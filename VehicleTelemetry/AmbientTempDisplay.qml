import QtQuick 2.6

Rectangle{

    width:300
    height: 115

    Image {
        id: background
        source: "qrc:/images/textbg.png"
        anchors.fill:parent
    }

    Text {
        padding: 5
        color:"black"
        text: "The temperature is : "
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}

