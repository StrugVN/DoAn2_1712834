#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include"LargeNum.h"

int main() {
	LargeInt a, b;
	a.getFromStr("999999999");
	b.getFromStr("1");
	
	LargeInt c = a + b;

	c.print();

	a.eraseData();
	b.eraseData();
	c.eraseData();

	_getche();
	return 0;
}