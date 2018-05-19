#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "base.h"
#include "arrays.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BaseOfData_clicked();

    void on_Arrays_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Base *window1;
    Arrays *window2;
};

#endif // MAINWINDOW_H
