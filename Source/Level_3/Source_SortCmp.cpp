#include"SortAlg.h"

void(*SortAlg[7])(LargeInt*, int, LargeInt&, LargeInt&) = {
	SelectionSort,
	InsertionSort,
	ShellSort,
	RadixSort,
	HeapSort,
	BubbleSort,
	ShakerSort
};

void(*SortAlg2[2])(LargeInt*, int, int, LargeInt&, LargeInt&) = {
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

void Report(LargeInt *arr, int n, int i) {
	LargeInt ss, gan;

	ss.getFromStr("0");
	gan.getFromStr("0");

	printf("=== %s voi \"%d\" phan tu:", name[i], n);

	clock_t s = clock();

	if (i < 2)
		SortAlg2[i](arr, 0, n - 1, ss, gan);
	else
		SortAlg[i - 2](arr, n, ss, gan);

	clock_t e = clock();

	double time = (double)(e - s) / CLOCKS_PER_SEC;

	printf("\nSo phep gan : ");
	gan.print();

	printf("\tSo phep so sanh: ");
	ss.print();

	printf("\nThoi gian chay: \"%f\" giay\n\n", time);

	char head[4] = " . ";
	head[0] = i + '1';
	char *filename = (char*)malloc(sizeof(char)*(strlen(name[i]) + 8));
	strcpy(filename, head);
	strcat(filename, name[i]);
	strcat(filename, ".txt");

	FILE *f = fopen(filename, "w");

	fprintf(f, "==== Mang sau khi duoc sap xep boi %s ======\n", name[i]);
	fprintf(f, "So phep gan : ");
	gan.printToFile(f);
	fprintf(f, "\t So phep so sanh: ");
	ss.printToFile(f);
	fprintf(f, "\nThoi gian chay: \"%f\" giay\n\n", time);
	for (int i = 0; i < n; i++) {
		arr[i].printToFile(f);
		fprintf(f, "\n");
	}

	free(filename);
	fclose(f);
	ss.eraseData();
	gan.eraseData();
}

void RunAllTest(LargeInt *arr, int n) {
	LargeInt *temp = (LargeInt*)malloc(sizeof(LargeInt)*n);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < n; j++)
			temp[j] = arr[j].Duplicate();

		Report(temp, n, i);

		for (int j = 0; j < n; j++)
			temp[j].eraseData();
	}

	free(temp);
}

void RunTest(LargeInt *arr, int n) {
	int i;

	printf("\nHay chon thuat toan can chay: (Hay chay tung thuat rieng voi N>=100000)\n");

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