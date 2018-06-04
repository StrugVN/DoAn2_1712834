#include"SortAlg.h"

void(*SortAlg[8])(int*, int, __int64&, __int64&) = { SelectionSort,
													InsertionSort,
													ShellSort,
													RadixSort,
													HeapSort,
													BubbleSort,
													InterchangeSort,
													ShakerSort };

void(*SortAlg2[2])(int*, int, int, __int64&, __int64&) = { QuickSort,
															MergeSort };

const char* name[10] = { "Quick Sort",
						"MergeSort",
						"Selection Sort",
						"Insertion Sort",
						"Shell Sort",
						"Radix Sort",
						"Heap Sort",
						"Bubble Sort",
						"Interchange Sort",
						"Shaker Sort" };

void Report(int *arr, int n, int i) {
	__int64 ss = 0, gan = 0;

	printf("\t %s voi \"%d\" phan tu:\n", name[i] , n);

	clock_t s = clock();

	if (i < 2)
		SortAlg2[i](arr, 0, n - 1, ss, gan);
	else
		SortAlg[i - 2](arr, n, ss, gan);

	clock_t e = clock();

	double time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay\n\n", gan, ss, time);
}