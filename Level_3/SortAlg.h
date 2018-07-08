#define _CRT_SECURE_NO_WARNINGS
#ifndef _SortAlg_h_
#define _SortAlg_h_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"LargeNum.h"

void swap(LargeInt &a, LargeInt &b, LargeInt& gan);

// Source_SortAlg.cpp
void SelectionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void InsertionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void BubbleSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void ShellSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void QuickSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan);
void MergeSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan);
void RadixSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void HeapSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void ShakerSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);

// Source_SortCmp.cpp
void RunTest(LargeInt *arr, int n);

#endif