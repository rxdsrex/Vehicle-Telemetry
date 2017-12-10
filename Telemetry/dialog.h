#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGlobal>
#include <QTimer>
#include <QTime>
#include <QVariantMap>
#include <QVariant>
#include <QByteArray>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog *ui;
    const QString WRITE_KEY = "RAYYNYWYN2CD62K7";
    const QString READ_KEY = "9YW3MYRRHQUAL1DW";
    const QString CHANNEL_NUMBER = "380449";
    int ambientHigh;
    int ambientLow;
    QTime time;
    QPushButton *buttonSender;
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
    QNetworkAccessManager *restClient;
    QUrl url;
    QUrlQuery querystr;
    QNetworkRequest request;
    QNetworkReply *reply;


public:
    explicit Dialog(QWidget *parent = 0);
    void displayGraph(QByteArray&);
    void displayTable(QByteArray&);
    ~Dialog();

private slots:
    void periodic();
    void publishFeed();
    void retrieveFromDB();
    void replyFinished(QNetworkReply *);
};

#endif // DIALOG_H
