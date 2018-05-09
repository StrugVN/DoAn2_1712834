#include<stdio.h>
#include<conio.h>
#include"SortAlg.h"

int main() {
	int a[] = { 3,2,4,1,5 };
	int n = 5;

	MergeSort(a, 0,n-1);

	for (int k = 0; k < n; k++)
		printf("%d\n", a[k]);

	_getche();
	return 0;
}