#pragma once
#ifndef _SortAlg_h_
#define _SortAlg_h_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Queue.h"

void SelectionSort(int *arr, int n, int &ss, int &gan);
void InsertionSort(int *arr, int n, int &ss, int &gan);
void InterchangeSort(int *arr, int n, int &ss, int &gan);
void BubbleSort(int *arr, int n, int &ss, int &gan);
void ShellSort(int *arr, int n, int &ss, int &gan);
void QuickSort(int *arr, int l, int r, int &ss, int &gan);
void MergeSort(int *arr, int l, int r, int &ss, int &gan);
void RadixSort(int *arr, int n, int &ss, int &gan);
void HeapSort(int arr[], int n, int &ss, int &gan);

#endif