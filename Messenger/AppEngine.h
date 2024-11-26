#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "PersonModel.h"
#include "TcpClient.h"
#include "UserProfile.h"

#define  APP_ENGINE     AppEngine::getInstance()
#define  USER_PROFILE   APP_ENGINE->profile()
#define  PERSON_MODEL   APP_ENGINE->persons()


class AppEngine
{
public:
    static AppEngine *getInstance();
    void initApp();
    void setContextProperty(const QQmlApplicationEngine &engine);


    AppEngine(const AppEngine&) = delete;
    AppEngine& operator=(const AppEngine&) = delete;

    PersonModel *persons() const;
    void setPersons(PersonModel *newPersons);

    UserProfile *profile() const;
    void setProfile(UserProfile *newProfile);

signals:

private:
    explicit AppEngine();
    PersonModel *m_persons = nullptr;
    TcpClient *m_client = nullptr;
    UserProfile *m_profile = nullptr;

    static AppEngine* m_instance;
};

#endif // APPENGINE_H
