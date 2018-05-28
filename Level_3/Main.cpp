#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"LargeIntCal.h"

int main() {
	
	LargeInt kq;
	const char *str = "-14245565463546346763573567635756372643734675625+546346736577534167567563546767889637546625656";

	if (TinhBieuThucSoLon(str, kq))
		kq.print();

	kq.eraseData();
	
	_getche();
	return 0;
}