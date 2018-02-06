#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QObject>
#include <QtDebug>
#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *object = component.create();

    Controller *controller = new Controller();

    QObject *frontPanel = object->findChild<QObject*>("frontPanel");
    if(frontPanel) {
        QObject *frontTempSlider = frontPanel->findChild<QObject*>("frontTempSlider");
        if(frontTempSlider) {
            QObject::connect(frontTempSlider, SIGNAL(frontSliderSignal(QVariant)), controller, SLOT(frontTempSliderSlot(QVariant)));
        }
    }

    QObject *rearPanel = object->findChild<QObject*>("backPanel");
    if(rearPanel) {
        QObject *rearTempSlider = rearPanel->findChild<QObject*>("rearTempSlider");
        if(rearTempSlider) {
            QObject::connect(rearTempSlider,SIGNAL(rearSliderSignal(QVariant)),controller, SLOT(rearTempSliderSlot(QVariant)));
        }
    }

    QObject *leftDial = object->findChild<QObject*>("leftDial");
    if(leftDial) {
        QObject *leftHeatDial = leftDial->findChild<QObject*>("leftHeatDial");
        if(leftHeatDial) {
            QObject::connect(leftHeatDial,SIGNAL(leftDialSignal(QVariant)),controller, SLOT(leftHeatDialSlot(QVariant)));
        }
    }

    QObject *rightDial = object->findChild<QObject*>("rightDial");
    if(rightDial) {
        QObject *rightHeatDial = rightDial->findChild<QObject*>("rightHeatDial");
        if(rightHeatDial) {
            QObject::connect(rightHeatDial,SIGNAL(rightDialSignal(QVariant)),controller, SLOT(rightHeatDialSlot(QVariant)));
        }
    }

    QObject *centralPanel = object->findChild<QObject*>("centralPanel");
    if(centralPanel) {
        QObject *fanSpeedIndicator = centralPanel->findChild<QObject*>("fanSpeedIndicator");
        QObject *ambientDisplay = centralPanel->findChild<QObject*>("ambientDisplay");
        if(fanSpeedIndicator) {
            QObject *fanSpeedSlider = fanSpeedIndicator->findChild<QObject*>("fanSpeedSlider");
            if(fanSpeedSlider) {
                QObject::connect(fanSpeedSlider,SIGNAL(fanSpeedSliderSignal(QVariant)),controller, SLOT(fanSpeedSliderSlot(QVariant)));
            }
        }
        if(ambientDisplay) {
            QObject::connect(controller,SIGNAL(ambientAirTemperatureChanged(QVariant)),ambientDisplay, SIGNAL(ambientTemperatureChanged(QVariant)));
        }
    }

    QObject *buttonPanel = object->findChild<QObject*>("buttonPanel");
    if(buttonPanel) {
        QObject *acButtonObject = buttonPanel->findChild<QObject*>("acButtonObject");
        QObject *rcButtonObject = buttonPanel->findChild<QObject*>("rcButtonObject");

        if(acButtonObject) {
                QObject::connect(acButtonObject,SIGNAL(acSignal(QVariant)),controller, SLOT(acStateSlot(QVariant)));
        }

        if(rcButtonObject) {
                QObject::connect(rcButtonObject,SIGNAL(rcSignal(QVariant)),controller, SLOT(recirculationStateSlot(QVariant)));
        }
    }

    return app.exec();
}
