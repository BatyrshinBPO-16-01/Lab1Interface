#include "arrays.h"
#include "ui_arrays.h"
#include <QApplication>
#include <QMessageBox>

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

void Arrays::on_Prev_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this, "Выход", "Выйти в главное окно?", QMessageBox::Yes| QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->close();
        emit firstWindow();
    }
}

void Arrays::on_Run_clicked()
{
    int n = ui-> SizeofArray -> text().toInt();



}
