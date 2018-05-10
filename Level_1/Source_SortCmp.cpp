#include"SortAlg.h"

void SelectionSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();
	SelectionSort(arr, n, ss, gan);
	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Selection Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void InterchangeSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	InterchangeSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Interchange Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void InsertionSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	InsertionSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Insertion Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void BubbleSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	BubbleSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Bubble Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void ShellSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	ShellSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Shell Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void QuickSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	QuickSort(arr, 0, n-1, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Quick Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void MergeSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	MergeSort(arr, 0, n-1, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Merge Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void RadixSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	RadixSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Radix Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void HeapSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	HeapSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Heap Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}

void ShakerSort_Report(int *arr, int n) {
	int ss = 0, gan = 0;
	double time;
	clock_t s = clock();

	ShakerSort(arr, n, ss, gan);

	clock_t e = clock();
	time = (double)(e - s) / CLOCKS_PER_SEC;
	printf("============= Shaker Sort voi \"%d\" phan tu:\n", n);
	printf(" ===> So phep gan: \"%d\"\t So phep so sanh: \"%d\'\t Thoi gian chay: \"%f\" giay", gan, ss, time);
}