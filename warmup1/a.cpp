/*
 * a.cpp
 *
 *  Created on: Sep 29, 2014
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

	char str[1024];

	int Z = 1;
	ll int a, b, c;
	sll(a);
	sll(b);

	while (a != 0LL && b != 0LL) {

		int total_count = 0;

		printf("Problem %d\n", Z++);

		c = a * b;

		sprintf(str, "%lld", c);

		int len = strlen(str);
		int final_len = len;

		printf("%*d\n", len, a);
		printf("%*d\n", len, b);

		for (int i = 0; i < final_len; i++)
			printf("-");
		printf("\n");

		int count0 = 0;
		while (b) {
			int d = b % 10;
			if (d == 0) {
				count0++;
			} else {
				break;
			}
			b = b / 10;
		}

		while (b) {
			int d = b % 10;

			if (d == 0) {
				count0++;
				b = b / 10;
				continue;
			}

			ll int mul = a * d;

			if (mul == 0LL) {
				len--;
			} else {

				total_count ++;
				len = len - count0;
				printf("%*lld", len--, a * d);
				for (int i = 0; i < count0; i++) {
					printf("0");
				}
				count0 = 0;
				printf("\n");
			}

			b = b / 10;
		}

		if (total_count > 1) {

			for (int i = 0; i < final_len; i++)
				printf("-");
			printf("\n");

			printf("%lld\n", c);
		}

		sll(a);
		sll(b);
	}

	return 0;
}
