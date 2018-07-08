#pragma once
#ifndef _Stack_h_
#define _Stack_h_

#include"List.h"

struct LargeIntStack {
	LargeIntList stack;

	LargeIntNode *&top = stack.head;

	bool isEmpty() {
		return stack.isEmpty();
	}

	int getSize() {
		return stack.getSize();
	}

	void push(LargeInt data) {
		stack.push_front(data);
	}

	void pop() {
		stack.pop_front();
	}

	void deleteStack() {
		stack.deleteList();
	}
};

struct CharStack {
	CharList stack;

	CharNode *&top = stack.head;

	bool isEmpty() {
		return stack.isEmpty();
	}

	int getSize() {
		return stack.getSize();
	}

	void push(char data) {
		stack.push_front(data);
	}

	void pop() {
		stack.pop_front();
	}

	void deleteStack() {
		stack.deleteList();
	}
};

#endif