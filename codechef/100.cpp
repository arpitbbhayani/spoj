/*
 * 100.cpp
 *
 *  Created on: Sep 4, 2014
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

int main(int argc, char * argv[]) {

	int a, b;

	while (scanf("%d %d", &a, &b) != EOF) {

		int a1 = a, b1 = b;

		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}

		ll int maxcount = 0;

		while (a <= b) {

			ll int count = 0;
			ll int n = a;

			while (n != 1LL) {

				count++;

				if (n & 1)
					n = 3 * n + 1;
				else
					n >>= 1;
			}

			if (count > maxcount)
				maxcount = count;

			a++;

		}

		printf("%d %d %lld\n", a1, b1, maxcount + 1);

	}

	return 0;
}
