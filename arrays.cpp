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

void swapEl(int *arr, int i)
{
    int buff;
    buff = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buff;
}
void ShakerSort(int *arr, int size, Ui::Arrays *ui)
{
    int d=0;
    clock_t start = clock();
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        if (arr[i - 1] > arr[i]) swapEl(arr, i);
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
        if (arr[i - 1] > arr[i]) swapEl(arr, i);
        rightMark--;

        d++;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    ui->Time->setText(QString::number( seconds ));
    ui->Sravn ->setText(QString::number( d ));

}

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB, Ui::Arrays *ui)
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
        //if ((cr % 2)==0) d++;
        br[cr[ar[i]]-1]=ar[i];
        cr[ar[i]]-=1;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    ui->Time->setText(QString::number( seconds ));
    ui->Sravn ->setText(QString::number( d ));

}

void Arrays::on_Run_clicked()
{
    int *matrix, *br, *cr, n, sizeC=10;
    n = ui-> SizeofArray -> text().toInt();

    matrix=new int[n];
    br=new int[n];
    cr=new int[10];



    zapolnenie(matrix,br,n);

    if ((ui->RadixSort->isChecked())&&(ui->Medium->isChecked()))
        radix(matrix,br,cr,sizeC,n, ui);

    if ((ui->ShakerSort->isChecked())&&(ui->Medium->isChecked()))
        ShakerSort(matrix, n, ui);


}

void Arrays::on_pushButton_clicked()
{
    ui->Time->clear();
    ui->Sravn ->clear();
    ui->Perestan->clear();

}
