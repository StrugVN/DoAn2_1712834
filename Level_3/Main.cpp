#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"LargeIntCal.h"
#include"SortAlg.h"

int main() {
	LargeInt ss, gan;
	ss.getFromStr("1");
	gan.getFromStr("0");
	LargeInt a[10];
	a[0].getFromStr("478765432345689876543");
	a[1].getFromStr("987654345678796543456");
	a[2].getFromStr("756342345987654879087");
	a[3].getFromStr("234567898765456789786");
	a[4].getFromStr("787544458879678346756");
	a[5].getFromStr("1454567887035465546567");
	a[6].getFromStr("3354669856547658577567");
	a[7].getFromStr("4546756887877870989089");
	a[8].getFromStr("1232557798098865634565");
	a[9].getFromStr("6895434642554366967807");


	for (int i = 0; i < 10; i++) {
		a[i].print();
		printf("\n");
	}
	printf("\n\n");
	_getche();

	QuickSort(a,0,9, ss, gan);

	for (int i = 0; i < 10; i++) {
		a[i].print();
		printf("\n");
		a[i].eraseData();
	}

	ss.eraseData();
	gan.eraseData();

	_getche();
	_getche();
	return 0;
}