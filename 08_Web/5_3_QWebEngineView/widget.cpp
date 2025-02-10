#include "widget.h"
#include "ui_widget.h"
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QString localUrl = "F:\\8.17QT_data(SecondYear)\\08_Web\\5_3_QWebEngineView\\youku_video_html\\index.html";
    //localUrl = QDir::toNativeSeparators(localUrl);
    ui->web_widget->setUrl(QUrl(localUrl));
    ui->web_widget->show();

    ui->web_widget2->load(QUrl("http://www.baidu.com"));
    //ui->web_widget2->show(); //可以不写这句
}
Widget::~Widget()
{
    delete ui;
}

