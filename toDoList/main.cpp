#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include <taskmodel.h>
#include <taskitem.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<taskModel>("Tasks", 1, 0, "TaskModel");
    qmlRegisterUncreatableType<taskItem>("ToDo", 1, 0, "ToDoListItems",
                                         QStringLiteral("ToDoList should not be created in QML"));

    taskItem toDoListItems;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("toDoListItems"), &toDoListItems);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
