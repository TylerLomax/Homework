#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QCoreApplication>

void Swap(int* nl, int* n2);

void fill_array_with_rand_num(int* array, int Size);

void BubbleSort(int* array, int Size);
void InsertionSort(int* array, int Size);
void SelectionSort(int* array, int Size);
void ShellSort(int* array, int Size);
void QuickSort(int* array, int Size);

void Merge(int* merged, int* L, int lenl, int* R, int lenR);
void MergeSort(int* array, int Size);

#endif//MAINWINDOW_H
