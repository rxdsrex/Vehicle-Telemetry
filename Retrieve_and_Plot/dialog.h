#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <algorithm>
#include <QVariantMap>
#include <QVariant>
#include <QByteArray>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtDebug>
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
    const QString READ_KEY = "9YW3MYRRHQUAL1DW";
    const QString CHANNEL_NUMBER = "380449";
    QPushButton *buttonSender;
    QVariantMap feed;
    QJsonDocument payload;
    QJsonArray feedArray;
    QJsonObject attributeObj;
    QNetworkAccessManager *restClient;
    QUrl url;
    QUrlQuery querystr;
    QNetworkRequest request;
    QNetworkReply *reply;


public:
    explicit Dialog(QWidget *parent = 0);
    void populateGraphCbox(QJsonObject);
    void displayTable(QByteArray&);
    ~Dialog();

private slots:
    void retrieveFromDB();
    void replyFinished(QNetworkReply *);
    void populateGraph();
};

#endif // DIALOG_H
