#include"Cal.h"

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
		return 1;
	else if (c == '.')
		return 0;
	else if (isdigit(c))
		return -1;
	else
		return 2;
}

double getNumD(CharQueue& queue) {
	double kq = 0;

	while (Priority(queue.front->data) == -1) {
		kq *= 10;
		kq += queue.front->data - '0';
		queue.deQueue();
	}

	if (queue.front->data == '.') {
		queue.deQueue();
		double temp = 10;
		while (Priority(queue.front->data) == -1) {
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

	if (str[0] == '+' || str[0] == '-')
		queue.enQueue('0');

	while (str[i]) {
		if (Priority(str[i]) <= 0) {
			queue.enQueue(str[i]);
			i++;
			if (Priority(str[i]) > 0)	// Chèn ngăn cách giữ các số
				queue.enQueue(' ');
		}
		else if (isOperator(str[i])) {
			if (!stack.isEmpty()) {
				while (Priority(stack.top->data) > Priority(str[i])) {
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
		if (Priority(queue.front->data) == -1)
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