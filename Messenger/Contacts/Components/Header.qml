import QtQuick 2.15
import QtQuick.Layouts

Item {
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.margins: 14*1.5

    RowLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 8*1.5
        anchors.topMargin: 10*1.5
        anchors.bottomMargin: 24*1.5
        spacing: 10*1.5

        ColumnLayout{
            id: welcomingLayout
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 0

            Text{
                text: qsTr("Good Morning") + ","
                color: "white"
                font.pixelSize: 12*1.5
                Layout.fillWidth: true
                opacity: 0.4
                font.family: Font.Bold
                Layout.topMargin: 4*1.5
            }
            Text{
                text: UserProfile.nickname
                color: "white"
                font.pixelSize: 16*1.5
                Layout.fillWidth: true
                opacity: 0.8
                font.family: Font.Bold
                lineHeight: 0.5*1.5
            }
        }
    }
}
