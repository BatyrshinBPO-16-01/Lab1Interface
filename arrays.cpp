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
//-------------------------------------------------------------------

void LowA(int *arr1,int *matrix, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
        arr1[i]=matrix[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n ; j++)
        {
            if (arr1[j] > arr1[i])
            {
                temp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = temp;
            }
         }
     }
}

void BestA(int *arr2,int *matrix, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
        arr2[i]=matrix[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n ; j++)
        {
            if (arr2[j] < arr2[i])
            {
                temp = arr2[j];
                arr2[j] = arr2[i];
                arr2[i] = temp;
            }
         }
     }
}

void zapolnenie(int *matrix,int *br,int n, int size)
{
    for(int i=0; i<n; i++)
    {
        matrix[i]=rand()%(size+1);
        br[i]=matrix[i];
    }
}

void swapEl(int *arr, int i,int &p)
{
    int buff;
    buff = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buff;
    p++;
}

void ShakerSort(int *arr, int size, Ui::Arrays *ui)
{
    ui->First10->clear();
    ui->Last10->clear();

    int d=0,p=0,i;
    for(i=0; i<size; i++)
    {
        if (i<5)
        {
            ui->First10->insertPlainText(QString::number(arr[i]));
            ui->First10->insertPlainText("  ");
        }
        if (i==size-7) ui->First10->insertPlainText("| ");
        if (i>size-6)
        {
            ui->First10->insertPlainText(QString::number(arr[i]));
            ui->First10->insertPlainText("  ");
        }
    }

    clock_t start = clock();
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--)
        {
            d++;
            if (arr[i - 1] > arr[i]) swapEl(arr, i,p);
        }
        leftMark++;


        for (int i = leftMark; i <= rightMark; i++)
        {
            d++;
            if (arr[i - 1] > arr[i]) swapEl(arr, i,p);
        }
        rightMark--;
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    for(i=0; i<size; i++)
    {
        if (i<5)
        {
            ui->Last10->insertPlainText(QString::number(arr[i]));
            ui->Last10->insertPlainText("  ");
        }
        if (i==size-7) ui->Last10->insertPlainText("| ");
        if (i>size-6)
        {
            ui->Last10->insertPlainText(QString::number(arr[i]));
            ui->Last10->insertPlainText("  ");
        }
    }

    ui->Time->setText(QString::number( seconds ));
    ui->Sravn ->setText(QString::number( d ));
    ui->Perestan->setText(QString::number( p ));

}

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB, Ui::Arrays *ui)
{
    ui->First10->clear();
    ui->Last10->clear();
    clock_t start = clock();

    int i,k,n,d=0,p=0;
    k = sizeC;
    n = sizeAB;
    for(i=0; i<n; i++)
    {
        if (i<5)
        {
            ui->First10->insertPlainText(QString::number(ar[i]));
            ui->First10->insertPlainText("  ");
        }
        if (i==n-7) ui->First10->insertPlainText("| ");
        if (i>n-6)
        {
            ui->First10->insertPlainText(QString::number(ar[i]));
            ui->First10->insertPlainText("  ");
        }
    }

    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
    {
        br[cr[ar[i]]-1]=ar[i];
        cr[ar[i]]-=1;
        p++;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    ui->Time->setText(QString::number( seconds ));
    ui->Sravn ->setText(QString::number( d ));
    ui->Perestan->setText(QString::number( p ));

    for(i=0; i<n; i++)
    {
        if (i<5)
        {
            ui->Last10->insertPlainText(QString::number(br[i]));
            ui->Last10->insertPlainText("  ");
        }
        if (i==n-7) ui->Last10->insertPlainText("| ");
        if (i>n-6)
        {
            ui->Last10->insertPlainText(QString::number(br[i]));
            ui->Last10->insertPlainText("  ");
        }
    }

}

void Merge(int *a, int n, Ui::Arrays *ui)
{
    ui->First10->clear();
    ui->Last10->clear();

    for(int i=0; i<n; i++)
    {
        if (i<5)
        {
            ui->First10->insertPlainText(QString::number(a[i]));
            ui->First10->insertPlainText("  ");
        }
        if (i==n-7) ui->First10->insertPlainText("| ");
        if (i>n-6)
        {
            ui->First10->insertPlainText(QString::number(a[i]));
            ui->First10->insertPlainText("  ");
        }
    }

    int mid = n / 2, h = 1,step,d=0,p=0;
    if (n % 2 == 1)
        mid++;

    int *c = new int[n];
    clock_t start = clock();
    while (h < n)
    {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            {
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++; k++;
                }
                else
                {
                    c[k] = a[j];
                    j++; k++;
                }
            }

            while (i < step)
            {
                c[k] = a[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j<n))
            {
                c[k] = a[j];
                j++; k++;
            }
            step = step + h;
        }

        h = h * 2;
        for (i = 0; i<n; i++)
            a[i] = c[i];
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    ui->Time->setText(QString::number( seconds ));
    ui->Sravn ->setText(QString::number( d ));
    ui->Perestan->setText(QString::number( p ));

    for(int i=0; i<n; i++)
    {
        if (i<5)
        {
            ui->Last10->insertPlainText(QString::number(a[i]));
            ui->Last10->insertPlainText("  ");
        }
        if (i==n-7) ui->Last10->insertPlainText("| ");
        if (i>n-6)
        {
            ui->Last10->insertPlainText(QString::number(a[i]));
            ui->Last10->insertPlainText("  ");
        }
    }

    delete c[];
}

void Arrays::on_Run_clicked()
{
    int *matrix,*arr1,*arr2, *br, *cr, n, size=100;
    n = ui-> SizeofArray -> text().toInt();
    srand(time(0));

    matrix=new int[n];
    br=new int[n];
    cr=new int[size];
    arr1=new int[n];
    arr2=new int[n];

    zapolnenie(matrix,br,n,size);

    LowA(arr1,matrix,n);
    BestA(arr2,matrix,n);

    if ((ui->ShakerSort->isChecked())&&(ui->Medium->isChecked()))
        ShakerSort(matrix, n, ui);
    if ((ui->ShakerSort->isChecked())&&(ui->Low->isChecked()))
        ShakerSort(arr1, n, ui);
    if ((ui->ShakerSort->isChecked())&&(ui->Best->isChecked()))
        ShakerSort(arr2, n, ui);

    if ((ui->RadixSort->isChecked())&&(ui->Medium->isChecked()))
        radix(matrix,br,cr,size,n, ui);
    if ((ui->RadixSort->isChecked())&&(ui->Low->isChecked()))
        radix(arr1,br,cr,size,n, ui);
    if ((ui->RadixSort->isChecked())&&(ui->Best->isChecked()))
        radix(arr2,br,cr,size,n, ui);

    if ((ui->MergeSort->isChecked())&&(ui->Medium->isChecked()))
        Merge(matrix,n, ui);
    if ((ui->MergeSort->isChecked())&&(ui->Low->isChecked()))
        Merge(arr1,n, ui);
    if ((ui->MergeSort->isChecked())&&(ui->Best->isChecked()))
        Merge(arr2,n, ui);

    delete []matrix;
    delete []arr1;
    delete []arr2;
    delete []br;
    delete []cr;
}
