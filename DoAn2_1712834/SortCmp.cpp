#include"SortAlg.h"

void(*SortAlg[8])(LargeInt*, int, LargeInt&, LargeInt&) = { 
SelectionSort,
InsertionSort,
ShellSort,
RadixSort,
HeapSort,
BubbleSort,
InterchangeSort,
ShakerSort 
};

void(*SortAlg2[2])(LargeInt*, int, int, LargeInt&, LargeInt&) = { 
QuickSort,
MergeSort
};

const char* name[10] = { 
"Quick Sort",
"MergeSort",
"Selection Sort",
"Insertion Sort",
"Shell Sort",
"Radix Sort",
"Heap Sort",
"Bubble Sort",
"Interchange Sort",
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

	printf("\nThoi gian chay: \"%f\" giay\n\n",time);
	
	char head[4] = " . ";
	head[0] = i + '1';
	char *filename = (char*)malloc(sizeof(char)*(strlen(name[i]) + 8));
	strcpy(filename, head);
	strcat(filename, name[i]);
	strcat(filename, ".txt");

	FILE *f = fopen(filename,"w");
	fprintf(f, "==== Mang sau khi duoc sap xep boi %s ======\n", name[i]);
	fprintf(f, "So phep gan : ");
	gan.printToFile(f);
	fprintf(f, "\t So phep so sanh: ");
	ss.printToFile(f);
	fprintf(f,"\n\n");
	for (int i = 0; i < n; i++) {
		arr[i].printToFile(f);
		fprintf(f, "\n");
	}

	free(filename);
	
	ss.eraseData();
	gan.eraseData();
}