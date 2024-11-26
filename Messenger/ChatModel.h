#ifndef CHATMODEL_H
#define CHATMODEL_H
#include <QObject>
#include <QAbstractListModel>

class Chat {
public:
    Chat();
    Chat(const QString &contents, const bool &isSender);
    QString contents() const ;
    void setContents(const QString &newContents);
    bool getIsSender() const;
    void setIsSender(bool newIsSender);

private :
    QString m_contents;
    bool m_isSender;
};

class ChatModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum ChatRoles {
        ContentRole = Qt::UserRole + 1,
        IsSenderRole
    };
    explicit ChatModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    void setData(const int &index, const QVariant &value, int role = Qt::EditRole);

    Q_INVOKABLE void appendChat(Chat chat);
    Q_INVOKABLE void appendChat(QString msg, bool isSender = false );


    QList<Chat> chatThread() const;
    void setChatThread(const QList<Chat> &newChatThread);

signals:

private:
    QList <Chat> m_chatThread;
};

#endif // CHATMODEL_H
