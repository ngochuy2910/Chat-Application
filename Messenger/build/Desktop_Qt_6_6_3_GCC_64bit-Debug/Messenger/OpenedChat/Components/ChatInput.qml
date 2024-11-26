import QtQuick 2.15
import QtQuick.Controls 2.5


Rectangle {
    // id: vhi
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 15
    anchors.horizontalCenter: parent.horizontalCenter

    height: 55*1.5
    width: parent.width * 0.87
    radius: 100

    signal sendMsg(string msg)

    // color: "light blue"

    gradient: Gradient {
        orientation: Gradient.Horizontal
        GradientStop { position: -0.2; color: "#252B35"; }
        GradientStop { position: 1.0; color: "#3f4045"; }
    }

    TextArea{
        id: messageField
        anchors.left: parent.left
        anchors.right: sendButton.left
        anchors.margins: 10
        height: parent.height
        verticalAlignment: Qt.AlignVCenter
        clip: true
        wrapMode: TextArea.Wrap
        placeholderText: qsTr("Type your message here...")

        color: "#FFFFFF" //CustomColors.plainWhite
        font.pixelSize: 23
        opacity: 0.9
        font.family: Font.Bold ///Poppins.bold
        selectByMouse: true
    }

    IconButton{
        id: sendButton

        height: parent.height * 0.8
        width: height
        anchors.right: parent.right; anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 8
        icon.color: "#FFFFFF" //CustomColors.plainWhite
        icon.path: "../../svg/send.svg"//IconVault.send
        icon.sourceSize.height: height * 0.45
        icon.anchors.leftMargin: 10

        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: -0.4; color: "#32CEF2"; }
            GradientStop { position: 1.0; color: "#2D6CF7"; }
        }
        onClicked: sendMessage();
    }

    Shortcut{
        sequence: visible ? "Ctrl+Return" : ""
        onActivated: sendMessage();
    }

    function sendMessage(){
        sendMsg(messageField.text);
        if(messageField.text == "")
            return;
        // sendMsg();

        // Chat.sendMessage(messageField.text);
        messageField.text = "";
    }
}

