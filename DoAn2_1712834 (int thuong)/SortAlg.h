#pragma once
#ifndef _SortAlg_h_
#define _SortAlg_h_
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

// Source_SortAlg.cpp
void SelectionSort(int *arr, int n, __int64 &ss, __int64 &gan);
void InsertionSort(int *arr, int n, __int64 &ss, __int64 &gan);
void BubbleSort(int *arr, int n, __int64 &ss, __int64 &gan);
void ShellSort(int *arr, int n, __int64 &ss, __int64 &gan);
void QuickSort(int *arr, int l, int r, __int64 &ss, __int64 &gan);
void MergeSort(int *arr, int l, int r, __int64 &ss, __int64 &gan);
void RadixSort(int *arr, int n, __int64 &ss, __int64 &gan);
void HeapSort(int *arr, int n, __int64 &ss, __int64 &gan);
void ShakerSort(int *arr, int n, __int64 &ss, __int64 &gan);

// Source_SortCmp.cpp
void Report(int *arr, int n, int i);
void RunAllTest(int *arr, int n);
void RunTest(int *arr, int n);

#endif