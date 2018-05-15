#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<memory.h>
#include"SortAlg.h"

int* CreateTest(int n) {
	int *arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		arr[i] = rand();
	return arr;
}

int main() {
	srand(time(NULL));
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	
	int *mau = CreateTest(n);

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