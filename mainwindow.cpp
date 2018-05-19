#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked()
{


}

void MainWindow::on_radioButton_3_clicked()
{
    ui ->textBrowser ->append(" ");

}



void MainWindow::on_radioButton_4_clicked()
{
    ui ->textBrowser ->append("Azm ");
}
