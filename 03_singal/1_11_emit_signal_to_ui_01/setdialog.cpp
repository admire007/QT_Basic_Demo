#include "setdialog.h"
#include "ui_setdialog.h"

SetDialog::SetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetDialog)
{
    ui->setupUi(this);
}

SetDialog::~SetDialog()
{
    delete ui;
}

void SetDialog::on_btnAdd_clicked()
{
    static int value = 100;
    emit sig_addOne(value++);
}
