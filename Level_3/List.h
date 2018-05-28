#pragma once
#ifndef _List_h_
#define _List_h_

#include<stdio.h>
#include<stdlib.h>
#include"LargeNum.h"

struct CharNode {
	char data;
	CharNode* next;
};

struct CharList {
	CharNode *head = NULL;
	CharNode *tail = NULL;

	bool isEmpty() {
		return !(head && tail);
	}

	int getSize() {
		int i = 0;
		for (CharNode *t = head; t != NULL; t = t->next)
			i++;
		return i;
	}

	void push_back(char data) {
		CharNode *temp = (CharNode*)malloc(sizeof*temp);
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
			CharNode *temp = head;
			while (temp->next != tail)
				temp = temp->next;
			free(tail);
			tail = temp;
			tail->next = NULL;
		}
	}

	void push_front(char data) {
		CharNode *temp = (CharNode*)malloc(sizeof*temp);
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
			CharNode *temp = head->next;
			free(head);
			head = temp;
		}
	}

	void deleteList() {
		while (!isEmpty())
			pop_front();
	}
};

struct LargeIntNode {
	LargeInt data;
	LargeIntNode *next;
};

struct LargeIntList {
	LargeIntNode *head = NULL;
	LargeIntNode *tail = NULL;

	bool isEmpty() {
		return !(head && tail);
	}

	int getSize() {
		int i = 0;
		for (LargeIntNode *t = head; t != NULL; t = t->next)
			i++;
		return i;
	}

	void push_back(LargeInt data) {
		LargeIntNode *temp = (LargeIntNode*)malloc(sizeof*temp);
		temp->data.list.head = NULL;
		temp->data.list.tail = NULL;

		for (LongLongNode *p = data.list.head; p; p = p->next)
			temp->data.list.push_back(p->data);

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
			head->data.eraseData();
			free(head);
			head = NULL;
			tail = NULL;
		}
		else {
			LargeIntNode *temp = head;
			while (temp->next != tail)
				temp = temp->next;
			tail->data.eraseData();
			free(tail);
			tail = temp;
			tail->next = NULL;
		}
	}

	void push_front(LargeInt data) {
		LargeIntNode *temp = (LargeIntNode*)malloc(sizeof*temp);
		temp->data.list.head = NULL;
		temp->data.list.tail = NULL;

		for (LongLongNode *p = data.list.head; p; p = p->next)
			temp->data.list.push_back(p->data);

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
			head->data.eraseData();
			free(head);
			head = NULL;
			tail = NULL;
		}
		else {
			LargeIntNode *temp = head->next;
			head->data.eraseData();
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