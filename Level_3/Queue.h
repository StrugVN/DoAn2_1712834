#pragma once
#ifndef _Queue_h_
#define _Queue_h_

#include"List.h"

struct CharQueue {
	CharList queue;

	CharNode *&rear = queue.tail;
	CharNode *&front = queue.head;

	bool isEmpty() {
		return queue.isEmpty();
	}

	int getSize() {
		return queue.getSize();
	}

	void enQueue(char data) {
		queue.push_back(data);
	}

	void deQueue() {
		queue.pop_front();
	}

	void deleteQueue() {
		queue.deleteList();
	}
};

#endif