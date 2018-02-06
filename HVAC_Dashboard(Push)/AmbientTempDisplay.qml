import QtQuick 2.6

Rectangle{
    objectName: "ambientDisplay"
    signal ambientTemperatureChanged(var temp)
    property string currentTemperature:"25"
    property string unit:" °C"
    width:300
    height: 115

    onAmbientTemperatureChanged: {
        currentTemperature = temp
    }

    Image {
        id: background
        source: "qrc:/images/textbg.png"
        anchors.fill:parent
    }

    FontLoader { id: digitalFont; name: "DS-DIGITAL";source:"qrc:/fonts/DS-DIGIB.TTF" }

    Text {
        padding: 5
        color:"#282828"
        font.family: digitalFont.name
        text: currentTemperature+unit
        font.pixelSize: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}

