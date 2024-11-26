import QtQuick 2.15
import "./Components"
// Rectangle {
//     anchors.fill: parent
//     color: "light blue"
//     opacity: 0.7
// }

    Rectangle {
        id: openedChatViewRoot
        // readonly property var openedChatUser: Chat.openedChatUser
        signal sav(string mess)
        gradient: Gradient{
            orientation: Gradient.Horizontal
            GradientStop{ position: 0.0; color: "#0B0F11"; }
            GradientStop{ position: 1.0; color: "#20375B"; }
        }
        radius: 50
        ChatHeader {
            id: chatHeader;
        }
        Rectangle{
            id: chatBody
            width: parent.width
            anchors.bottom: parent.bottom
            height: parent.height * 0.89
            radius: 40
            color: "#09101A"
            ChatThread {
                id: chatThread;
            }
            ChatInput {
                id: chatInput;

                onSendMsg: {
                    sav(msg)
                    PersonModel.sendMsg(msg)
                    client.sendMessage(msg)
                    console.log(msg)
                }
            }

        }
    }


