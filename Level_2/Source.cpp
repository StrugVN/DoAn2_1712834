#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include"Cal.h"

int main() {
	const char* str = "5.5/2+3*(4/8-2)";
	double kq;
	int kq2;

	if (TinhBieuThuc(str, kq))
		printf("%s = %f\n", str, kq);
	if (TinhBieuThuc(str, kq)) {
		kq2 = (int)kq;
		printf("%s = %d\n", str, kq2);
	}
	_getche();
	return 0;
}