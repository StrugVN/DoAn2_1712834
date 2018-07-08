#ifndef _Generatetest_h_
#define _Generatetest_h_
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"LargeNum.h"

void BigNumberGenerator(LargeInt &a, int numberOfDigit);
void CreateTest(LargeInt *arr, int n, int numberOfDigit);
bool CheckFile(const char* filename);
void LoadTest(LargeInt *&arr, int &n, char *filename);
void NewTest(LargeInt *&arr, int &n);
void generateTest(LargeInt *&arr, int &n);

#endif