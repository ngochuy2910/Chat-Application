import QtQuick 2.15
import QtQuick.Controls 2.5

Item {
    id: root
    height: shouldShowTime ? bubble.height + 25 : bubble.height
    width: bubble.width
    // x: sender ? 0 : openedChatList.width - width


    property bool sender: isSender // index%2 == 0 // userID == Chat.mainUser.ID
    property bool shouldShowTime: false //openedChatList.count - 1 === index ? true : openedChatList.model.at(index+1).userID !== Chat.mainUser.ID

    Rectangle {
        id: bubble
        width: Math.min(messageText.implicitWidth + 24, (openedChatList.width * 0.8))
        height: messageText.implicitHeight + 24
        radius: 12
        x: sender ? 0 : openedChatList.width - width
        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: -0.2; color: sender ? "#252B35" : "#32CEF2"; }
            GradientStop { position: 1.0; color: sender ? "#3f4045" : "#2D6CF7"; }
        }

        Text{
            id: messageText
            text: contents
            anchors.fill: parent
            anchors.margins: 12
            wrapMode: Label.Wrap
            color: "white"//CustomColors.plainWhite
            opacity: 0.75
            font.pixelSize: 20
            // font.family: Poppins.medium
            verticalAlignment: Qt.AlignVCenter
            horizontalAlignment: sender ? Qt.AlignLeft : Qt.AlignRight
        }
    }
}
