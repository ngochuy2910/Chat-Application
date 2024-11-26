#include "AppEngine.h"

AppEngine* AppEngine::m_instance = nullptr;

AppEngine::AppEngine()
{
    this->initApp();
}

UserProfile *AppEngine::profile() const
{
    return m_profile;
}

void AppEngine::setProfile(UserProfile *newProfile)
{
    m_profile = newProfile;
}

PersonModel *AppEngine::persons() const
{
    return m_persons;
}

void AppEngine::setPersons(PersonModel *newPersons)
{
    m_persons = newPersons;
}

AppEngine *AppEngine::getInstance()
{
    if(m_instance == nullptr){
        m_instance = new AppEngine();
        return m_instance;
    }
    return m_instance;
}

void AppEngine::initApp()
{
    m_persons = new PersonModel();
    m_client = new TcpClient();
    m_profile = new UserProfile();

    // PersonModel::getDataFromJsonFile(m_persons);
    // m_persons->getDataFromJsonFile();
    QObject::connect(m_client, &TcpClient::newMessage, m_persons, &PersonModel::receiveNewMsg);
    QObject::connect(m_profile, &UserProfile::userChanged, m_persons, &PersonModel::handleUserActive);
}

void AppEngine::setContextProperty(const QQmlApplicationEngine &engine)
{
    engine.rootContext()->setContextProperty("client", m_client);
    engine.rootContext()->setContextProperty("PersonModel",m_persons);
    engine.rootContext()->setContextProperty("UserProfile",m_profile);
}
