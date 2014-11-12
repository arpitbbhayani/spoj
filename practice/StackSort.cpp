/*
 * StackSort.cpp
 *
 *  Created on: Oct 13, 2014
 *      Author: Arpit Bhayani
 */

#include <map>
#include <cmath>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <ctime>
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

int main(int argc, char * argv[]) {

	srand(time(NULL));

	stack<int> s;
	int array[10];
	for (int k = 0; k < 10; k++) {
		array[k] = k;
	}

	printf("Stack : ");
	for (int i = 9; i >= 0; i--) {
		printf("%d ", array[i]);
		s.push(array[i]);
	}
	cout << endl;

	stack<int> t, u;

	while (!s.empty()) {

		int e = s.top();
		s.pop();

		//cout << "Current element : " << e << endl;

		if (t.empty() || e > t.top()) {
			//cout << "Pushing " << e << " to " << "t" << endl;
			t.push(e);
		} else {
			while (!t.empty() && t.top() > e) {
				//cout << "Pushing " << t.top() << " to " << "u" << endl;
				u.push(t.top());
				t.pop();
			}
			//cout << "Pushing " << e << " to " << "t" << endl;
			t.push(e);
			while (!u.empty()) {
				//cout << "Pushing " << u.top() << " to " << "t" << endl;
				t.push(u.top());
				u.pop();
			}
		}

	}

	printf("Stack : ");
	while (!t.empty()) {
		printf("%d ", t.top());
		t.pop();
	}
	cout << endl;
	return 0;
}
