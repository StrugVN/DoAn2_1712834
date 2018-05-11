#include"SortAlg.h"

void SelectionSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Selection Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	SelectionSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;
	
	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void InterchangeSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Interchange Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	InterchangeSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void InsertionSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Insertion Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	InsertionSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;
	
	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void BubbleSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Bubble Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	BubbleSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void ShellSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Shell Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	ShellSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void QuickSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Quick Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	QuickSort(arr, 0, n-1, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void MergeSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Merge Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	MergeSort(arr, 0, n-1, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void RadixSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Radix Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	RadixSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;
	
	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void HeapSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Heap Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	HeapSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void ShakerSort_Report(int *arr, int n) {
	__int64 ss = 0, gan = 0;
	double time;
	printf("\t Shaker Sort voi \"%d\" phan tu:\n", n);

	clock_t s = clock();

	ShakerSort(arr, n, ss, gan);

	clock_t e = clock();

	time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}