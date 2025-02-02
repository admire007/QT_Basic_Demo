#include "widget.h"
#include "ui_widget.h"
#include "setdialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnOpen_clicked()
{
    SetDialog dlg;

    connect(&dlg, &SetDialog::sig_addOne, [=](int value){
        ui->lineEdit->setText(QString::number(value));
    });

    dlg.exec();  //事件循环，会阻塞UI
}

