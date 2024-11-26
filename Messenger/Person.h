#ifndef PERSON_H
#define PERSON_H
#include "QDebug"
#include "ChatModel.h"
#include <QJsonArray>
#include <QJsonObject>

class Person {
public:
    Person() ;
    ~Person();

    Person(const QString &name, const QString &avatar );

    QString name() const;
    void setName(const QString &newName);

    QString avatar() const;
    void setAvatar(const QString &newAvatar);

    ChatModel *getChatModel() const;
    void setChatModel(ChatModel *newChatModel);

    QJsonObject toJson();

private:
    QString m_name ;
    QString m_avatar;
    ChatModel* chatModel = nullptr;
};

#endif // PERSON_H
