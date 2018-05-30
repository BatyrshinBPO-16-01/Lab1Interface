#ifndef ARRAYS_H
#define ARRAYS_H

#include <QDialog>

namespace Ui {
class Arrays;
}

class Arrays : public QDialog
{
    Q_OBJECT

public:
    explicit Arrays(QWidget *parent = 0);
    ~Arrays();

signals:
    void firstWindow();

private slots:
    void on_Prev_clicked();

    void on_Run_clicked();

private:
    Ui::Arrays *ui;
};

#endif // ARRAYS_H
