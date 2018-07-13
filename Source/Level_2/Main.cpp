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

			if (a[i] < 0) {	
				a[i] *= -1;
				if (a[i] < 0) {
					printf("Bieu thuc %d ra gia tri vuot INT_MAX, phan tu thu %d se duoc rand() thay the!\n", i + 1, i);
					a[i] = rand();
				}
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
	srand((unsigned int)time(NULL));
	int n;
	char *file = NULL;

	printf("=========== Do An 2 - KTLT - 1712834 - LEVEL 2 ===========\n\n");

	printf("Nhap so phan tu: ");
	scanf("%d%*c", &n);
	printf("Nhap ten file: ");
	file = readALine(stdin);

	int *a = loadTestFromFile(file, n);
	free(file);

	printf("Ket thuc ham load\n");

	RunTest(a, n);

	printf(" ===> Xem file \"i. [ten kieu sort].txt\" de xem thong tin va mang da sap xep.\n");
	
	free(a);

	_getche();
	return 0;
}