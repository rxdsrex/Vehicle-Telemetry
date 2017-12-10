#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QObject>
#include <QtDebug>
#include "signalhandler.h"

//#include <QQmlApplicationEngine>

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

    SignalHandler *signalHandler = new SignalHandler();

    QObject *frontPanel = object->findChild<QObject*>("frontPanel");
    if(frontPanel) {
        QObject *frontTempSlider = frontPanel->findChild<QObject*>("frontTempSlider");
        if(frontTempSlider) {
            QObject::connect(frontTempSlider, SIGNAL(frontSliderSignal(QVariant)), signalHandler, SLOT(frontTempSliderSlot(QVariant)));
        }
    }

    QObject *rearPanel = object->findChild<QObject*>("backPanel");
    if(rearPanel) {
        QObject *rearTempSlider = rearPanel->findChild<QObject*>("rearTempSlider");
        if(rearTempSlider) {
            QObject::connect(rearTempSlider,SIGNAL(rearSliderSignal(QVariant)),signalHandler, SLOT(rearTempSliderSlot(QVariant)));
        }
    }

    QObject *leftDial = object->findChild<QObject*>("leftDial");
    if(leftDial) {
        QObject *leftHeatDial = leftDial->findChild<QObject*>("leftHeatDial");
        if(leftHeatDial) {
            QObject::connect(leftHeatDial,SIGNAL(leftDialSignal(QVariant)),signalHandler, SLOT(leftHeatDialSlot(QVariant)));
        }
    }

    QObject *rightDial = object->findChild<QObject*>("rightDial");
    if(rightDial) {
        QObject *rightHeatDial = rightDial->findChild<QObject*>("rightHeatDial");
        if(rightHeatDial) {
            QObject::connect(rightHeatDial,SIGNAL(rightDialSignal(QVariant)),signalHandler, SLOT(rightHeatDialSlot(QVariant)));
        }
    }

    QObject *centralPanel = object->findChild<QObject*>("centralPanel");
    if(centralPanel) {
        QObject *fanSpeedIndicator = centralPanel->findChild<QObject*>("fanSpeedIndicator");
        if(fanSpeedIndicator) {
            QObject *fanSpeedSlider = fanSpeedIndicator->findChild<QObject*>("fanSpeedSlider");
            if(fanSpeedSlider) {
                QObject::connect(fanSpeedSlider,SIGNAL(fanSpeedSliderSignal(QVariant)),signalHandler, SLOT(fanSpeedSliderSlot(QVariant)));
            }
        }
    }

    QObject *buttonPanel = object->findChild<QObject*>("buttonPanel");
    if(buttonPanel) {
        QObject *acButtonObject = buttonPanel->findChild<QObject*>("acButtonObject");
        QObject *rcButtonObject = buttonPanel->findChild<QObject*>("rcButtonObject");

        if(acButtonObject) {
                QObject::connect(acButtonObject,SIGNAL(acSignal(QVariant)),signalHandler, SLOT(acStateSlot(QVariant)));
        }

        if(rcButtonObject) {
                QObject::connect(rcButtonObject,SIGNAL(rcSignal(QVariant)),signalHandler, SLOT(recirculationStateSlot(QVariant)));
        }
    }

    return app.exec();
}
