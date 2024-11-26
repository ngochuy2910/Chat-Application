import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import QtQuick.Effects
// import QtGraphicalEffects 1.0

// import "../../OpenedChat/OpenedChatView.qml"


Rectangle {

    color: "transparent"
    radius: 100

    Rectangle {
        id: hoverBackground
        height: parent.height
        width: mouseArea.containsMouse ? parent.width : 0
        Behavior on width { SmoothedAnimation{ duration: 450; } }
        anchors.left: parent.left; anchors.leftMargin: profileImage.width/2
        gradient: Gradient{
            orientation: Gradient.Horizontal
            GradientStop { position: 0.0; color: "transparent" }
            GradientStop { position: 0.4; color: "#3e4f6b"; }
            GradientStop { position: 0.8; color: "transparent" }
        }
    }

    RowLayout{
        width: parent.width * 0.9
        height: parent.height
        spacing: 8*1.5

        Image {
            id: profileImage
            source: avatar //"../../Media/Images/hoangvi.jpg"
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
            Layout.fillWidth: true;
            Layout.preferredHeight: parent.height
            Layout.leftMargin: 8*1.5
            spacing: 4
            Layout.topMargin: -4*1.5

            Text{
                text: name //name + " " + lastName
                color: "white" //CustomColors.plainWhite
                font.pixelSize: 14*1.5
                Layout.fillWidth: true
                opacity: 0.8
                font.family: Font.Bold
                Layout.fillHeight: true
                verticalAlignment: Qt.AlignBottom
            }
            Text{
                text: "Hallo .. "//messages.count === 0 ? "" : messages.at(contactData.messages.count-1).contents
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

    MouseArea{
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
            // Chat.openedChatUser = contactData;
            PersonModel.clickChat(index)
            mainStack.push("../../OpenedChat/OpenedChatView.qml");
        }
    }
}

