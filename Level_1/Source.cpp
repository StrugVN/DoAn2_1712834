#include<stdio.h>
#include<conio.h>
#include"SortAlg.h"


void(*SortAlg[10])(int*, int) = { SelectionSort_Report,
								InterchangeSort_Report,
								InsertionSort_Report,
								BubbleSort_Report,
								ShellSort_Report,
								QuickSort_Report,
								MergeSort_Report,
								RadixSort_Report,
								HeapSort_Report,
								ShakerSort_Report };

int numOfAlg = 10;

int main() {
	srand(NULL);
	int *a = (int*)malloc(sizeof*a * 10000);
	for (int i = 0; i < 10000; i++)
		a[i] = rand();
	int n = 10000;
	
	for (int i = 0; i < numOfAlg; i++) {
		SortAlg[i](a, n);
		for (int i = 0; i < 10000; i++)	// Xáo trộn lại mảng
			a[i] = rand();
		printf("\n\n-------------------------------------------------\n\n");
	}
	
	free(a);
	_getche();
	return 0;
}