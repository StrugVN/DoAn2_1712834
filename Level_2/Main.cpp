#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#include"SortAlg.h"
#include"Cal.h"

char* readALine(FILE *f) {
	char *str = (char*)malloc(sizeof(char));

	char c = fgetc(f);
	int n = 1;
	while (1) {
		if (feof(f)) {
			free(str);
			str = NULL;
			break;
		}
		if (c == '\n') {
			str = (char*)realloc(str, n * sizeof(char));	// *Fixed
			str[n - 1] = '\0';
			break;
		}
		str = (char*)realloc(str, (n + 1) * sizeof(char));
		str[n - 1] = c;
		c = fgetc(f);
		n++;
	}

	return str;
}

int* loadTestFromFile(const char* filePath, int n) {	// Lấy n hàng từ file tính thành số và đưa vào mảng
	FILE *f;
	f = fopen(filePath, "r");

	int *a = (int*)malloc(sizeof(int)*n);

	if (f == NULL) {
		printf("Mo file that bai, cac phan tu se duoc rand thay the!\n");
		for (int i = 0; i < n; i++)
			a[i] = rand();

		return a;
	}

	int i = 0;

	char *str = readALine(f);
	while (str && i<n) {
		double kq;

		if (TinhBieuThuc(str, kq)) {
			a[i] = (int)kq;

			if (a[i] < 0) {		// Xử lí âm (vì Radix Sort và chủ yếu vượt INT_MAX)
				printf("Bieu thuc thu %d ra gia tri am (hoac vuot INT_MAX) nen se duoc rand() thay the.\n", i);
				a[i] = rand();	// Vì theo trị INT_MIN = INT_MAX + 1 (số 0 là số dương) đổi dấu vẫn ko giải quyết đc, nếu thay đổi trị của biểu thức thay vì vậy rand() luôn cho rồi.
			}
		}
		else {
			printf("Loi o dong thu %d, phan tu thu %d se duoc rand thay the!\n", i + 1, i);
			a[i] = rand();
		}

		free(str);
		str = readALine(f);

		i++;
	}

	if (i < n) {
		printf("Chi tim thay trong file %d bieu thuc, cac phan tu con lai se duoc rand thay the!\n", i);
	}
	else
		printf("Da load thanh cong toan bo file\n");

	while (i < n) {
		a[i] = rand();
		i++;
	}

	return a;
}

int main() {
	srand(time(NULL));
	int n;
	char *file = NULL;

	printf("Nhap so phan tu: ");
	scanf("%d%*c", &n);
	printf("Nhap ten file: ");
	file = readALine(stdin);

	int *mau = loadTestFromFile(file, n);
	free(file);

	printf("Ket thuc ham load, bam phim bat ki de tiep tuc\n");
	_getche();

	for (int i = 0; i < n; i++)
		printf("%d %d\n",i ,mau[i]);

	int *temp = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < 10; i++) {
		memcpy(temp, mau, sizeof(int)*n);
		Report(temp, n, i);
	}
	free(temp);
	free(mau);

	_getche();

	_getche();
	return 0;
}