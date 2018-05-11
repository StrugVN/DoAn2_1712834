#pragma once
#ifndef _List_h_
#define _List_h_

#include<stdio.h>
#include<stdlib.h>

struct IntNode {
	int data;
	IntNode* next;
};

struct IntList {
	IntNode *head=NULL;
	IntNode *tail=NULL;

	bool isEmpty() {
		return !(head && tail);
	}

	int getSize() {
		int i = 0;
		for (IntNode *t = head; t != NULL; t++)
			i++;
		return i;
	}

	void push_back(int data) {
		IntNode *temp = (IntNode*)malloc(sizeof*temp);
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
			IntNode *temp = head;
			while (temp->next != tail)
				temp = temp->next;
			free(tail);
			tail = temp;
			tail->next = NULL;
		}
	}

	void push_front(int data) {
		IntNode *temp = (IntNode*)malloc(sizeof*temp);
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
			IntNode *temp = head->next;
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