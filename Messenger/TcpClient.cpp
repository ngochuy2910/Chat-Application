#include "TcpClient.h"
#include "AppEngine.h"

TcpClient::TcpClient(QObject *parent)
    : QObject{parent}
{
    this->connectToServer();
    connect(&_socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
    connect(&_socket, &QTcpSocket::errorOccurred, this, &TcpClient::onErrorOccurred);
    connect(&_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
}

void TcpClient::connectToServer()
{
    QString port = PORT;
    _socket.connectToHost(HOST,port.toUInt());
}

void TcpClient::handleResponseFromService(const QString &jsonString)
{
    qDebug()<< "response: " << jsonString;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());

    // Kiểm tra nếu JSON hợp lệ
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        qWarning() << "Invalid JSON!";
        return ;
    }

    // Chuyển QJsonDocument thành QJsonObject
    QJsonObject jsonObj = jsonDoc.object();

    // Truy cập các giá trị trong JSON
    int type = jsonObj.value("type").toInt();

    switch(type){
    case LOGIN_REQUEST:
        handleLoginProcess(jsonObj);
        break;
    case MSG_REQUEST:
        handleReceiveMsg(jsonObj);
        break;
    default:
        break;
    }
}

void TcpClient::handleLoginProcess(const QJsonObject &jsonObj )
{
    // Login true moi nhan dc request
    this->setIsLoginSuccess(true);

    QString nickname = jsonObj.value("nickname").toString();
    QString id = jsonObj.value("id").toString();

    USER_PROFILE->setNickname(nickname);

    // In ra các giá trị:
    qDebug() << "Nickname:" << nickname;
    qDebug() << "ID:" << id;
}

void TcpClient::handleReceiveMsg(const QJsonObject &jsonObj)
{
    QString contents = jsonObj.value("contents").toString();

    qDebug()<< contents;
    emit newMessage(contents);
}

void TcpClient::setIsLoginSuccess(const bool &isLogin)
{
    m_isLoginSuccess = isLogin;
    emit isLoginSuccessChanged(isLogin);
}

bool TcpClient::isLoginSuccess()
{
    return m_isLoginSuccess;
}

void TcpClient::onConnected(){
    qInfo() << "Connected to host";
}

void TcpClient::onErrorOccurred(QAbstractSocket::SocketError error){

    qInfo() << "Error" << error;

}

void TcpClient::onReadyRead(){

    const auto message = _socket.readAll();
    qInfo() << "message: "<< message;
    QString msgJson =  QString::fromUtf8(message);
    handleResponseFromService(msgJson);

    // emit newMessage(message);
}

void TcpClient::sendMessage(const QString &message){

    qDebug() << "TcpClient::sendMessage: "<< message;

    QJsonObject jsonObj;
    jsonObj["type"] = 1;
    jsonObj["contents"] = message;

    QJsonDocument jsonDoc(jsonObj);
    QString msgJson = jsonDoc.toJson(QJsonDocument::Compact);

    qDebug() << "msgJson: "<< msgJson;

    _socket.write(msgJson.toUtf8());
    _socket.flush();
}

void TcpClient::requestLogin(const QString &user, const QString &pwd)
{
    qDebug() << "user: "<< user << " pwd: "<<pwd;

    QJsonObject jsonObj;
    jsonObj["type"] = 0;
    jsonObj["user"] = user;
    jsonObj["password"] = pwd;

    QJsonDocument jsonDoc(jsonObj);
    QString msgJson = jsonDoc.toJson(QJsonDocument::Compact);

    qDebug() << "msgJson: "<< msgJson;

    _socket.write(msgJson.toUtf8());
    _socket.flush();

}
