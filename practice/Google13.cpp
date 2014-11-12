/*
 * Google13.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: Arpit Bhayani
 */

#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define DEBUG 0
#define gc getchar
#define ll long long

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

	priority_queue<int> q;

	int t, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		q.push(x);
	}

	int k;
	scanf("%d", &k);

	k--;

	while (k--) {
		//cout << q.top() << endl;
		q.pop();
	}

	cout << q.top() << endl;

	return 0;
}
