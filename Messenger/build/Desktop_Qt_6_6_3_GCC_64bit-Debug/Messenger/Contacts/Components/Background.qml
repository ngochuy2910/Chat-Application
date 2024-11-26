import QtQuick 2.15
import "../../Media/Images/"

Rectangle {
    anchors.fill: parent
    color: "transparent"
    Image {
        id: background
        anchors.fill: parent
        source:"../../Media/Images/background.png"
        asynchronous: true
        fillMode: Image.Stretch

        layer.enabled: true
    }
}
