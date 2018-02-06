import QtQuick 2.6

Rectangle {
    property string direction
    id: logo
    width: 95
    height: 80
    color: "#282828"
    border.color: "#282828"
    border.width: 2
    Image {
        width: parent.width
        height: parent.height
        id: image
        source: "./images/"+direction+"_temp.png"
    }
}
