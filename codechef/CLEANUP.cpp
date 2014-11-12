/*
 * CLEANUP.cpp
 *
 *  Created on: Sep 15, 2014
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

#define ASIZE 10

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {

		int indexa = 0, indexb = 0;
		int a[1010], b[1010], c[1010];

		int m = 0, n = 0, x;

		si(n);
		si(m);

		for (int i = 0; i < 1010; i++) {
			a[i] = b[i] = c[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			si(x);
			c[x] = 1;
		}

		int chance_chef = 1;

		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				if (chance_chef == 1) {
					a[indexa++] = i;
				} else {
					b[indexb++] = i;
				}

				chance_chef = 1 - chance_chef;
			}
		}

		for (int i = 0; i < indexa; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		for (int i = 0; i < indexb; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");

	}
	return 0;
}
