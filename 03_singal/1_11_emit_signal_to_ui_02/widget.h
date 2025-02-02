#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "childthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnUpdate_clicked();
    void showInfo(Score s);

    //void sig2(string name, int id, int age);
    void showInfo2(string name, int id);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
