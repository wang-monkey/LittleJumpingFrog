#include "testwidget.h"
#include "ui_testwidget.h"
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QUrl>
#include<QByteArray>
#include<QTextCodec>
#include<QDebug>

testWidget::testWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testWidget)
{
    ui->setupUi(this);
    init();
}

testWidget::~testWidget()
{
    delete ui;
}

void testWidget::init()
{
    connect(ui->u_connect_test,&QPushButton::clicked,this,&testWidget::connect_test);
}
//"http://192.168.0.103:8080/api/testGet"
void testWidget::connect_test()
{
    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    request.setUrl(QUrl("http://192.168.0.103:8080/api/testGet"));
    QNetworkReply* reply = naManager->get(request);

}

void testWidget::replyFinished(QNetworkReply* reply)
{

    // 获取http状态码
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug() << "status code=" << statusCode.toInt();

    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

    if(reason.isValid())
        qDebug() << "reason=" << reason.toString();

    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
    }
    else {
        // 获取返回内容
        qDebug() << reply->readAll();
    }
}
