#include "arrays.h"
#include "ui_arrays.h"
#include <QApplication>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <stdio.h>


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

void zapolnenie(int *matrix,int *br, int n)
{
    for(int i=0; i<n; i++)
    {
        matrix[i]=rand()%11;
        br[i]=matrix[i];
    }

}

double radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
    clock_t start = clock();

    int i,k,n,d=0;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
    {
        d++;
        br[cr[ar[i]]-1]=ar[i];
        cr[ar[i]]-=1;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    return seconds;
    ui->Time->setText(QString::number( seconds ));
    ui->Sravn ->setText(QString::number( d ));

    //printf("The time: %f seconds\n", seconds);
}

void Arrays::on_Run_clicked()
{
    int *matrix, *br, *cr, n, sizeC=10;
    n = ui-> SizeofArray -> text().toInt();
    double s;

    matrix=new int[n];
    br=new int[n];
    cr=new int[10];



    zapolnenie(matrix,br,n);

    if ((ui->RadixSort->isChecked())&&(ui->Medium->isChecked()))
    {
        radix(matrix,br,cr,sizeC,n);
        //ui->Time->setText(QString::number( s ));
    }


}
