#pragma once
#ifndef _SortAlg_h_
#define _SortAlg_h_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"LargeIntCal.h"

void swap(LargeInt &a, LargeInt &b, LargeInt& gan);

// Source_SortAlg.cpp
void SelectionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void InsertionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void InterchangeSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void BubbleSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void ShellSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void QuickSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan);
void MergeSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan);
void RadixSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void HeapSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);
void ShakerSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan);

// Source_SortCmp.cpp
void Report(LargeInt *arr, int n, int i);

#endif