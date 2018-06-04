#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"LargeIntCal.h"

int main() {
	
	LargeInt kq;
	const char *str = "55435+2342-5636*342*(123+54-12*2)-(12*534-123)*2";

	if (TinhBieuThucSoLon(str, kq))
		kq.print();

	kq.eraseData();
	
	_getche();
	return 0;
}