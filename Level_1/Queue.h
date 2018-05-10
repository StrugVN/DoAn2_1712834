#ifndef _Queue_h_
#define _Queue_h_

#include"List.h"

/*			Mô hình Queue:
	enQueue	                ---> deQueue
	    |                   |
	    --> head -> ... -> tail -> NULL
	       (rear)        (front)   
*/

struct IntQueue {
	IntList queue;

	IntNode *&rear = queue.head;
	IntNode *&front = queue.tail;

	bool isEmpty() {
		return queue.isEmpty();
	}

	int getSize() {
		return queue.getSize();
	}

	void enQueue(int data) {
		queue.push_front(data);
	}

	void deQueue() {
		queue.pop_back();
	}

	void deleteQueue() {
		queue.deleteList();
	}
};

#endif