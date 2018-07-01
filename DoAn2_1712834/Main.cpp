#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"SortAlg.h"

void BigNumberGenerator(LargeInt &a, int numberOfDigit) {
	int n = rand() % 6 + numberOfDigit - 2;
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

	fprintf(f, "Mang %d phan tu ban dau:\n",n);
	for (int i = 0; i < n; i++) {
		arr[i].printToFile(f);
		fprintf(f, "\n");
	}

	printf(" ---> Xem file \"0. Sample test.txt\" de xem mang ban dau.\n");
}

int main() {
	int n, numOfDigit;

	printf("=========== Do An 2 - KTLT - 1712834 ===========\n\n");
	printf("Nhap so phan tu cua mang can test: ");
	scanf("%d", &n);
	printf("Nhap do lon cua moi phan tu (so chu so): ");
	scanf("%d", &numOfDigit);

	LargeInt *a = (LargeInt*)malloc(sizeof(LargeInt)*n);
	for (int i = 0; i < n; i++) {
		a[i].list.head = NULL;
		a[i].list.tail = NULL;
	}

	CreateTest(a, n, numOfDigit);

	LargeInt *temp = (LargeInt*)malloc(sizeof(LargeInt)*n);

	for (int i = 0; i < 10; i++) {
		for (int l = 0; l < n; l++)
			temp[l] = a[l].Duplicate();

		Report(temp, n, i);

		for (int l = 0; l < n; l++)
			temp[l].eraseData();
	}

	printf(" --> Xem file \"i. [ten kieu sort].txt\" de xem thong tin va mang da sap xep.\n");

	for (int i = 0; i < n; i++)
		a[i].eraseData();
	free(a);
	free(temp);

	_getche();
	return 0;
}