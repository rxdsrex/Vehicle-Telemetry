#include "controller.h"

/*--------------Constructor & Destructor------------*/

Controller::Controller():ambientLow(5),ambientHigh(45), frontTemperature("15"), rearTemperature("15"), leftSeatHeat("0"), rightSeatHeat("0"), fanSpeed("0"), ambientAirTemperature("25"), isAirConditioningActive("false"), isRecirculationActive("false") {
    QTimer *publishTimer = new QTimer(this);
    publishTimer->setInterval(30000);
    this->restClient = new QNetworkAccessManager(this);
    connect(this->restClient, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    connect(publishTimer,SIGNAL(timeout()),this,SLOT(periodic()));
    publishTimer->start();
}

Controller::~Controller() {
    delete restClient;
}

/*--------------Getter & Setter------------*/

void Controller::setAmbientAirTemperature(QVariant var) {
    this->ambientAirTemperature = var.toString();
    emit ambientAirTemperatureChanged(this->ambientAirTemperature);
}

QVariant Controller::getAmbientAirTemperature() const {
    return ambientAirTemperature;
}

/*--------------SLOTS------------*/

void Controller::frontTempSliderSlot(const QVariant &ftemp) {
    this->frontTemperature = ftemp.toString();
    qWarning() << "Front Temp: " << this->frontTemperature.toString();
}

void Controller::rearTempSliderSlot(const QVariant &rtemp) {
    this->rearTemperature = rtemp.toString();
    qWarning() << "Rear Temp: " << this->rearTemperature.toString();
}

void Controller::leftHeatDialSlot(const QVariant &lheat) {
    this->leftSeatHeat = lheat.toString();
    qWarning() << "Left seat heat: " << this->leftSeatHeat.toString();
}

void Controller::rightHeatDialSlot(const QVariant &rheat) {
    this->rightSeatHeat = rheat.toString();
    qWarning() << "R seat heat: " << this->rightSeatHeat.toString();
}

void Controller::fanSpeedSliderSlot(const QVariant &fspeed) {
    this->fanSpeed = fspeed.toString();
    qWarning() << "Fan Speed: " << this->fanSpeed.toString();
}

void Controller::recirculationStateSlot(const QVariant &recirculate) {
    this->isRecirculationActive = recirculate.toString();
    qWarning() << "Recirculation: " << this->isRecirculationActive.toString();
}

void Controller::acStateSlot(const QVariant &ac) {
    this->isAirConditioningActive = ac.toString();
    qWarning() << "A/C: " << this->isAirConditioningActive.toString();
}

void Controller::periodic() {
    time = QTime::currentTime();
    qsrand((uint)time.msec());
    QVariant temp = (qrand() % ((ambientHigh + 1) - ambientLow) + ambientLow);
    this->setAmbientAirTemperature(temp);
    this->publishFeed();
}

void Controller::replyFinished(QNetworkReply *reply) {
    QByteArray buffer = reply->readAll();
    qWarning() << "Posted Successfully " << reply->readAll();
}

/*--------------Functions------------*/

void Controller::publishFeed() {
    this->feed.clear();
    this->feed.insert("api_key",this->WRITE_KEY);
    this->feed.insert("field1",this->frontTemperature.toString());
    this->feed.insert("field2",this->rearTemperature.toString());
    this->feed.insert("field3",this->leftSeatHeat.toString());
    this->feed.insert("field4",this->rightSeatHeat.toString());
    this->feed.insert("field5",this->fanSpeed.toString());
    this->feed.insert("field6",this->ambientAirTemperature.toString());
    this->feed.insert("field7",this->isAirConditioningActive.toString());
    this->feed.insert("field8",this->isRecirculationActive.toString());
    payload = QJsonDocument::fromVariant(feed);

    this->url.clear();
    this->url.setScheme("https");
    url.setHost("api.thingspeak.com");
    url.setPath("/update.json");

    this->request.setUrl(this->url);
    this->request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    this->restClient = new QNetworkAccessManager(this);
    this->reply = restClient->post(request,payload.toJson());
}
