#include "base.h"
#include "ui_base.h"
#include <QApplication>
#include <QMessageBox>

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

void Base::on_Prev_clicked()
{

    QMessageBox::StandardButton reply=QMessageBox::question(this, "Выход", "Выйти в главное окно?", QMessageBox::Yes| QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->close();
        emit firstWindow();
    }
}
