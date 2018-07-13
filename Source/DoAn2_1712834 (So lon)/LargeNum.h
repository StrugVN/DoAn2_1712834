#ifndef _LargeNum_h_
#define _LargeNum_h_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct LongLongNode {
	__int64 data;
	LongLongNode* next;
	LongLongNode* prev;
};

struct LongLongList {
	LongLongNode *head = NULL;
	LongLongNode *tail = NULL;

	bool isEmpty() {
		return !(head && tail);
	}

	int getSize() {
		int i = 0;
		for (LongLongNode *t = head; t != NULL; t = t->next)
			i++;
		return i;
	}

	void push_back(__int64 data) {
		LongLongNode *temp = (LongLongNode*)malloc(sizeof*temp);
		temp->data = data;
		temp->next = NULL;

		if (isEmpty()) {
			temp->prev = NULL;
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	void pop_back() {
		if (isEmpty())
			return;
		else if (head == tail) {
			free(head);
			head = NULL;
			tail = NULL;
		}
		else {
			LongLongNode *temp = head;
			while (temp->next != tail)
				temp = temp->next;
			free(tail);
			tail = temp;
			tail->next = NULL;
		}
	}

	void push_front(__int64 data) {
		LongLongNode *temp = (LongLongNode*)malloc(sizeof*temp);
		temp->data = data;
		temp->prev = NULL;
		if (isEmpty()) {
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}

	void pop_front() {
		if (isEmpty())
			return;
		else if (head == tail) {
			free(head);
			head = NULL;
			tail = NULL;
		}
		else {
			LongLongNode *temp = head->next;
			free(head);
			head = temp;
			head->prev = NULL;
		}
	}

	void deleteList() {
		while (!isEmpty())
			pop_front();
	}
};

struct LargeInt {
	LongLongList list;

	void getFromStr(const char* str) {
		int n = (int)strlen(str) - 1;
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
				temp += str[n + size] - '0';
				size++;
			}
			n--;
			if (i == 1)
				temp *= -1;

			list.push_back(temp);
		}
	}

	void print() {
		LongLongNode *p = list.tail;
		printf("%lld", p->data);
		p = p->prev;
		while (p) {
			if (p->data == 0)
				printf("000000000");
			else {
				for (int i = (int)log10((double)abs(p->data)) + 1; i < 9; i++)
					printf("0");
				printf("%lld", abs(p->data));
			}
			p = p->prev;
		}
	}

	void printToFile(FILE *f) {
		LongLongNode *p = list.tail;
		fprintf(f, "%lld", p->data);
		p = p->prev;
		while (p) {
			if (p->data == 0)
				fprintf(f,"000000000");
			else {
				for (int i = (int)log10((double)abs(p->data)) + 1; i < 9; i++)
					fprintf(f,"0");
				fprintf(f,"%lld", abs(p->data));
			}
			p = p->prev;
		}
	}

	void eraseData() {
		list.deleteList();
	}

	void ReScalePos(LongLongNode *start) {	// Xử lí kết quả để node chứa tối đa 9 chữ số và >0 (trừ node cao nhất)
		if (!start)
			return;
		if (start->data < 0) {
			if (start->next) {
				start->next->data -= 1;
				start->data += 1000000000;
				ReScalePos(start->next);
			}
		}
		else if ((int)log10((double)start->data) + 1 > 9) {
			__int64 du = start->data / 1000000000;
			start->data = start->data % 1000000000;

			if (start->next != NULL) {
				start->next->data += du;
				ReScalePos(start->next);
			}
			else
				list.push_back(du);
		}
		else
			ReScalePos(start->next);
	}

	void ReScaleNev(LongLongNode *start) {
		if (!start)
			return;
		if (start->data > 0) {
			if (start->next) {
				start->next->data += 1;
				start->data -= 1000000000;
				ReScaleNev(start->next);
			}
		}
		else if ((int)log10((double)start->data) + 1 > 9) {
			__int64 du = start->data / 1000000000;
			start->data = start->data % 1000000000;

			if (start->next != NULL) {
				start->next->data += du;
				ReScaleNev(start->next);
			}
			else
				list.push_back(du);
		}
		else
			ReScaleNev(start->next);
	}

	void ReScaleList() {
		if (list.tail->data > 0)
			ReScalePos(list.head);
		else
			ReScaleNev(list.head);

		while (list.tail->data == 0) {
			if (list.head != list.tail)
				list.pop_back();
			else
				break;
		}
	}

	LargeInt Duplicate() {
		LargeInt new_element;
		LongLongNode *p = list.head;

		while (p) {
			new_element.list.push_back(p->data);
			p = p->next;
		}

		return new_element;
	}
};

LargeInt operator+(LargeInt This, LargeInt other);
LargeInt operator-(LargeInt This, LargeInt other);
LargeInt operator+(LargeInt This, __int64 num);
LargeInt operator*(LargeInt This, __int64 int64);
LargeInt& operator*=(LargeInt& This, __int64 int64);
LargeInt& operator+=(LargeInt& This, __int64 num);
LargeInt& operator+=(LargeInt& This, LargeInt other);
LargeInt& operator-=(LargeInt& This, LargeInt other);
LargeInt operator*(LargeInt This, LargeInt other);
bool operator ==(LargeInt This, LargeInt other);
bool operator !=(LargeInt This, LargeInt other);
bool operator <(LargeInt This, LargeInt other);
bool operator <=(LargeInt This, LargeInt other);
bool operator >(LargeInt This, LargeInt other);
bool operator >=(LargeInt This, LargeInt other);
bool operator >(LargeInt This, int i);
bool operator ++ (LargeInt &This, int);	// Xài tạm cho ct

#endif