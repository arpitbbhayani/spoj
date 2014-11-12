/*
 * two-arrays.cpp
 *
 *  Created on: Aug 24, 2014
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

#define ASIZE 1010
ll int a[ASIZE], b[ASIZE];

int comparasc(const void * x, const void * y) {
	return (*((ll int *) x)) - (*((ll int *) y));
}

int compardsc(const void * x, const void * y) {
	return (*((ll int *) y)) - (*((ll int *) x));
}

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {

		int n, k;
		si(n);
		si(k);

		fup(i,0,n)
		{
			scanf("%lld", &a[i]);
		}

		fup(i,0,n)
		{
			scanf("%lld", &b[i]);
		}

		qsort(a, n, sizeof(ll int), comparasc);
		qsort(b, n, sizeof(ll int), compardsc);

		int isTrue = true;

		for (int i = 0; i < n; i++) {

			if ((a[i] + b[i]) < (ll int) k) {
				isTrue = false;
				break;
			}
		}

		if (isTrue == true) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
