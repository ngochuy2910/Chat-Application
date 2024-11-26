#include "ChatModel.h"

ChatModel::ChatModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int ChatModel::rowCount(const QModelIndex &parent) const
{
    return m_chatThread.size();
}

QVariant ChatModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_chatThread.count())
        return {};

    const Chat &chat = m_chatThread[index.row()];
    switch (role)
    {
    case ContentRole:
        return chat.contents();
    case IsSenderRole:
        return chat.getIsSender();
    default:
        return {};
    };
}

QHash<int, QByteArray> ChatModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContentRole] = "contents";
    roles[IsSenderRole] = "isSender";

    return roles;
}

void ChatModel::setData(const int &index, const QVariant &value, int role)
{

}

void ChatModel::appendChat(Chat chat)
{
    beginInsertRows(QModelIndex(),m_chatThread.count(),m_chatThread.count());
    m_chatThread.append(chat);
    endInsertRows();
}

void ChatModel::appendChat(QString msg, bool isSender)
{
    beginInsertRows(QModelIndex(),m_chatThread.count(),m_chatThread.count());
    Chat chat(msg,isSender);
    m_chatThread.append(chat);
    endInsertRows();
}

QList<Chat> ChatModel::chatThread() const
{
    return m_chatThread;
}

void ChatModel::setChatThread(const QList<Chat> &newChatThread)
{
    m_chatThread = newChatThread;
};

Chat::Chat():m_contents("hello"),m_isSender(false)
{

}

Chat::Chat(const QString &contents, const bool &isSender)
{
    m_contents = contents;
    m_isSender = isSender;
}

QString Chat::contents() const
{
    return m_contents;
}

void Chat::setContents(const QString &newContents)
{
    m_contents = newContents;
}

bool Chat::getIsSender() const
{
    return m_isSender;
}

void Chat::setIsSender(bool newIsSender)
{
    m_isSender = newIsSender;
}
