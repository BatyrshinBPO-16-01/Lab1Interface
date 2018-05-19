#include "arrays.h"
#include "ui_arrays.h"

Arrays::Arrays(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arrays)
{
    ui->setupUi(this);
}

Arrays::~Arrays()
{
    delete ui;
}

void Arrays::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
