#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QObject>
#include <QDebug>

class UserProfile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged FINAL)
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY nicknameChanged FINAL)
public:
    explicit UserProfile(QObject *parent = nullptr);

    QString user();
    void setUser(const QString &user);

    QString nickname();
    void setNickname(const QString &nickname);

    // QString password();
    // void setPassword(const QString &password);
signals:
    void userChanged(QString);
    void nicknameChanged();
private:
    QString m_user;
    QString m_password ;
    QString m_nickname;

};

#endif // USERPROFILE_H
