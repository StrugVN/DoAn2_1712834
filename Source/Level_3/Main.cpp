#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"LargeIntCal.h"
#include"SortAlg.h"
#include"Generate test.h"

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

LargeInt* loadTestFromFile(const char* filePath, int n) {	// Lấy n hàng từ file tính thành số và đưa vào mảng
	FILE *f;
	f = fopen(filePath, "r");

	LargeInt *a = (LargeInt*)malloc(sizeof(LargeInt)*n);

	for (int i = 0; i < n; i++) {
		a[i].list.head = NULL;
		a[i].list.tail = NULL;
	}

	if (f == NULL) {
		printf("Mo file that bai, cac phan tu se duoc rand thay the!\n");
		for (int i = 0; i < n; i++)
			BigNumberGenerator(a[i], 20);

		return a;
	}

	int i = 0;

	char *str = readALine(f);
	while (str && i<n) {
		LargeInt kq;

		if (TinhBieuThucSoLon(str, kq)) {
			a[i] = kq;
			if (a[i].list.tail->data < 0) {
				a[i] *= -1;
			}
		}
		else {
			printf("Loi o dong thu %d, phan tu thu %d se duoc rand thay the!\n", i + 1, i);
			BigNumberGenerator(a[i],20);
		}

		free(str);
		str = readALine(f);

		i++;	// Ko xóa kq vì đã truyền cho a[i]
	}

	if (i < n) {
		printf("Chi tim thay trong file %d bieu thuc, cac phan tu con lai se duoc rand thay the!\n", i);
	}
	else
		printf("Da load thanh cong toan bo file\n");

	while (i < n) {
		BigNumberGenerator(a[i],20);
		i++;
	}

	return a;
}

int main() {
	srand(time(NULL));
	int n;
	char *file = NULL;

	printf("=========== Do An 2 - KTLT - 1712834 - LEVEL 3 ===========\n\n");

	printf("Nhap so phan tu: ");
	scanf("%d%*c", &n);
	printf("Nhap ten file: ");
	file = readALine(stdin);

	LargeInt *a = loadTestFromFile(file, n);
	free(file);

	printf("Ket thuc ham load.\n");

	RunTest(a, n);

	printf(" ===> Xem file \"i. [ten kieu sort].txt\" de xem thong tin va mang da sap xep.\n");


	for (int i = 0; i < n; i++)
		a[i].eraseData();
	free(a);

	_getche();
	return 0;
}