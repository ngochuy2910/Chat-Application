#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>
#include "ChatModel.h"
#include "QDebug"
#include "Person.h"
#include <QFile>
#include <QJsonDocument>

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ChatModel* currentChat READ currentChat WRITE setCurrentChat NOTIFY currentChatChanged FINAL)
    Q_PROPERTY(QString currentAvatar READ currentAvatar NOTIFY currentAvatarChanged )
    Q_PROPERTY(QString currentName READ currentName NOTIFY currentNameChanged )
public:
    enum PersonRole {
        NameRole,
        AvatarRole,
    };
    explicit PersonModel(QObject *parent = nullptr);
    void initilize();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    // void setData(const int &index, const QVariant &value, int role = Qt::EditRole);
    void appendPerson(Person person);

    QList<Person> listPersons() const;
    void setListPersons(const QList<Person> &newListPersons);

    ChatModel* currentChat();
    void setCurrentChat( ChatModel* chatModel);
    void setCurrentAvatar(const QString &currentAvatar);
    QString currentAvatar();

    QString currentName();
    void setCurrentName(const QString &currentName);

    Person currentPerson() const;
    void setCurrentPerson(const Person &newCurrentPerson);

    void saveDataToJsonFile();
    void getDataFromJsonFile(const QString &user);
    Q_INVOKABLE void clickChat(int index);
    Q_INVOKABLE void sendMsg(QString msg);
    // Q_INVOKABLE ChatModel* currentChatThread();

signals:
    void currentChatChanged();
    void currentAvatarChanged();
    void currentNameChanged();

public slots :
    void receiveNewMsg(QString msg);
    void handleUserActive(QString user);

private:
    QList<Person> m_listPersons;
    Person *m_currentPerson = nullptr;
    ChatModel *m_currentChat = nullptr;
    QString m_currentAvatar = "";
    QString m_currentName = "";

};

#endif // PERSONMODEL_H
