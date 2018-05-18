#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"LargeNum.h"

int main() {
	LargeInt a, b;
	  a.getFromStr("99624689579348572349785672968792356782563456356354634234565466123453425234367");
	b.getFromStr("1625389674398543978523896985689725689234234623452562565463673463456546345654539");
	
	a.print();
	printf("\n-\n");
	b.print();
	printf("\n------------------------------\n");

	

	LargeInt c;

	clock_t s = clock();
	for (int i = 0; i < 1000000; i++)
		c = a - b;
	clock_t e = clock();

	c.print();

	

	printf("\n\nRun Time x10^6: %f s", (double)(e - s)/1000);

	a.eraseData();
	b.eraseData();
	c.eraseData();

	_getche();
	return 0;
}