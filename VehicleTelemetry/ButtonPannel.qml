import QtQuick 2.6
import QtQuick.Controls 1.4

GroupBox {
    anchors.horizontalCenter: parent.horizontalCenter
    ACButton {id:acbutton}
    ReciculationButton{ anchors.left: acbutton.right; anchors.leftMargin: 70}
}
