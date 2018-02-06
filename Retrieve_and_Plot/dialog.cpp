#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->restClient = new QNetworkAccessManager(this);
    ui->tableWidget->resizeColumnsToContents();
    connect(this->restClient, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
    connect(ui->tablePopulate,SIGNAL(clicked(bool)),this,SLOT(retrieveFromDB()));
    connect(ui->graphRetrieve,SIGNAL(clicked(bool)),this,SLOT(retrieveFromDB()));
    connect(ui->graphPopulate,SIGNAL(clicked(bool)),this,SLOT(populateGraph()));
}

Dialog::~Dialog() {
    delete restClient;
    delete ui;
}

void Dialog::retrieveFromDB() {
    buttonSender = qobject_cast<QPushButton*>(sender());
    querystr.clear();
    querystr.addQueryItem("api_key",this->READ_KEY);
    querystr.addQueryItem("results",QVariant(ui->numResults->value()).toString());

    this->url.clear();
    this->url.setScheme("https");
    this->url.setHost("api.thingspeak.com");
    this->url.setPath("/channels/" + CHANNEL_NUMBER + "/feeds.json");
    this->url.setQuery(querystr);

    this->request.setUrl(url);

    this->reply = restClient->get(request);
}

void Dialog::replyFinished(QNetworkReply *reply) {
    QByteArray buffer = reply->readAll();

    if(buttonSender->objectName() == "tablePopulate") {
        displayTable(buffer);
    }

    else if(buttonSender->objectName() == "graphRetrieve") {
        QJsonDocument rootDoc = QJsonDocument::fromJson(buffer);
        QJsonObject rootObj = rootDoc.object();
        this->feedArray = rootObj["feeds"].toArray();
        QJsonValue channel = rootObj["channel"];
        this->attributeObj = channel.toObject();
        populateGraphCbox(attributeObj);
    }
    reply->deleteLater();
}

void Dialog::displayTable(QByteArray &buffer) {
    QJsonDocument feedDoc = QJsonDocument::fromJson(buffer);
    QJsonObject feedObj = feedDoc.object();
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

void Dialog::populateGraphCbox(QJsonObject attributeObj) {
    ui->graphList->clear();
    ui->graphList->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    ui->graphList->addItem(attributeObj["field1"].toString());
    ui->graphList->addItem(attributeObj["field2"].toString());
    ui->graphList->addItem(attributeObj["field3"].toString());
    ui->graphList->addItem(attributeObj["field4"].toString());
    ui->graphList->addItem(attributeObj["field5"].toString());
    ui->graphList->addItem(attributeObj["field6"].toString());
}

void Dialog::populateGraph() {
    QVector<double> x(this->feedArray.count());
    QVector<double> y(this->feedArray.count());
    double xmax;
    double ymax;
    int i;
    if(ui->graphList->currentIndex() != -1) {
        if(ui->graphList->currentIndex() == 0) {
            i = 0;
            foreach (const QJsonValue &value, this->feedArray) {
                QJsonObject jsObj = value.toObject();
                x[i] = jsObj["entry_id"].toDouble();
                //qWarning() << jsObj["entry_id"].toDouble();
                y[i] = jsObj["field1"].toString().toDouble();
                //qWarning() << jsObj["field1"].toString().toDouble();
                i++;
            }
            ui->graphView->clearGraphs();
            ui->graphView->addGraph();
            ui->graphView->graph(0)->setData(x,y);
            ui->graphView->xAxis->setLabel("Entry ID");
            ui->graphView->yAxis->setLabel(this->attributeObj["field1"].toString());

            xmax = *std::max_element(x.constBegin(), x.constEnd());
            ymax = *std::max_element(y.constBegin(), y.constEnd());

            ui->graphView->xAxis->setRange(0, xmax+5);
            ui->graphView->yAxis->setRange(0, ymax+5);
            ui->graphView->replot();
        }

        if(ui->graphList->currentIndex() == 1) {
            i = 0;
            foreach (const QJsonValue &value, this->feedArray) {
                QJsonObject jsObj = value.toObject();
                x[i] = jsObj["entry_id"].toDouble();
                //qWarning() << jsObj["entry_id"].toDouble();
                y[i] = jsObj["field2"].toString().toDouble();
                //qWarning() << jsObj["field1"].toString().toDouble();
                i++;
            }
            ui->graphView->clearGraphs();
            ui->graphView->addGraph();
            ui->graphView->graph(0)->setData(x,y);
            ui->graphView->xAxis->setLabel("Entry ID");
            ui->graphView->yAxis->setLabel(this->attributeObj["field2"].toString());

            xmax = *std::max_element(x.constBegin(), x.constEnd());
            ymax = *std::max_element(y.constBegin(), y.constEnd());

            ui->graphView->xAxis->setRange(0, xmax+5);
            ui->graphView->yAxis->setRange(0, ymax+5);
            ui->graphView->replot();
        }

        if(ui->graphList->currentIndex() == 2) {
            i = 0;
            foreach (const QJsonValue &value, this->feedArray) {
                QJsonObject jsObj = value.toObject();
                x[i] = jsObj["entry_id"].toDouble();
                //qWarning() << jsObj["entry_id"].toDouble();
                y[i] = jsObj["field3"].toString().toDouble();
                //qWarning() << jsObj["field1"].toString().toDouble();
                i++;
            }
            ui->graphView->clearGraphs();
            ui->graphView->addGraph();
            ui->graphView->graph(0)->setData(x,y);
            ui->graphView->xAxis->setLabel("Entry ID");
            ui->graphView->yAxis->setLabel(this->attributeObj["field3"].toString());

            xmax = *std::max_element(x.constBegin(), x.constEnd());
            ymax = *std::max_element(y.constBegin(), y.constEnd());

            ui->graphView->xAxis->setRange(0, xmax+5);
            ui->graphView->yAxis->setRange(0, ymax+5);
            ui->graphView->replot();
        }

        if(ui->graphList->currentIndex() == 3) {
            i = 0;
            foreach (const QJsonValue &value, this->feedArray) {
                QJsonObject jsObj = value.toObject();
                x[i] = jsObj["entry_id"].toDouble();
                //qWarning() << jsObj["entry_id"].toDouble();
                y[i] = jsObj["field4"].toString().toDouble();
                //qWarning() << jsObj["field1"].toString().toDouble();
                i++;
            }
            ui->graphView->clearGraphs();
            ui->graphView->addGraph();
            ui->graphView->graph(0)->setData(x,y);
            ui->graphView->xAxis->setLabel("Entry ID");
            ui->graphView->yAxis->setLabel(this->attributeObj["field4"].toString());

            xmax = *std::max_element(x.constBegin(), x.constEnd());
            ymax = *std::max_element(y.constBegin(), y.constEnd());

            ui->graphView->xAxis->setRange(0, xmax+5);
            ui->graphView->yAxis->setRange(0, ymax+5);
            ui->graphView->replot();
        }

        if(ui->graphList->currentIndex() == 4) {
            i = 0;
            foreach (const QJsonValue &value, this->feedArray) {
                QJsonObject jsObj = value.toObject();
                x[i] = jsObj["entry_id"].toDouble();
                //qWarning() << jsObj["entry_id"].toDouble();
                y[i] = jsObj["field5"].toString().toDouble();
                //qWarning() << jsObj["field1"].toString().toDouble();
                i++;
            }
            ui->graphView->clearGraphs();
            ui->graphView->addGraph();
            ui->graphView->graph(0)->setData(x,y);
            ui->graphView->xAxis->setLabel("Entry ID");
            ui->graphView->yAxis->setLabel(this->attributeObj["field5"].toString());

            xmax = *std::max_element(x.constBegin(), x.constEnd());
            ymax = *std::max_element(y.constBegin(), y.constEnd());

            ui->graphView->xAxis->setRange(0, xmax+5);
            ui->graphView->yAxis->setRange(0, ymax+5);
            ui->graphView->replot();
        }

        if(ui->graphList->currentIndex() == 5) {
            i = 0;
            foreach (const QJsonValue &value, this->feedArray) {
                QJsonObject jsObj = value.toObject();
                x[i] = jsObj["entry_id"].toDouble();
                //qWarning() << jsObj["entry_id"].toDouble();
                y[i] = jsObj["field6"].toString().toDouble();
                //qWarning() << jsObj["field1"].toString().toDouble();
                i++;
            }
            ui->graphView->clearGraphs();
            ui->graphView->addGraph();
            ui->graphView->graph(0)->setData(x,y);
            ui->graphView->xAxis->setLabel("Entry ID");
            ui->graphView->yAxis->setLabel(this->attributeObj["field6"].toString());

            xmax = *std::max_element(x.constBegin(), x.constEnd());
            ymax = *std::max_element(y.constBegin(), y.constEnd());

            ui->graphView->xAxis->setRange(0, xmax+5);
            ui->graphView->yAxis->setRange(0, ymax+5);
            ui->graphView->replot();
        }
    }

    else{
        qWarning() << "No item to populate.";
    }
}
