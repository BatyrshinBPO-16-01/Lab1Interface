#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "baza.h"
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

    void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
    Baza *window1;
    Arrays *window2;
};

#endif // MAINWINDOW_H
