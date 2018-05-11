#include<stdio.h>
#include<conio.h>
#include<memory.h>
#include"SortAlg.h"


void(*SortAlg[10])(int*, int) = { SelectionSort_Report,
								InterchangeSort_Report,
								InsertionSort_Report,
								ShellSort_Report,
								QuickSort_Report,
								MergeSort_Report,
								RadixSort_Report,
								HeapSort_Report,
								BubbleSort_Report,
								ShakerSort_Report };

int numOfAlg = 10;

int* CreateTest(int n) {
	int *arr = (int*)malloc(sizeof*arr * n);
	for (int i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}

int main() {
	srand(NULL);
	
	for (int n = 1000; n <= 1000000; n*=10) {
		int *arr = CreateTest(n);

		int *a = (int*)malloc(sizeof*a*n);
		memcpy(a, arr, sizeof*a*n);
		
		for (int i = 0; i < numOfAlg; i++) {
			SortAlg[i](a, n);
			printf("\n-------------------------------------------------\n");
			memcpy(a, arr, sizeof*a*n);		// Reset
		}
		

		free(a);
		free(arr);
		printf("\n\n====================================================\n\n");
	}
	
	_getche();
	_getche(); _getche(); _getche(); _getche(); _getche();
	return 0;
}