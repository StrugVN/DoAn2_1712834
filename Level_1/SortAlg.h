#pragma once
#ifndef _SortAlg_h_
#define _SortAlg_h_

#include<stdio.h>
#include<stdlib.h>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

/*
void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
*/

// ========================= Selection Sort ==============================
int* getMin(int *arr, int n) {	
	int *temp = arr;
	for (int i = 1; i < n; i++)
		if (*temp > arr[i])
			temp = arr + i;
	return temp;
}

void SelectionSort(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int *t = getMin(arr+i, n-i);
		if (t != arr + i)
			swap(arr[i], *t);
	}
}
// ===================================================================


// ========================= Insertion Sort ==============================
int BinarySearch(int *arr, int n, int x) {
	int left, right, mid;
	left = 0;
	right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

void InsertionSort(int *arr, int n) {
	for (int i = 1; i < n; i++) {
		int x = arr[i];
		int pos = BinarySearch(arr, i, x);
		
		for (int j = i; j > pos; j--)
			arr[j] = arr[j - 1];

		arr[pos] = x;
	}
}
// ===================================================================


// ========================= Interchange Sort ==========================
void InterchangeSort(int *arr, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}
// =====================================================================


// ========================= Bubble Sort ==========================
void BubbleSort(int *arr, int n) {
	for (int i = 0; i < n-1; i++)
		for (int j = n-1; j > i; j--)
			if (arr[j] < arr[j-1])
				swap(arr[j], arr[j-1]);
}
// =====================================================================


// ========================= Shell Sort ===============================
void ShellSort(int *arr, int n) {
	for (int size = n / 2; size > 0; size /= 2) {
		for (int i = size; i < n; i++) {
			int x = arr[i];

			int j = i;
			while (j >= size && arr[j - size] > x) {
				arr[j] = arr[j - size];
				j -= size;
			}

			arr[j] = x;
		}
	}
}
// ====================================================================


// ========================= Quick Sort ===============================
void QuickSort(int *arr, int l, int r) {
	if (l <= r)
	{
		int x = arr[(l + r) / 2];

		int i = l;
		int j = r;

		while (i <= j)
		{
			while (arr[i] < x)
				i++;
			while (arr[j] > x)
				j--;

			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}

		if (l < j)
			QuickSort(arr, l, j);
		if (r > i)
			QuickSort(arr, i, r);
	}
}
// ====================================================================


// ======================== Merge Sort ================================
void Merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = (int*)malloc(sizeof(int)*n1), 
		*R = (int*)malloc(sizeof(int)*n2);

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void MergeSort(int *arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}
// ====================================================================

#endif