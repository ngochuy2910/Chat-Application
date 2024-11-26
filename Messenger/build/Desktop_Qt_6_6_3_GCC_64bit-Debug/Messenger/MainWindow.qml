import QtQuick
import QtQuick.Controls
import "./Contacts"
import "./OpenedChat"
import "./LoginChat"

Rectangle {
    id: mainWindow
    color: "transparent"
    radius: 50

    // Text {
    //     id: timeText
    //     x: 10
    //     y: 10
    //     text: Qt.formatTime(new Date(),"hh:mm")
    //     color: "white"
    // }

    StackView {
        id: mainStack
        anchors.fill: parent
        initialItem: loginView //contactView
    }

    LoginChat {
        id: loginView
    }
    Text {
        id: timeText
        anchors.horizontalCenter: parent.horizontalCenter
        y: 10
        text: Qt.formatTime(new Date(),"hh:mm")
        color: "white"
        Timer {

            interval: 1000
            running: true
            repeat: true
            onTriggered: {
               parent.text = Qt.formatTime(new Date(),"hh:mm")
            }
        }


    }

    ContactViews {
        id: contactView
        visible: false
    }
}
