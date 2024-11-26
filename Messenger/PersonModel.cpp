#include "PersonModel.h"
#include "AppEngine.h"

PersonModel::PersonModel(QObject *parent)
    : QAbstractListModel{parent}
{
    // m_currentPerson = nullptr;
    initilize();
}

void PersonModel::initilize()
{
    qDebug() << "init";
    m_currentChat = new ChatModel();
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    return m_listPersons.count();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_listPersons.count())
        return {};

    const Person &person = m_listPersons[index.row()];
    switch (role) {
    case NameRole:
        return person.name();
    case AvatarRole:
        return person.avatar();
    default:
        return {};
    };
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AvatarRole] = "avatar";

    return roles;
}

void PersonModel::appendPerson(Person person)
{
    beginInsertRows(QModelIndex(),m_listPersons.count(),m_listPersons.count());
    m_listPersons.append(person);
    endInsertRows();
}

QList<Person> PersonModel::listPersons() const
{
    return m_listPersons;
}

void PersonModel::setListPersons(const QList<Person> &newListPersons)
{
    m_listPersons = newListPersons;
}

ChatModel *PersonModel::currentChat()
{
    return m_currentChat;
}

void PersonModel::setCurrentChat(ChatModel *chatModel)
{
    if(chatModel  == nullptr){
        qDebug() << "hduh3";
        return;
    };
    m_currentChat = chatModel;
    emit currentChatChanged();
}

void PersonModel::setCurrentAvatar(const QString &currentAvatar)
{
    m_currentAvatar = currentAvatar;
}

QString PersonModel::currentAvatar()
{
    return m_currentAvatar;
}

QString PersonModel::currentName()
{
    return m_currentName;
}

void PersonModel::setCurrentName(const QString &currentName)
{
    m_currentName = currentName;
    emit currentNameChanged();
}

void PersonModel::saveDataToJsonFile()
{
    qDebug() << "Save data to json " ;
    QJsonArray jsonArray;
    for ( Person &model : m_listPersons) {
        jsonArray.append(model.toJson());
    }

    QJsonDocument jsonDoc(jsonArray);
    QString currentUser = USER_PROFILE->user();
    QFile file(QString("/home/huy/Huy/Application/Messenger/JsonData/%1.json").arg(currentUser));

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file.");
        return;
    }

    file.write(jsonDoc.toJson());
    file.close();
}

void PersonModel::getDataFromJsonFile(const QString &user)
{
    QFile file(QString("/home/huy/Huy/Application/Messenger/JsonData/%1.json").arg(user));
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return ;
    }

    // PersonModel* personModel = PERSON_MODEL;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = jsonDoc.array();
    // qDebug() << "jsonArray.count(): "<< jsonArray.count();
    for( const QJsonValue  &item : jsonArray){
        QString ava = item["avatar"].toString();
        QString name = item["name"].toString();
        Person person(name,ava);
        ChatModel *chatModel = person.getChatModel();
        QJsonArray chatArray  = item["chatThread"].toArray();
        for (const QJsonValue &chat : chatArray) {
            QString content = chat["content"].toString();
            bool isSender   = chat["isSender"].toBool();
            chatModel->appendChat(content,isSender);
        }
        this->appendPerson(person);


    }
}

void PersonModel::clickChat(int index)
{
    qDebug()<< "clickChat " << index;
    this->setCurrentChat(m_listPersons.at(index).getChatModel());
    this->setCurrentAvatar(m_listPersons.at(index).avatar());
    this->setCurrentName(m_listPersons.at(index).name());
    // this->saveDataToJsonFile();
}

void PersonModel::sendMsg(QString msg)
{
    m_currentChat->appendChat(msg);
    this->saveDataToJsonFile();
}

void PersonModel::receiveNewMsg(QString msg)
{
    qDebug()<< "PersonModel::receiveNewMsg: " << msg;
    m_currentChat->appendChat(msg,true);
    this->saveDataToJsonFile();
}

void PersonModel::handleUserActive(QString user)
{
    qDebug() << user;
    this->getDataFromJsonFile(user);
}
