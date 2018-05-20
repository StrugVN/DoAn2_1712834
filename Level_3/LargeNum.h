#pragma once
#ifndef _LargeNum_h_
#define _LargeNum_h_

#include<stdio.h>
#include<string.h>
#include<math.h>
#include"List.h"

/*
	Số lớn |A| = |a1|*10^(9*0) + |a2|*10^(9*1) + ... + |an|*10^(9*n). ai < 10^10, ai cùng dấu A
	(Chọn 9 vì __int64 tối đa 20, 9^2 = 18<20)

	A + B = (a1+b1)*10^(9*0) + (a2+b2)*10^(9*1) + ...
	A - B = (a1-b1)*10^(9*0) + (a2-b2)*10^(9*1) + ...
	A * B = A*b1*10^(9*0) + A*b2*10^(9*1) + ... + A*bn*10^(9*n),		A*x = a1*x*10^(9*0) + a2*x*10^(9*1) + ... + an*x*10^(9*n)
	A / B = ???

*/

struct LargeInt {
	LongLongList list;

	void getFromStr(const char* str) {
		int n = strlen(str)-1;
		int i = 0;
		if (str[0] == '-')
			i = 1;

		while (n >= i) {
			int t = n;
			if (n - 8 < 0)
				n = i;
			else
				n = n - 8;

			__int64 temp = 0;
			int size = 0;

			while (size + n <= t) {
				temp *= 10;
				temp += str[n+size] - '0';
				size++;
			}
			n--;
			if (i == 1)
				temp *= -1;

			list.push_back(temp);
		}
	}

	void print() {
		LongLongNode *t = list.head;
		LongLongNode *p = list.tail;
		printf("%lld", p->data);
		while (t != p) {
			while (t->next != p) {
				t = t->next;
			}
			if (t->data == 0)
				printf("000000000");
			else {
				for (int i = (int)log10(abs(t->data)) + 1; i < 9; i++)
					printf("0");
				printf("%lld", abs(t->data));
			}
			p = t;
			t = list.head;
		}
	}

	void eraseData() {
		list.deleteList();
	}

	void ReScale(LongLongNode *start) {	// Xử lí kết quả để node chứa tối đa 9 chữ số và >0 (trừ node cao nhất)
		if (!start)
			return;
		if (start->data < 0) {
			if (start->next) {
				start->next->data -= 1;
				start->data += 1000000000;
				ReScale(start->next);
			}
		}
		else if ((int)log10(start->data)+1 > 9) {
			__int64 du = start->data / 1000000000;
			start->data = start->data % 1000000000;

			if (start->next != NULL) {
				start->next->data += du;
				ReScale(start->next);
			}
			else
				list.push_back(du);
		}
		else
			ReScale(start->next);
	}

	void ReScaleList() {
		ReScale(list.head);
		while (list.tail->data == 0) {
			if (list.head != list.tail)
				list.pop_back();
			else
				break;
		}
	}
};


LargeInt operator+(LargeInt This, LargeInt other) {
	LargeInt kq;
	LongLongNode *p1 = This.list.head;
	LongLongNode *p2 = other.list.head;

	while (p1 && p2) {
		kq.list.push_back(p1->data + p2->data);
		p1 = p1->next;
		p2 = p2->next;
	}

	while (p1) {
		kq.list.push_back(p1->data);
		p1 = p1->next;
	}
	while (p2) {
		kq.list.push_back(p2->data);
		p2 = p2->next;
	}

	kq.ReScaleList();

	return kq;
}

LargeInt operator-(LargeInt This, LargeInt other) {
	LargeInt kq;
	LongLongNode *p1 = This.list.head;
	LongLongNode *p2 = other.list.head;

	while (p1 && p2) {
		kq.list.push_back(p1->data - p2->data);
		p1 = p1->next;
		p2 = p2->next;
	}

	while (p1) {
		kq.list.push_back(p1->data);
		p1 = p1->next;
	}
	while (p2) {
		kq.list.push_back(-p2->data);
		p2 = p2->next;
	}
	kq.ReScaleList();
	return kq;
}

LargeInt operator*(LargeInt This, __int64 int64) {
	LargeInt kq;
	LongLongNode *p = This.list.head;

	while (p) {
		kq.list.push_back(p->data*int64);
		p = p->next;
	}
	kq.ReScaleList();
	return kq;
}

LargeInt& operator*=(LargeInt& This, __int64 int64) {
	LongLongNode *p = This.list.head;

	while (p) {
		p->data *= int64;
		p = p->next;
	}
	This.ReScaleList();

	return This;
}

LargeInt& operator+=(LargeInt& This, LargeInt other) {
	LargeInt temp = This + other;
	This.eraseData();
	This = temp;
	return This;
}

LargeInt operator*(LargeInt This, LargeInt other) {
	LargeInt kq, *arr;
	kq.list.push_back(0);

	int n = other.list.getSize();
	arr = (LargeInt*)malloc(sizeof(LargeInt)*n);

	LongLongNode *p = other.list.head;

	for (int i = 0; i < n; i++) {
		arr[i] = This * p->data;

		for (int j = 0; j < i; j++)
			arr[i] *= 1000000000;

		p = p->next;
	}

	for (int i = 0; i < n; i++)
		kq += arr[i];

	for (int i = 0; i < n; i++)
		arr[i].eraseData();
	free(arr);

	return kq;
}

#endif