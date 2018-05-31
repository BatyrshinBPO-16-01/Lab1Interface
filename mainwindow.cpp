#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>

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


void MainWindow::on_BaseOfData_clicked()
{
    hide();
    window1 = new Baza(this);
    connect(window1, &Baza::firstWindow, this, &MainWindow::show);
    window1->show();
}

void MainWindow::on_Arrays_clicked()
{
    hide();
    window2 = new Arrays(this);
    connect(window2, &Arrays::firstWindow, this, &MainWindow::show);
    window2->show();
}

void MainWindow::on_Exit_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this, "Выход", "Выйти из приложения?", QMessageBox::Yes| QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}
