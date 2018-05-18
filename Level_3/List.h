#pragma once
#ifndef _List_h_
#define _List_h_

#include<stdio.h>
#include<stdlib.h>

struct LongLongNode {
	__int64 data;
	LongLongNode* next;
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
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
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
		if (isEmpty()) {
			head = temp;
			tail = temp;
			temp->next = NULL;
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
		}
	}

	void deleteList() {
		while (!isEmpty())
			pop_front();
	}
};

#endif