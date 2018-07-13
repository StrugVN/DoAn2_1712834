#include"Cal.h"

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int Priority(char c) {
	if (isOperator(c))
		if (c == '*' || c == '/')
			return 2;
		else
			return 1;
	return -1;
}

double getNumD(CharQueue& queue) {
	double kq = 0;

	while (isDigit(queue.front->data)) {
		kq *= 10;
		kq += queue.front->data - '0';
		queue.deQueue();
	}

	if (queue.front->data == '.') {
		queue.deQueue();
		double temp = 10;
		while (isDigit(queue.front->data)) {
			kq += (queue.front->data - '0') / temp;
			temp *= 10;
			queue.deQueue();
		}
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
		if (isDigit(str[i]) || str[i] == '.') {
			queue.enQueue(str[i]);
			i++;
			if (!isDigit(str[i]) && str[i] != '.')	// Chèn ngăn cách giữ các số
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

bool Cal(CharQueue& queue, double& kq) {
	DoubleStack stack;

	while (!queue.isEmpty()) {
		if (isDigit(queue.front->data))
			stack.push(getNumD(queue));
		else if (isOperator(queue.front->data)) {
			if (stack.getSize() < 2) {
				stack.deleteStack();
				return false;
			}

			double b = stack.top->data;
			stack.pop();
			double a = stack.top->data;
			stack.pop();
			double kqt;

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
				kqt = a / b;
			}

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
		stack.pop();
	}
	return true;
}

bool TinhBieuThuc(const char* str, double &kq) {
	CharQueue Postfix;
	if (!ToPostFix(Postfix, str))
		return false;

	if (!Cal(Postfix, kq))
		return false;
	return true;
}