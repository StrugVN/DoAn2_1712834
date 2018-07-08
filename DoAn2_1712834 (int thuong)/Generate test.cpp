#include"Generate test.h"

void CreateTest(int *arr, int n) {
	for (int i = 0; i < n; i++)
		arr[i] = rand()*(RAND_MAX+1) + rand();

	FILE *f = fopen("0. Sample test.txt", "w");

	fprintf(f, "Mang %d phan tu ban dau:\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(f, "%d\n",arr[i]);
	}

	printf("\n ===> Xem file \"0. Sample test.txt\" de xem mang duoc phat sinh ngau nhien.\n\n");

	fclose(f);
}

bool CheckFile(const char* filename) {
	FILE *f = fopen(filename, "r");

	if (f) {
		fclose(f);
		return true;
	}
	else
		return false;
}

void LoadTest(int *&arr, int &n, const char *filename) {
	FILE *f = fopen(filename, "r");

	fscanf(f, "Mang %d phan tu ban dau:\n", &n);

	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
		fscanf(f, "%d\n", &arr[i]);
}

void NewTest(int *&arr, int &n) {
	printf("Nhap so phan tu cua mang can test: ");
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);

	CreateTest(arr, n);
}

void generateTest(int *&arr, int &n) {
	if (CheckFile("0. Sample test.txt")) {
		char c;
		printf("Phat hien ton tai file chua mang ban dau, load mang tu file cu?\n");
		printf("Nhap Y/N: ");
		scanf("%c", &c);

		if (c == 'y' || c == 'Y') {
			LoadTest(arr, n, "0. Sample test.txt");
			return;
		}
	}

	NewTest(arr, n);
}