#include "signalhandler.h"

SignalHandler::SignalHandler() {
    ambientLow = 5;
    ambientHigh = 45;
}

/*--------------Getters & Setter------------*/

QVariant SignalHandler::getAmbientAirTemperature() {
    this->setAmbientAirTemperature();
    return ambientAirTemperature;
}

void SignalHandler::setAmbientAirTemperature() {
    time = QTime::currentTime();
    qsrand((uint)time.msec());
    this->ambientAirTemperature = (qrand() % ((ambientHigh + 1) - ambientLow) + ambientLow);
}

QVariant SignalHandler::getFrontTemperature() {
    return frontTemperature;
}

QVariant SignalHandler::getRearTemperature() {
    return rearTemperature;
}

QVariant SignalHandler::getLeftSeatHeat() {
    return leftSeatHeat;
}

QVariant SignalHandler::getRightSeatHeat() {
    return rightSeatHeat;
}

QVariant SignalHandler::getFanSpeed() {
    return fanSpeed;
}

QVariant SignalHandler::getIsAirConditioningActive() {
    return isAirConditioningActive;
}

QVariant SignalHandler::getIsRecirculationActive() {
    return isRecirculationActive;
}

/*--------------SLOTS------------*/

void SignalHandler::frontTempSliderSlot(const QVariant &ftemp) {
    this->frontTemperature = ftemp.toString();
    qWarning() << "F-Temp: " << this->frontTemperature.toString();
}

void SignalHandler::rearTempSliderSlot(const QVariant &rtemp) {
    this->rearTemperature = rtemp.toString();
    qWarning() << "R-Temp: " << this->rearTemperature.toString();
}

void SignalHandler::leftHeatDialSlot(const QVariant &lheat) {
    this->leftSeatHeat = lheat.toString();
    qWarning() << "L-Heat: " << this->leftSeatHeat.toString();
}

void SignalHandler::rightHeatDialSlot(const QVariant &rheat) {
    this->rightSeatHeat = rheat.toString();
    qWarning() << "R-Heat: " << this->rightSeatHeat.toString();
}

void SignalHandler::fanSpeedSliderSlot(const QVariant &fspeed) {
    this->fanSpeed = fspeed.toString();
    qWarning() << "F-Speed: " << this->fanSpeed.toString();
}

void SignalHandler::recirculationStateSlot(const QVariant &recirculate) {
    this->isRecirculationActive = recirculate.toString();
    qWarning() << "Recirculation: " << this->isRecirculationActive.toString();
}

void SignalHandler::acStateSlot(const QVariant &ac) {
    this->isAirConditioningActive = ac.toString();
    qWarning() << "A/C: " << this->isAirConditioningActive.toString();
}
