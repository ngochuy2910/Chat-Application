import QtQuick 2.15

Item {
    anchors.left: parent.left; anchors.right: parent.right;
    anchors.bottom: chatInput.top; anchors.top: parent.top;


    ListModel {
        id: chatModel

        ListElement {
            isSender: true
            contents: "How are you today ... dsdfsd "
        }

        ListElement {
            isSender: false
            contents: "I'm OK. HOW arre you  ?"
        }

        ListElement {
            isSender: true
            contents: "I'm not OK. I'm hungry  ?"
        }

        ListElement {
            isSender: true
            contents: "I want to eat something ... "
        }

        ListElement {
            isSender: true
            contents: "hi, emyeuanhhihi''"
        }

    }


    ListView {
        id: openedChatList
        anchors.fill: parent
        anchors.margins: 16
        model: PersonModel.currentChat //ChatModel //Chat.openedChatUser.messages

        spacing: 8
        clip: true
        highlightFollowsCurrentItem: true

        onCountChanged: {
            openedChatList.currentIndex = count - 1;
        }

        delegate: ChatBubble { }

        add: Transition{
            NumberAnimation{ properties: "x"; from: openedChatList.width/2; duration: 500; easing.type: Easing.OutBounce; }
        }
    }

    Connections {
        target: openedChatViewRoot
        onSav : {
            console.log("halo")
        }
    }
}
