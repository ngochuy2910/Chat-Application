#ifndef ADAPTOR_H
#define ADAPTOR_H

#include <QObject>

class Adaptor : public QObject
{
    Q_OBJECT
public:
   explicit Adaptor(QObject *parent = nullptr);

    void onResponseFromService();


signals:

private:
    QString m_adaptor;
};

#endif // ADAPTOR_H
