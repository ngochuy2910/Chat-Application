#include "Person.h"

Person::Person() : m_name(""),m_avatar("avatar.jpg")
{
    qDebug()<< "huyhuy";
    chatModel = new ChatModel();
}

Person::~Person()
{
    // delete chatModel;
}

Person::Person(const QString &name, const QString &avatar)
{
    m_name = name;
    m_avatar = avatar;

    qDebug()<< "huyhuy1";
    chatModel = new ChatModel();
}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString &newName)
{
    m_name = newName;
}

QString Person::avatar() const
{
    return m_avatar;
}

void Person::setAvatar(const QString &newAvatar)
{
    m_avatar = newAvatar;
}

ChatModel *Person::getChatModel() const
{
    qDebug()<< "svjs";
    return chatModel;
}

void Person::setChatModel( ChatModel *newChatModel)
{
    chatModel = newChatModel;
}

QJsonObject Person::toJson()
{
    QJsonObject jsonObj;
    jsonObj["name"]     = m_name;
    jsonObj["avatar"]   = m_avatar;

    QJsonArray chatArray;
    for(int i = 0 ; i < chatModel->rowCount() ; ++i){
        QJsonObject item ;
        item["content"] = chatModel->chatThread()[i].contents();
        item["isSender"] = chatModel->chatThread()[i].getIsSender();
        chatArray.append(item);
    }

    jsonObj["chatThread"] = chatArray;

    // chatObj(chatArray);
    return  jsonObj;
}
