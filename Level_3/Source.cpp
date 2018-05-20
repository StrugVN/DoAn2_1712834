#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"LargeNum.h"

int main() {
	LargeInt a, b;
	a.getFromStr("347823682768542");
	b.getFromStr("32452575756373755625");

	a.print();
	printf("\n*\n");
	b.print();
	//printf("%lld",i);
	printf("\n-----------------------------------------\n");

	LargeInt c = a * b;

	c.print();

	a.eraseData();
	b.eraseData();
	c.eraseData();

	_getche();
	return 0;
}