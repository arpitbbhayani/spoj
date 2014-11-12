/*
 * sigmoid7.cpp
 *
 *  Created on: May 17, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

#define DEBUG 0

using namespace std;

int readline(char * str) {
	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int is_op(char ch) {
	switch (ch) {
	case '+':
		return 1;
	case '*':
		return 1;
	default:
		return 0;
	}
}

int is_digit(char ch) {
	return (ch >= '0' && ch <= '9');
}

void evaluate(stack<char> &operator_stack, stack<int> &operand_stack) {

	if (operand_stack.size() < 2) {
		return;
	}

	int op2 = operand_stack.top();
	operand_stack.pop();

	int op1 = operand_stack.top();
	operand_stack.pop();

	char op = operator_stack.top();
	operator_stack.pop();

	switch (op) {
	case '+':
		operand_stack.push(op1 + op2);
		break;
	case '*':
		operand_stack.push(op1 * op2);
		break;
	}

	cout << "Evaluating : " << op1 << op << op2 << endl;

}

int main(int argc, char * argv[]) {

	int n;
	char str[1024];
	stack<char> operator_stack;
	stack<int> operand_stack;

	n = readline(str);
	cout << "Expression : " << str << endl;

	for (int i = 0; i < n; i++) {

		char ch = str[i];

		if (is_op(ch)) {

			while (!operator_stack.empty() && operator_stack.top() != '+' && operator_stack.top() != '(') {
				evaluate(operator_stack, operand_stack);
			}
			operator_stack.push(ch);

		} else if (is_digit(ch)) {
			operand_stack.push(ch - '0');
		} else if (ch == '(') {
			operator_stack.push('(');
		} else if (ch == ')') {
			while (!operator_stack.empty() && operator_stack.top() != '(') {
				evaluate(operator_stack, operand_stack);
			}
			operator_stack.pop();
		}

	}

	while (operator_stack.empty() == false) {
		evaluate(operator_stack, operand_stack);
	}

	cout << "Result : " << operand_stack.top() << endl;

	return 0;
}
