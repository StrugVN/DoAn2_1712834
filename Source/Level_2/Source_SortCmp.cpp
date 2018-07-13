#include"SortAlg.h"

void(*SortAlg[7])(int*, int, __int64&, __int64&) = {
	SelectionSort,
	InsertionSort,
	ShellSort,
	RadixSort,
	HeapSort,
	BubbleSort,
	ShakerSort
};

void(*SortAlg2[2])(int*, int, int, __int64&, __int64&) = {
	QuickSort,
	MergeSort
};

const char* name[9] = {
	"Quick Sort",
	"MergeSort",
	"Selection Sort",
	"Insertion Sort",
	"Shell Sort",
	"Radix Sort",
	"Heap Sort",
	"Bubble Sort",
	"Shaker Sort"
};

void Report(int *arr, int n, int i) {
	__int64 ss = 0, gan = 0;

	printf("\t %s voi \"%d\" phan tu:\n", name[i], n);

	clock_t s = clock();

	if (i < 2)
		SortAlg2[i](arr, 0, n - 1, ss, gan);
	else
		SortAlg[i - 2](arr, n, ss, gan);

	clock_t e = clock();

	double time = (double)(e - s) / CLOCKS_PER_SEC;

	printf(" ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\t Thoi gian chay: \"%f\" giay\n\n", gan, ss, time);

	char head[4] = " . ";
	head[0] = i + '1';
	char *filename = (char*)malloc(sizeof(char)*(strlen(name[i]) + 8));
	strcpy(filename, head);
	strcat(filename, name[i]);
	strcat(filename, ".txt");

	FILE *f = fopen(filename, "w");

	fprintf(f, "==== Mang sau khi duoc sap xep boi %s ======\n", name[i]);
	fprintf(f, " ===> So phep gan: \"%llu\"\t So phep so sanh: \"%llu\'\nThoi gian chay: \"%f\" giay\n\n", gan, ss, time);

	for (int i = 0; i < n; i++) {
		fprintf(f, "%d\n", arr[i]);
	}

	fclose(f);
}

void RunAllTest(int *arr, int n) {
	int *temp = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < n; j++)
			temp[j] = arr[j];

		Report(temp, n, i);
	}

	free(temp);
}

void RunTest(int *arr, int n) {
	int i;

	printf("\nHay chon thuat toan can chay: (Hay chay tung thuat rieng voi N>=1000000)\n");

	printf("0. Chay toan bo thuat toan\n");
	for (int i = 1; i <= 9; i++)
		printf("%d. Chay thuat toan \"%s\"\n", i, name[i - 1]);

	printf("\nLua chon cua ban: ");
	scanf("%d", &i);

	if (i > 0 && i <= 9)
		Report(arr, n, i - 1);
	else {
		printf("Chay toan bo thuat: \n\n");
		RunAllTest(arr, n);
	}
}