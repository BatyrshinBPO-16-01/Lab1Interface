#include "base.h"
#include "ui_base.h"

Base::Base(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Base)
{
    ui->setupUi(this);
}

Base::~Base()
{
    delete ui;
}

void Base::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
