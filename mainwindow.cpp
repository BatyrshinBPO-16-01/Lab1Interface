#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

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
    window1 = new Base(this);
    connect(window1, &Base::firstWindow, this, &MainWindow::show);
    window1->show();
}

void MainWindow::on_Arrays_clicked()
{
    hide();
    window2 = new Arrays(this);
    connect(window2, &Arrays::firstWindow, this, &MainWindow::show);
    window2->show();
}
