/*
 * sieve.cpp
 *
 *  Created on: Aug 25, 2014
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

#define ASIZE 125000001

/* Initially all values of prime are 0 */
char prime[ASIZE];

/*void p(int index, int val) {
 int r = index / 8;
 int c = index % 8;
 prime[r] = prime[r] | (1 << c);
 }

 int is_p(int index) {
 int r = index / 8;
 int c = index % 8;

 return prime[r] & (1 << c);
 }*/

int i = 0, j = 0;

void sieve() {

	prime[0] = prime[1] = 1;
	//p(0, 1);
	//p(1, 1);

	for (i = 2; i < ASIZE; i++) {

		if (prime[i] == 1) {
			continue;
		}

		//if (is_p(i) == 1) {
		//	continue;
		//}

		for (j = 2; i * j < ASIZE; j++) {
			prime[i * j] = 1;
			//p(i * j, 1);
		}
	}
}

int a, b, t;

int main(int argc, char * argv[]) {

	sieve();
	si(t);

	while (t--) {
		scanf("%d %d", &a, &b);

		for (i = a; i <= b; i++) {
			if (prime[i] == 0) {
				//if (is_p(i) == 0) {
				printf("%d\n", i);
			}
		}
		printf("\n");
	}

	return 0;
}
