#include"LargeNum.h"

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

LargeInt operator+(LargeInt This, __int64 num) {
	LargeInt kq;
	for (LongLongNode *p = This.list.head; p; p = p->next)
		kq.list.push_back(p->data);
	kq.list.head->data += num;
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

LargeInt& operator+=(LargeInt& This, __int64 num) {
	LargeInt temp = This + num;
	This.eraseData();
	This = temp;
	return This;
}

LargeInt& operator+=(LargeInt& This, LargeInt other) {
	LargeInt temp = This + other;
	This.eraseData();
	This = temp;
	return This;
}

LargeInt& operator-=(LargeInt& This, LargeInt other) {
	LargeInt temp = This - other;
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

bool operator ==(LargeInt This, LargeInt other) {
	if (This.list.tail->data*other.list.tail->data < 0)
		return false;
	else if (This.list.getSize() == other.list.getSize()) {
		LongLongNode *p = This.list.tail;
		LongLongNode *t = other.list.tail;

		while (t && p) {
			if (p->data != t->data)
				return false;
			p = p->prev;
			t = t->prev;
		}

		return true;
	}
	else
		return false;
}

bool operator !=(LargeInt This, LargeInt other) {
	return !(This == other);
}

bool operator <(LargeInt This, LargeInt other) {
	if (This.list.tail->data*other.list.tail->data < 0)	// 1 trong a hoặc b âm => a<b <=> a âm
		return This.list.tail->data < 0;
	else if (This.list.getSize() == other.list.getSize()) {
		LongLongNode *p = This.list.tail;
		LongLongNode *t = other.list.tail;

		while (t && p) {
			if (p->data > t->data)
				return false;
			else if (p->data < t->data)
				return true;
			p = p->prev;
			t = t->prev;
		}

		return true;
	}
	else
		return This.list.getSize() < other.list.getSize();
}

bool operator <=(LargeInt This, LargeInt other) {
	return (This < other || This == other);
}

bool operator > (LargeInt This, LargeInt other) {
	return !(This <= other);
}

bool operator >= (LargeInt This, LargeInt other) {
	return !(This < other);
}

LargeInt operator/(LargeInt This, LargeInt other) {
	LargeInt kq;
	if (other.list.getSize() == 1) {
		for (LongLongNode *p = This.list.tail; p; p = p->prev) {
			kq.list.push_back(p->data / other.list.head->data);
		}
	}
	else {
		LargeInt temp;
		for (LongLongNode *p = This.list.head; p; p = p->next)
			temp.list.push_back(p->data);

		kq.list.push_back(0);

		while (temp >= other) {
			temp -= other;
			kq += 1;
		}
		temp.eraseData();
	}

	return kq;
}

bool operator > (LargeInt This, int i) {
	return This.list.head->data > i;
}

bool operator ++ (LargeInt &This, int) {	// Đây ko đúng là operator ++ postfix thật sự, chỉ làm tạm để phục vụ ct hiện tại
	This.list.head->data++;
	This.ReScaleList();
	return true;
}