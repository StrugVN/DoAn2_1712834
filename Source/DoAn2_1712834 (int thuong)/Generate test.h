#ifndef _Generatetest_h_
#define _Generatetest_h_
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void CreateTest(int *arr, int n);
bool CheckFile(const char* filename);
void LoadTest(int *&arr, int &n, char *filename);
void NewTest(int *&arr, int &n);
void generateTest(int *&arr, int &n);
void RunTest(int *arr, int n);

#endif