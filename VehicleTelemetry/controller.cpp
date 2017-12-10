#include "controller.h"

Controller::Controller() {
    ambientLow = 5;
    ambientHigh = 45;
}

/*--------------Getters & Setter------------*/

QVariant Controller::getAmbientAirTemperature() {
    this->setAmbientAirTemperature();
    return ambientAirTemperature;
}

void Controller::setAmbientAirTemperature() {
    time = QTime::currentTime();
    qsrand((uint)time.msec());
    this->ambientAirTemperature = (qrand() % ((ambientHigh + 1) - ambientLow) + ambientLow);
}

QVariant Controller::getFrontTemperature() {
    return frontTemperature;
}

QVariant Controller::getRearTemperature() {
    return rearTemperature;
}

QVariant Controller::getLeftSeatHeat() {
    return leftSeatHeat;
}

QVariant Controller::getRightSeatHeat() {
    return rightSeatHeat;
}

QVariant Controller::getFanSpeed() {
    return fanSpeed;
}

QVariant Controller::getIsAirConditioningActive() {
    return isAirConditioningActive;
}

QVariant Controller::getIsRecirculationActive() {
    return isRecirculationActive;
}

/*--------------SLOTS------------*/

void Controller::frontTempSliderSlot(const QVariant &ftemp) {
    this->frontTemperature = ftemp.toString();
    qWarning() << "F-Temp: " << this->frontTemperature.toString();
}

void Controller::rearTempSliderSlot(const QVariant &rtemp) {
    this->rearTemperature = rtemp.toString();
    qWarning() << "R-Temp: " << this->rearTemperature.toString();
}

void Controller::leftHeatDialSlot(const QVariant &lheat) {
    this->leftSeatHeat = lheat.toString();
    qWarning() << "L-Heat: " << this->leftSeatHeat.toString();
}

void Controller::rightHeatDialSlot(const QVariant &rheat) {
    this->rightSeatHeat = rheat.toString();
    qWarning() << "R-Heat: " << this->rightSeatHeat.toString();
}

void Controller::fanSpeedSliderSlot(const QVariant &fspeed) {
    this->fanSpeed = fspeed.toString();
    qWarning() << "F-Speed: " << this->fanSpeed.toString();
}

void Controller::recirculationStateSlot(const QVariant &recirculate) {
    this->isRecirculationActive = recirculate.toString();
    qWarning() << "Recirculation: " << this->isRecirculationActive.toString();
}

void Controller::acStateSlot(const QVariant &ac) {
    this->isAirConditioningActive = ac.toString();
    qWarning() << "A/C: " << this->isAirConditioningActive.toString();
}
