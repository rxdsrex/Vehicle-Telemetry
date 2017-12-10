#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtDebug>
#include <QtGlobal>
#include <QTime>
#include <QTimer>
#include <QVariant>
#include <QVariantMap>
#include <QByteArray>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QUrlQuery>
#include <QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class Controller : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariant ambientAirTemperature READ getAmbientAirTemperature WRITE setAmbientAirTemperature NOTIFY ambientAirTemperatureChanged)
private:
    const QString WRITE_KEY = "RAYYNYWYN2CD62K7";
    const QString CHANNEL_NUMBER = "380449";
    int ambientLow;
    int ambientHigh;
    QTime time;
    QVariant frontTemperature;
    QVariant rearTemperature;
    QVariant leftSeatHeat;
    QVariant rightSeatHeat;
    QVariant fanSpeed;
    QVariant ambientAirTemperature;
    QVariant isAirConditioningActive;
    QVariant isRecirculationActive;
    QVariantMap feed;
    QJsonDocument payload;
    QUrl url;
    QUrlQuery querystr;
    QNetworkAccessManager *restClient;
    QNetworkRequest request;
    QNetworkReply *reply;

public:
    explicit Controller();
    void setAmbientAirTemperature(QVariant);
    QVariant getAmbientAirTemperature() const;
    void publishFeed();
    ~Controller();

signals:
    void ambientAirTemperatureChanged(QVariant);

private slots:
    void replyFinished(QNetworkReply *);
    void periodic();

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
