#include<stdio.h>
#include<conio.h>
#include"SortAlg.h"
#include"List.h"
#include"Queue.h"

int main() {
	int a[] = { 3453,22435,4232,11274,5425 };
	int n = 5;
	int ss = 0, gan = 0;
	
	HeapSort(a, n, ss, gan);
	for (int k = 0; k < n; k++)
		printf("%d\n", a[k]);

	

	_getche();
	return 0;
}