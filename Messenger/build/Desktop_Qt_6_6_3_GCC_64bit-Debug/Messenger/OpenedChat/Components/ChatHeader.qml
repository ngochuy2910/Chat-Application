import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import QtQuick.Effects

Item  {
    anchors.top: parent.top
    anchors.bottom: chatBody.top
    anchors.topMargin: 16; anchors.bottomMargin: 16;
    anchors.leftMargin: 22; anchors.rightMargin: 22
    anchors.left: parent.left; anchors.right: parent.right;

    RowLayout{
        width: parent.width * 0.9
        height: parent.height
        spacing: 12

        IconButton{
            id: backButton
            Layout.preferredHeight: parent.height * 0.91
            Layout.preferredWidth: height
            color: "#09101A"    //CustomColors.primary
            icon.color: "#FFFFFF"   //CustomColors.plainWhite
            icon.path: "../../svg/arrowLeft.svg"    //IconVault.arrowLeft"../../svg/arrowLeft.svg"
            onClicked: mainStack.pop();
        }

        Image {
            id: profileImage
            source: PersonModel.currentAvatar //"../../Media/Images/avatar.jpg"
            Layout.leftMargin: 12
            width: parent.height
            height: parent.height
            visible: false
        }

        MultiEffect {
            source: profileImage
            anchors.fill: profileImage
            maskEnabled: true
            maskSource: mask
        }

        Item {
            id: mask
            width: profileImage.width
            height: profileImage.height
            layer.enabled: true
            visible: false

            Rectangle {
                width: profileImage.width
                height: profileImage.height
                radius: width/2
            }
        }

        ColumnLayout{
            id: avata
            Layout.fillWidth: true;
            Layout.preferredHeight: parent.height
            Layout.leftMargin: 8*1.5
            spacing: 4
            Layout.topMargin: -4*1.5

            Text{
                text: PersonModel.currentName //name + " " + lastName
                color: "white" //CustomColors.plainWhite
                font.pixelSize: 14*1.5
                Layout.fillWidth: true
                opacity: 0.8
                font.family: Font.Bold
                Layout.fillHeight: true
                verticalAlignment: Qt.AlignBottom
            }
            Text{
                text: "Hallo ........................................."//messages.count === 0 ? "" : messages.at(contactData.messages.count-1).contents
                color: "white"
                font.pixelSize: 12*1.5
                Layout.fillWidth: true
                opacity: 0.4
                font.family: Font.Bold
                Layout.fillHeight: true
                verticalAlignment: Qt.AlignTop
                elide: Text.ElideRight
            }
        }
    }
}

