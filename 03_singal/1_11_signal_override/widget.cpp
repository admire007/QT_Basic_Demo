#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("10");
    ui->comboBox->addItem("11");
    ui->comboBox->addItem("12");
    ui->comboBox->addItem("13");
    ui->comboBox->addItem("14");

    connect(ui->comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Widget::onIndex);//使用了 static_cast 来明确指定信号的版本
    //使用qt写法，解决信号重载
   connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),
           this, SLOT(onIndex(int)));

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Widget::onIndex);

    connect(ui->comboBox, QOverload<const QString&>::of(&QComboBox::currentIndexChanged),
            this, &Widget::onIndexStr);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onIndex(int index)
{
    qDebug("void Widget::onIndex(int index)");

}

void Widget::onIndexStr(const QString& index)
{

}

