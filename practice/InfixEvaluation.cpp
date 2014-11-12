/*
 * InfixEvaluation.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: Arpit Bhayani
 */

#include <map>
#include <cmath>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define pi(x) printf("%d\n" , x)
#define pl(x) printf("%ld\n" , x)
#define pll(x) printf("%lld\n" , x)
#define pc(x) printf("%c\n" , x)
#define ps(x) printf("%s\n" , x)

#define fup(i,a,b) for(int i=a;i<b;i++)
#define fdn(i,a,b) for(int i=a;i>=b;i--)

#define DEBUG 0
#define gc getchar
#define ll long long

#define SEPERATOR " : "

#define trace1(a) cout << #a << SEPERATOR << a << endl;
#define trace2(a,b) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << endl;
#define trace3(a,b,c) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << #c << SEPERATOR << c << endl;

void scanint(ll int &x) {
	register ll int c = gc();
	x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		x = (x << 1) + (x << 3) + c - 48;
	}
}

int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 10

int prec(char op) {
	int p = 0;
	switch (op) {
	case '%':
		p = 2;
		break;
	case '*':
		p = 2;
		break;
	case '+':
		p = 1;
		break;
	case '-':
		p = 1;
		break;
	default:
		p = 0;
		break;
	}
	return p;
}

int eval(char * str, int n) {

	stack<char> ops;
	stack<int> val;

	for (int i = 0; i < n; i++) {

		if (str[i] == '%' || str[i] == '*' || str[i] == '+' || str[i] == '-') {

			while (ops.empty() == false && prec(str[i]) < prec(ops.top())) {

				int b = val.top();
				val.pop();
				int a = val.top();
				val.pop();
				char op = ops.top();
				ops.pop();

				int ans = 0;
				switch (op) {
				case '+':
					ans = a + b;
					break;
				case '-':
					ans = a - b;
					break;
				case '*':
					ans = a * b;
					break;
				case '%':
					ans = a / b;
					break;
				}

				cout << "Evaluating : a = " << a << " and b = " << b
						<< " and op = " << op << endl;
				val.push(ans);
			}
			cout << "Pushing operator " << str[i] << endl;
			ops.push(str[i]);

		} else {
			int v = 0;
			while (i < n && str[i] >= '0' && str[i] <= '9') {
				v = v * 10 + (str[i] - '0');
				i++;
			}
			i--;
			cout << "Pushing value : " << v << endl;
			val.push(v);
		}
	}

	while (ops.empty() == false) {
		int b = val.top();
		val.pop();
		int a = val.top();
		val.pop();
		char op = ops.top();
		ops.pop();

		int ans = 0;
		switch (op) {
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '%':
			ans = a / b;
			break;
		}
		cout << "Evaluating : a = " << a << " and b = " << b << " and op = "
				<< op << endl;
		val.push(ans);
	}

	cout << val.size() << endl;
	return val.top();

	/*cout << "Operators : ";
	 while (!op_stack.empty()) {
	 cout << op_stack.top() << " ";
	 op_stack.pop();
	 }
	 cout << endl;

	 cout << "Operands : ";
	 while (!oper_stack.empty()) {
	 cout << oper_stack.top() << " ";
	 oper_stack.pop();
	 }
	 cout << endl;*/

}

int main(int argc, char * argv[]) {

	char str[100];
	ss(str);

	cout << eval(str, strlen(str)) << endl;

	return 0;
}
