/*
 * CopyConstructorVsCopyAssignment.cpp
 *
 *  Created on: Sep 30, 2014
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

class Test {
private:
	int a;

public:
	Test() {
		cout << "Default constructor" << endl;
	}
	Test(int aa) {
		a = aa;
		cout << "Normal constructor with arg" << endl;
	}
	Test(const Test &t) {
		a = t.a;
		cout << "Copy constructor" << endl;
	}

	Test operator=(const Test &t) {
		a = t.a;
		cout << "Copy assignment" << endl;
	}
};

int main(int argc, char * argv[]) {

	Test t1, t2, t3;

	cout << "t1 = Test(10);";
	t1 = Test(10);

	cout << "t2 = t1;";
	t2 = t1;

	cout << "t3 = Test(t2);";
	t3 = Test(t2);

	cout << "Test t4 = Test(t3);";
	Test t4 = Test(t3);

	cout << "Test t5 = t4;";
	Test t5 = t4;

	cout << "Test t6 = Test(20);";
	Test t6 = Test(20);

	return 0;
}
