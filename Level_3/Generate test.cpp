#include"Generate test.h"

void BigNumberGenerator(LargeInt &a, int numberOfDigit) {
	int n = rand()%6 - 3 + numberOfDigit;
	char *str = (char*)malloc(sizeof(char)*(n + 1));

	str[n] = '\0';

	str[0] = rand() % 10 + '1';

	for (int i = 1; i < n; i++)
		str[i] = (rand() % 10) + '0';

	a.getFromStr(str);
	free(str);
}

void CreateTest(LargeInt *arr, int n, int numberOfDigit) {
	for (int i = 0; i < n; i++)
		BigNumberGenerator(arr[i], numberOfDigit);

	FILE *f = fopen("0. Sample test.txt", "w");

	fprintf(f, "Mang %d phan tu ban dau:\n", n);
	for (int i = 0; i < n; i++) {
		arr[i].printToFile(f);
		fprintf(f, "\n");
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

void LoadTest(LargeInt *&arr, int &n, const char *filename) {
	FILE *f = fopen(filename, "r");

	char temp[1000];
	fscanf(f, "Mang %d phan tu ban dau:\n", &n);

	arr = (LargeInt*)malloc(sizeof(LargeInt)*n);
	for (int i = 0; i < n; i++) {
		arr[i].list.head = NULL;
		arr[i].list.tail = NULL;
	}

	for (int i = 0; i < n; i++) {
		fgets(temp, 1000, f);
		temp[strlen(temp)-1] = '\0';
		arr[i].getFromStr(temp);
	}
}

void NewTest(LargeInt *&arr, int &n) {
	int numOfDigit;
	printf("Nhap so phan tu cua mang can test: ");
	scanf("%d", &n);
	printf("Nhap do lon cua moi phan tu (so chu so): ");
	scanf("%d", &numOfDigit);

	arr = (LargeInt*)malloc(sizeof(LargeInt)*n);
	for (int i = 0; i < n; i++) {
		arr[i].list.head = NULL;
		arr[i].list.tail = NULL;
	}

	CreateTest(arr, n, numOfDigit);
}

void generateTest(LargeInt *&arr, int &n) {
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