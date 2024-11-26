#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#define HOST    "127.0.0.1"
#define PORT      "45000"

class TcpClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isLoginSuccess READ isLoginSuccess WRITE setIsLoginSuccess NOTIFY isLoginSuccessChanged FINAL)
public:
    enum REQUEST_TYPE {
        LOGIN_REQUEST,
        MSG_REQUEST
    };
    explicit TcpClient(QObject *parent = nullptr);
    Q_INVOKABLE void sendMessage(const QString &message);
    Q_INVOKABLE void requestLogin(const QString &user, const QString &pwd);
    void connectToServer();
    void handleResponseFromService(const QString &jsonString);
    void handleLoginProcess(const QJsonObject &jsonObj);
    void handleReceiveMsg(const QJsonObject &jsonObj);
    void setIsLoginSuccess(const bool &isLogin);
    bool isLoginSuccess();

signals:
    void newMessage(const QString &message);
    void isLoginSuccessChanged(const bool &isLogin);
private slots:
    void onConnected();
    void onErrorOccurred(QAbstractSocket::SocketError error);
    void onReadyRead();

private:
    QTcpSocket _socket;
    bool m_isLoginSuccess = false;

};

#endif // TCPCLIENT_H
