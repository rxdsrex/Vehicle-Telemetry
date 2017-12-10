#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtGlobal>
#include <QTime>
#include <QVariant>
#include <QString>
#include <QtDebug>

class Controller : public QObject {
    Q_OBJECT
private:
    int ambientHigh;
    int ambientLow;
    QTime time;
    QVariant frontTemperature;
    QVariant rearTemperature;
    QVariant leftSeatHeat;
    QVariant rightSeatHeat;
    QVariant fanSpeed;
    QVariant ambientAirTemperature;
    QVariant isAirConditioningActive;
    QVariant isRecirculationActive;

public:
    explicit Controller();
    void setAmbientAirTemperature();
    QVariant getAmbientAirTemperature();
    QVariant getFrontTemperature();
    QVariant getRearTemperature();
    QVariant getLeftSeatHeat();
    QVariant getRightSeatHeat();
    QVariant getFanSpeed();
    QVariant getIsAirConditioningActive();
    QVariant getIsRecirculationActive();

signals:

public slots:
    void frontTempSliderSlot(const QVariant&);
    void rearTempSliderSlot(const QVariant&);
    void leftHeatDialSlot(const QVariant&);
    void rightHeatDialSlot(const QVariant&);
    void fanSpeedSliderSlot(const QVariant&);
    void recirculationStateSlot(const QVariant&);
    void acStateSlot(const QVariant&);
};

#endif // CONTROLLER_H
