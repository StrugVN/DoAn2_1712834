#pragma once
#ifndef _SortAlg_h_
#define _SortAlg_h_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"Queue.h"

// Source_SortAlg.cpp
void SelectionSort(int *arr, int n, __int64 &ss, __int64 &gan);
void InsertionSort(int *arr, int n, __int64 &ss, __int64 &gan);
void InterchangeSort(int *arr, int n, __int64 &ss, __int64 &gan);
void BubbleSort(int *arr, int n, __int64 &ss, __int64 &gan);
void ShellSort(int *arr, int n, __int64 &ss, __int64 &gan);
void QuickSort(int *arr, int l, int r, __int64 &ss, __int64 &gan);
void MergeSort(int *arr, int l, int r, __int64 &ss, __int64 &gan);
void RadixSort(int *arr, int n, __int64 &ss, __int64 &gan);
void HeapSort(int *arr, int n, __int64 &ss, __int64 &gan);
void ShakerSort(int *arr, int n, __int64 &ss, __int64 &gan);

// Source_SortCmp.cpp
void SelectionSort_Report(int *arr, int n);
void InterchangeSort_Report(int *arr, int n);
void InsertionSort_Report(int *arr, int n);
void BubbleSort_Report(int *arr, int n);
void ShellSort_Report(int *arr, int n);
void QuickSort_Report(int *arr, int n);
void MergeSort_Report(int *arr, int n);
void RadixSort_Report(int *arr, int n);
void HeapSort_Report(int *arr, int n);
void ShakerSort_Report(int *arr, int n);

#endif