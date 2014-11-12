/*
 * c.cpp
 *
 *  Created on: Oct 2, 2014
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

#define ASIZE 100010

int array1[ASIZE];
int array2[ASIZE];

int lcs(int *x, int * y, int ls, int lt) {

	int i, j, k;

	for (i = 1; i < ls + 1; i++) {
		for (j = 1; j < lt + 1; j++) {
			if (array1[i - 1] == array2[j - 1]) {
				y[j] = x[j - 1] + 1;
			} else {
				y[j] = y[j - 1] > x[j] ? y[j - 1] : x[j];
			}
		}

		int * t;
		t = x;
		x = y;
		y = t;
	}

	return x[lt];
}

int main(int argc, char * argv[]) {

	int x[ASIZE];
	int y[ASIZE];

	int t;
	scanf("%d", &t);
	while (t--) {

		int n;
		si(n);

		for (int i = 0; i < n; i++) {
			si(a[i]);
		}

		for (int i = 0; i < n; i++) {
			si(b[i]);
		}

		printf("%d\n", lcs(x, y, n, n));

	}

	return 0;
}
