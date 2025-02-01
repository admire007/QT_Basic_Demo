#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QSettings>
#include <QDebug>
#include <QStandardPaths>
#include <memory>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label_image->clear();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::open1()
{
    QString fileName = QFileDialog::getOpenFileName(this,QString::fromUtf8("图片阅读器"), "D:/", QString::fromUtf8("图片(*.png *.jpg);;"));

    if(fileName.isEmpty())
    {
        return;
    }

    ui->lineEdit_path->setText(fileName);
    ui->label_image->setPixmap((QPixmap(fileName)));
}

void Widget::open2()
{
    QString config_path = qApp->applicationDirPath() + "/config/Setting.ini";
    qDebug() << config_path;

    QSettings *pIniSet = new QSettings(config_path, QSettings::IniFormat);
    QString lastPath = pIniSet->value("/LastPath/path").toString();

    if(lastPath.isEmpty())
    {
        lastPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    }

    QString fileName = QFileDialog::getOpenFileName(this, QString::fromUtf8("图片阅读器"), lastPath, QString::fromUtf8("图片(*.png *.jpg);;"));

    if(fileName.isEmpty())
    {
        return;
    }

    ui->lineEdit_path->setText(fileName);
    ui->label_image->setPixmap((QPixmap(fileName)));

    int end = fileName.lastIndexOf("/");
    QString _path = fileName.left(end);
    pIniSet->setValue("/LastPath/path", _path);
    delete pIniSet;
    pIniSet = nullptr;
    qDebug() << _path;
}

void Widget::open3()
{
    QString config_path = qApp->applicationDirPath() + "/config/Setting.ini";
    qDebug() << config_path;

    std::unique_ptr<QSettings> pIniSet(new QSettings(config_path, QSettings::IniFormat));
    //QSettings *pIniSet = new QSettings(config_path, QSettings::IniFormat);
    QString lastPath = pIniSet->value("/LastPath/path").toString();

    if(lastPath.isEmpty())
    {
        lastPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    }

    QString fileName = QFileDialog::getOpenFileName(this, QString::fromUtf8("图片阅读器"), lastPath, QString::fromUtf8("图片(*.png *.jpg);;"));

    if(fileName.isEmpty())
    {
        return;
    }

    ui->lineEdit_path->setText(fileName);
    ui->label_image->setPixmap((QPixmap(fileName)));

    int end = fileName.lastIndexOf("/");
    QString _path = fileName.left(end);
    pIniSet->setValue("/LastPath/path", _path);
    //delete pIniSet;
    //pIniSet = nullptr;
    qDebug() << _path;
}

void Widget::open4()
{
    QString config_path = qApp->applicationDirPath() + "/config/Setting.ini";
    qDebug() << config_path;

    /*QSettings 用于读取和写入配置文件，这里指定配置文件路径为 config_path，格式为 INI 格式*/
    std::unique_ptr<QSettings> pIniSet(new QSettings(config_path, QSettings::IniFormat));
    //QSettings *pIniSet = new QSettings(config_path, QSettings::IniFormat);
    QString lastPath = pIniSet->value("/LastPath/path").toString();//获取上次保存的文件夹路径

    if(lastPath.isEmpty())
    {
        //使用 QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) 获取系统默认的图片存储位置作为默认路径。
        lastPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    }

    //调用 QFileDialog::getOpenFileName 弹出文件选择对话框，让用户选择图片文件。
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromUtf8("图片阅读器"), lastPath, QString::fromUtf8("图片(*.png *.jpg);;"));

    if(fileName.isEmpty())
    {
        return;
    }

    ui->lineEdit_path->setText(fileName);

    QPixmap *pix = new QPixmap(fileName);
    pix->scaled(ui->label_image->size(), Qt::KeepAspectRatio);//使用 scaled 方法将图片缩放到 label_image 控件的大小，同时保持图片的宽高比
    /*设置 label_image 控件的 setScaledContents 属性为 true，确保图片在控件中正确显示。
使用 setPixmap 方法将图片显示在 label_image 控件中*/
    ui->label_image->setScaledContents(true);

    ui->label_image->setPixmap(*pix);

    delete pix;
    pix = nullptr;

    /*使用 lastIndexOf 方法找到文件路径中最后一个 / 的位置。
使用 left 方法截取文件路径中的文件夹部分。
将当前文件夹路径保存到配置文件中，键为 /LastPath/path。*/
    int end = fileName.lastIndexOf("/");
    QString _path = fileName.left(end);
    pIniSet->setValue("/LastPath/path", _path);
    //delete pIniSet;
    //pIniSet = nullptr;
    qDebug() << _path;
}

void Widget::on_btnOpen_clicked()
{
    //open1();
    //open2();//记住上次文件路径
    //open3();//智能指针实现上次文件路径
    open4();//图片自适应
}

