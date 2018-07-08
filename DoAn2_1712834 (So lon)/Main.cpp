#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"SortAlg.h"
#include"Generate test.h"

int main() {
	srand(time(NULL));
	int n;

	printf("=========== Do An 2 (So cuc lon) - KTLT - 1712834 ===========\n\n");

	LargeInt *a = NULL;
	generateTest(a, n);

	RunTest(a,n);

	printf(" ===> Xem file \"i. [ten kieu sort].txt\" de xem thong tin va mang da sap xep.\n");


	for (int i = 0; i < n; i++)
		a[i].eraseData();
	free(a);

	_getche();
	return 0;
}