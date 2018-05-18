#pragma once
#ifndef _LargeNum_h_
#define _LargeNum_h_

#include<stdio.h>
#include<string.h>
#include<math.h>
#include"List.h"

struct LargeInt {
	LongLongList list;

	int getSize() {
		return list.getSize();
	}

	void getFromStr(const char* str) {
		int n = strlen(str)-1;
		
		while (n >= 0) {
			int t = n;
			if (n - 8 < 0)
				n = 0;
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
				for (int i = (int)log10(t->data) + 1; i <= 9; i++)
					printf("0");
				printf("%lld", t->data);
			}
			p = t;
			t = list.head;
		}
	}

	void eraseData() {
		list.deleteList();
	}

	void ReScale(LongLongNode *start) {	// Xử lí kết quả để node chứa tối đa 9 chữ số
		if (!start)
			return;

		if ((int)log10(start->data)+1 > 9) {
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
	}

	LargeInt operator+(LargeInt &other) {
		LargeInt kq;
		LongLongNode *p1 = list.head;
		LongLongNode *p2 = other.list.head;

		while (p1 && p2) {
			kq.list.push_back(p1->data + p2->data);
			p1 = p1->next;
			p2 = p2->next;
		}

		// Chỉ 1 trong 2 vòng while sau chạy vì 1 bên đã hết dữ liệu
		while (p1) {
			kq.list.push_back(p1->data);
			p1 = p1->next;
		}
		while (p2) {
			kq.list.push_back(p2->data);
			p1 = p1->next;
		}

		kq.ReScaleList();

		return kq;
	}
};

#endif