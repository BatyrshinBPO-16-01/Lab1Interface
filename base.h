#ifndef BASE_H
#define BASE_H

#include <QDialog>

namespace Ui {
class Base;
}

class Base : public QDialog
{
    Q_OBJECT

public:
    explicit Base(QWidget *parent = 0);
    ~Base();

private slots:
    void on_Prev_clicked();

signals:
    void firstWindow();

private:
    Ui::Base *ui;
};

#endif // BASE_H
