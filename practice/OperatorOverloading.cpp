/*
 * OperatorOverloading.cpp
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

class MyInt {

private:
	int a;

public:
	MyInt(int x) {
		a = x;
	}

	MyInt operator+(MyInt &val1) {
		MyInt result = MyInt(val1.a * a);
		return result;
	}

	int getVal() {
		return a;
	}

};

class MyMadInt {
public:
	int getVal() {
		return val;
	}
	MyMadInt(int v) {
		val = v;
	}
private:
	int val;
};

int operator+(MyMadInt &a, MyMadInt &b) {
	MyMadInt c = MyMadInt(a.getVal() * b.getVal());
	return c.getVal();
}

int main(int argc, char * argv[]) {

	MyInt a = MyInt(2);
	MyInt b = MyInt(3);
	MyInt c = a + b;

	cout << c.getVal() << endl;

	MyMadInt x = MyMadInt(4);
	MyMadInt y = MyMadInt(3);
	int z = x + y;

	cout << z << endl;

	return 0;
}
