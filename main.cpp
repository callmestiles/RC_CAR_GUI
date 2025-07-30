// #include <QGuiApplication>
// #include <QQmlApplicationEngine>
// #include <QQmlContext>
// #include "PathfindingEngine.h"
// #include "CarController.h"
// #include <QFile>

// int main(int argc, char *argv[])
// {
//     QGuiApplication app(argc, argv);

//     // Register PathfindingEngine type
//     qmlRegisterType<PathfindingEngine>("PathfindingEngine", 1, 0, "PathfindingEngine");

//     QQmlApplicationEngine engine;

//     PathfindingEngine pathfindingEngine;
//     CarController carController;

//     engine.rootContext()->setContextProperty("carController", &carController);
//     engine.rootContext()->setContextProperty("pathfindingEngine", &pathfindingEngine);

//     const QUrl url(QStringLiteral("qrc:/Main.qml"));
//     QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                      &app, [url](QObject *obj, const QUrl &objUrl) {
//                          if (!obj && url == objUrl)
//                              QCoreApplication::exit(-1);
//                      }, Qt::QueuedConnection);

//     // qDebug() << "Main.qml exists in qrc:" << QFile::exists(":/Main.qml");

//     engine.load(url);

//     return app.exec();
// }

//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlContext>
//#include "PathfindingEngine.h"
//#include "CarController.h"

//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    // Register PathfindingEngine type
//    qmlRegisterType<PathfindingEngine>("PathfindingEngine", 1, 0, "PathfindingEngine");

//    QQmlApplicationEngine engine;

//    PathfindingEngine pathfindingEngine;
//    CarController carController;

//    engine.rootContext()->setContextProperty("carController", &carController);
//    engine.rootContext()->setContextProperty("pathfindingEngine", &pathfindingEngine);

//    const QUrl url(QStringLiteral("qrc:/Main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//                         if (!obj && url == objUrl)
//                             QCoreApplication::exit(-1);
//                     }, Qt::QueuedConnection);

//    engine.load(url);

//    return app.exec();
//}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "PathfindingEngine.h"
#include "CarController.h"
#include "ThumbstickController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register PathfindingEngine type
    qmlRegisterType<PathfindingEngine>("PathfindingEngine", 1, 0, "PathfindingEngine");

    QQmlApplicationEngine engine;

    PathfindingEngine pathfindingEngine;
    CarController carController;
    ThumbstickController thumbstickController;

    engine.rootContext()->setContextProperty("carController", &carController);
    engine.rootContext()->setContextProperty("pathfindingEngine", &pathfindingEngine);
    engine.rootContext()->setContextProperty("thumbstickController", &thumbstickController);

    QObject::connect(&thumbstickController, &ThumbstickController::motorControlReceived,
                         [&carController](const QString& direction, int speed) {
                             // Convert thumbstick direction to car controller commands
                             if (direction == "forward") {
                                 carController.moveForward();
                             } else if (direction == "backward") {
                                 carController.moveBackward();
                             } else if (direction == "left") {
                                 carController.turnLeft();
                             } else if (direction == "right") {
                                 carController.turnRight();
                             } else if (direction == "stop") {
                                 carController.stopCar();
                             }
                         });

    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
