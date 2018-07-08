#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"SortAlg.h"
#include"Generate test.h"

int main() {
	srand((unsigned int)time(NULL));
	int n;

	printf("=========== Do An 2 - KTLT - 1712834 ===========\n\n");

	int *a = NULL;
	generateTest(a, n);

	RunTest(a, n);

	printf(" ===> Xem file \"i. [ten kieu sort].txt\" de xem thong tin va mang da sap xep.\n");

	free(a);

	_getche();
	return 0;
}