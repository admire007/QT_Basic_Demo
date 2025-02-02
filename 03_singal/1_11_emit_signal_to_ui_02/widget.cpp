#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() <<"ui thread id = " << QThread::currentThreadId();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnUpdate_clicked()
{
    ChildThread* ch = new ChildThread();

   // connect(ch, &ChildThread::sig_SendToUI, [=](Score s){
   //     string info = s.name + "id = " + to_string(s.id) + " age = " + to_string(s.age);
   //     ui->lineEdit->setText(QString::fromStdString(info));
   //     qDebug() <<"slot thread id = " << QThread::currentThreadId();
   // });

    connect(ch, &ChildThread::sig_SendToUI, this, &Widget::showInfo);
    connect(ch, &ChildThread::sig2, this, &Widget::showInfo2);

    ch->start();

    qDebug() <<"ui thread id2 = " << QThread::currentThreadId();
}

void Widget::showInfo(Score s)
{
    qDebug() <<"ui thread id3 = " << QThread::currentThreadId();

    string info = s.name + "id = " + to_string(s.id) + " age = " + to_string(s.age);
    ui->lineEdit->setText(QString::fromStdString(info));
}

void Widget::showInfo2(string name, int id)
{
    qDebug() << "name = " << QString::fromStdString(name);
    //qDebug() << "id = " << id;
}












