#include"LargeIntCal.h"

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int Priority(char c) {
	if (isOperator(c))
		if (c == '*' || c == '/')
			return 4;
		else
			return 3;
	else if (c == '(' || c == ')')
		return 2;
	else if (c == '.')
		return 0;
	else if (c >= '0' && c <= '9')
		return -1;

	return 1;
}

LargeInt getLargeInt(CharQueue& queue) {
	LargeInt kq;
	kq.list.push_back(0);

	while (Priority(queue.front->data) == -1) {
		kq *= 10;
		kq += queue.front->data - '0';
		queue.deQueue();
		if (queue.isEmpty())
			return kq;
	}

	if (queue.front->data == ' ')
		queue.deQueue();

	return kq;
}

bool ToPostFix(CharQueue& queue, const char* str) {
	CharStack stack;
	int i = 0;

	if (str[0] == '*' || str[0] == '/')
		return false;

	if (str[0] == '+' || str[0] == '-') {
		queue.enQueue('0');
		queue.enQueue(' ');
	}

	while (str[i]) {
		if (Priority(str[i]) <= 0) {
			queue.enQueue(str[i]);
			i++;
			if (Priority(str[i]) > 0)	// Chèn ngăn cách giữ các số
				queue.enQueue(' ');
		}
		else if (isOperator(str[i])) {
			if (!stack.isEmpty()) {
				while (Priority(stack.top->data) >= Priority(str[i])) {
					queue.enQueue(stack.top->data);
					stack.pop();
					if (stack.isEmpty())
						break;
				}
			}
			stack.push(str[i]);
			i++;
		}
		else if (str[i] == '(') {
			stack.push(str[i]);
			i++;
		}
		else if (str[i] == ')') {
			while (stack.top->data != '(') {
				queue.enQueue(stack.top->data);
				stack.pop();

				if (stack.isEmpty())	// Nếu stack ko có '(' => biểu thức lỗi
					return false;
			}
			stack.pop();
			i++;
		}
		else
			i++;
	}

	while (!stack.isEmpty()) {
		queue.enQueue(stack.top->data);
		stack.pop();
	}

	return true;
}

bool Cal(CharQueue& queue, LargeInt& kq) {
	LargeIntStack stack;

	while (!queue.isEmpty()) {
		if (Priority(queue.front->data) == -1) {
			LargeInt temp;
			temp = getLargeInt(queue);
			stack.push(temp);
			temp.eraseData();
		}
		else if (isOperator(queue.front->data)) {
			if (stack.getSize() < 2) {
				stack.deleteStack();
				return false;
			}

			LargeInt b;
			for (LongLongNode *p = stack.top->data.list.head; p; p = p->next)
				b.list.push_back(p->data);
			stack.pop();
			
			LargeInt a;
			for (LongLongNode *p = stack.top->data.list.head; p; p = p->next)
				a.list.push_back(p->data);
			stack.pop();

			LargeInt kqt;

			switch (queue.front->data) {
			case '+':
				kqt = a + b;
				break;
			case '-':
				kqt = a - b;
				break;
			case '*':
				kqt = a * b;
				break;
			case '/':
				if (b.list.getSize() == 1 && b.list.head->data == 0) {	// lỗi /0
					a.eraseData();
					b.eraseData();
					queue.deleteQueue();
					stack.deleteStack();
					return false;
				}
				kqt = a / b;
			}
			
			a.eraseData();
			b.eraseData();

			stack.push(kqt);
			queue.deQueue();
		}
	}

	if (stack.getSize() != 1) {
		stack.deleteStack();
		return false;
	}
	else {
		kq = stack.top->data;
	}
	return true;
}

bool TinhBieuThucSoLon(const char* str, LargeInt &kq) {
	CharQueue Postfix;
	if (!ToPostFix(Postfix, str))
		return false;

	if (!Cal(Postfix, kq))
		return false;
	return true;
}