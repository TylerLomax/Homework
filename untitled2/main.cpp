#include "mainwindow.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <sysinfoapi.h>
#include <QDebug>
#include "mainwindow.h"
#define NUMBER_OF_SORT_FUNC 6

int getTimeOfOperation(int i, int* ptrArray, int Size, void
(*ptrSortFuncArray[NUMBER_OF_SORT_FUNC]) (int*, int)) {
int tick_start;
int tick_end;

tick_start = GetTickCount();
ptrSortFuncArray[i] (ptrArray, Size);
tick_end = GetTickCount();

return tick_end - tick_start;
}
void load_DATA_to_File(int* ptrArray, QString fname) {
QTextStream stream(stdout);
QFile sort_result_file(fname);

if (sort_result_file. open(QIODevice::WriteOnly)){


QTextStream stream(&sort_result_file);

int TimeOfOperation;
void ( *ptrSortFuncArray[ NUMBER_OF_SORT_FUNC])(int*,int)= {BubbleSort, SelectionSort,InsertionSort, QuickSort, MergeSort};

for (int i = 0; i <NUMBER_OF_SORT_FUNC; ++i){

    TimeOfOperation = 0;
stream << "Next sort\n";

int Size = 100;
while (TimeOfOperation < 1'000 && Size <= 500'000)
{
ptrArray = new (std:: nothrow) int[Size];

fill_array_with_rand_num(ptrArray, Size);

TimeOfOperation = getTimeOfOperation(i, ptrArray, Size,ptrSortFuncArray);
stream << TimeOfOperation << "\n";
Size += 100;

delete[] ptrArray;
ptrArray = nullptr;
}

}

sort_result_file.close();
}
else
    qWarning("Error! Can't open file.");

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int* array = nullptr;
            QString filename = "SortResultData.txt";
   load_DATA_to_File(array,filename);
    return a.exec();
}
