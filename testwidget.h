#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include<QNetworkAccessManager>
#include<QNetworkReply>
namespace Ui {
class testWidget;
}

class testWidget : public QWidget
{
    Q_OBJECT

public:
    explicit testWidget(QWidget *parent = nullptr);
    ~testWidget();
    void init();
public slots:
    void connect_test();
    void replyFinished(QNetworkReply* reply);
signals:
    void finished(QNetworkReply*);
private:
    Ui::testWidget *ui;
};

#endif // TESTWIDGET_H
