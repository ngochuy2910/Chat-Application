import QtQuick 2.15
import QtQuick.Controls 2.15
import "../Contacts/Components"

Item {

    Background {
        id: background
    }

    Connections {
        target: client
        function onIsLoginSuccessChanged(isLogin) {
            if(isLogin){
                UserProfile.user = usernameField.text
                mainStack.push(contactView)
            }
        }
    }

    Rectangle {
        width: 300
        height: 300
        color: "#f0f0f0"
        anchors.centerIn: parent
        border.color: "#333"
        radius: 10
        opacity: 0.7

        Text {
            text: "Login"
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 15
        }

        Column {
            spacing: 15
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 60

            // Trường nhập liệu cho tên người dùng
            TextField {
                id: usernameField
                placeholderText: "Username"
                width: 200
                height: 40
            }

            // Trường nhập liệu cho mật khẩu
            TextField {
                id: passwordField
                placeholderText: "Password"
                echoMode: TextInput.Password
                width: 200
                height: 40
            }

            // Nút đăng nhập
            Button {
                text: "Login"
                width: 200
                height: 40
                onClicked: {
                    console.log("Username:", usernameField.text)
                    console.log("Password:", passwordField.text)
                    // UserProfile.user = usernameField.text
                    // mainStack.push(contactView)
                    client.requestLogin(usernameField.text, passwordField.text)
                }
            }


        }
    }

}
