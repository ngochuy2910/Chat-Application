#include <QGuiApplication>
#include <QQmlApplicationEngine>
// #include <ChatModel.h>
// #include <PersonModel.h>
#include <QQmlContext>
#include <QQuickView>
// #include <TcpClient.h>
#include "AppEngine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AppEngine *appEngine = AppEngine::getInstance();
    appEngine->setContextProperty(engine);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Messenger", "Main");

    return app.exec();
}
