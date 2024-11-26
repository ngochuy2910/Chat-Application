import QtQuick 2.15
import QtQuick.Controls 2.5


Rectangle{
    id: buttonRoot
    color: "#09101A"
    radius: 100
    opacity: mouseArea.containsMouse ? 0.8 : 1

    signal clicked

    property alias icon: icon


    Icon{
        id: icon
        sourceSize.height: parent.height * 0.3
        anchors.centerIn: parent
        path: "../../svg/android.svg"
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            buttonRoot.clicked();
        }
        cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
    }
}
