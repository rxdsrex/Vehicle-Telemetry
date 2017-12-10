#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QObject>
#include <QtDebug>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *object = component.create();

    MyClass myClass;

    QObject *frontPanel = object->findChild<QObject*>("frontPanel");
    if(frontPanel) {
        QObject *tempSlider = frontPanel->findChild<QObject*>("tempSlider");
        if(tempSlider)
            QObject::connect(tempSlider, SIGNAL(sliderSignal(QVariant)),
                             &myClass, SLOT(cppSlot(QVariant)));
    }
    return app.exec();
}
