#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ambientLow = 5;
    ambientHigh = 45;
    //QTimer publishTimer;
    //publishTimer.setInterval(20000);
    this->restClient = new QNetworkAccessManager(this);
    ui->tableWidget->resizeColumnsToContents();
    //connect(publishTimer,SIGNAL(timeout()),this,SLOT(periodic()));
    connect(this->restClient, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
    connect(ui->publishButton,SIGNAL(clicked(bool)),this,SLOT(publishFeed()));
    connect(ui->tablePopulate,SIGNAL(clicked(bool)),this,SLOT(retrieveFromDB()));
    connect(ui->graphPopulate,SIGNAL(clicked(bool)),this,SLOT(retrieveFromDB()));
}

Dialog::~Dialog() {
    delete restClient;
    delete ui;
}

void Dialog::publishFeed() {
    buttonSender = qobject_cast<QPushButton*>(sender());
    this->frontTemperature = ui->frontTemperature->value();
    this->rearTemperature = ui->rearTemperature->value();
    this->leftSeatHeat = ui->leftSeatTemp->value();
    this->rightSeatHeat = ui->rightSeatTemp->value();
    this->fanSpeed = ui->fanSpeed->value();
    time = QTime::currentTime();
    qsrand((uint)time.msec());
    this->ambientAirTemperature = (qrand() % ((ambientHigh + 1) - ambientLow) + ambientLow);
    this->isAirConditioningActive = ui->isACActive->isChecked();
    this->isRecirculationActive = (0 != ui->isRecirculationActive->value());

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

void Dialog::retrieveFromDB() {
    buttonSender = qobject_cast<QPushButton*>(sender());
    querystr.clear();
    querystr.addQueryItem("api_key",this->READ_KEY);
    querystr.addQueryItem("results",QVariant(ui->numResults->value()).toString());

    this->url.clear();
    this->url.setScheme("https");
    this->url.setHost("api.thingspeak.com");
    this->url.setPath("/channels/380449/feeds.json");
    this->url.setQuery(querystr);

    this->request.setUrl(url);

    //this->restClient = new QNetworkAccessManager(this);
    this->reply = restClient->get(request);
}

void Dialog::replyFinished(QNetworkReply *reply) {
    QByteArray buffer = reply->readAll();
    //qDebug() << buffer;

    if(buttonSender->objectName() == "tablePopulate") {
        displayTable(buffer);
    }

    else if(buttonSender->objectName() == "graphPopulate") {
        displayGraph(buffer);
    }
    else if(buttonSender->objectName() == "publishButton") {
        qDebug() << "Posted Successfully " << reply->readAll();
    }
    reply->deleteLater();
}

void Dialog::displayTable(QByteArray &buffer) {
    //qDebug() << buffer;
    QJsonDocument feedDoc = QJsonDocument::fromJson(buffer);
    QJsonObject feedObj = feedDoc.object();
//    QJsonValue jschannel = jsobj.value(QString("channel"));
//    QVariantMap jsmap = jschannel.toObject().toVariantMap();
//    for(QVariantMap::const_iterator iter = jsmap.begin(); iter != jsmap.end(); ++iter) {
//        qDebug() << iter.key() << "," << iter.value();
//    }
    QJsonArray feedArr = feedObj["feeds"].toArray();
    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(feedArr.count());
    int row = 0;
    foreach (const QJsonValue &value, feedArr) {
        QJsonObject jsObj = value.toObject();
        //ui->tableWidget->setItem(row,0,new QTableWidgetItem(QVariant(jsObj["entry_id"].toInt()).toString()));
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(jsObj["field1"].toString()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(jsObj["field2"].toString()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(jsObj["field3"].toString()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(jsObj["field4"].toString()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(jsObj["field5"].toString()));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(jsObj["field6"].toString()));
        ui->tableWidget->setItem(row,6,new QTableWidgetItem(jsObj["field7"].toString()));
        ui->tableWidget->setItem(row,7,new QTableWidgetItem(jsObj["field8"].toString()));
        ui->tableWidget->setItem(row,8,new QTableWidgetItem(jsObj["created_at"].toString()));
        row++;
        ui->tableWidget->resizeColumnsToContents();
    }
}

void Dialog::periodic() {

}

void Dialog::displayGraph(QByteArray &buffer) {

}
