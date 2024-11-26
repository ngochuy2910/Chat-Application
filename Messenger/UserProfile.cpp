#include "UserProfile.h"

UserProfile::UserProfile(QObject *parent)
    : QObject{parent}
{

}

QString UserProfile::user()
{
    return m_user;
}

void UserProfile::setUser(const QString &user)
{
    qDebug() << "set to: " << user;
    m_user = user ;
    emit userChanged(user);
}

QString UserProfile::nickname()
{
    return m_nickname;
}

void UserProfile::setNickname(const QString &nickname)
{
    qDebug() << "set to: " << nickname;
    m_nickname = nickname;
    emit nicknameChanged();
}
