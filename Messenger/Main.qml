import QtQuick
import QtQuick.Window

Window {
    width: 336*1.5
    height: 725*1.5
    visible: true
    title: qsTr("Message App")
    color: "transparent"
    Loader {
        id: mainLoader
        anchors.fill: parent
        source:"./MainWindow.qml"
    }

}
