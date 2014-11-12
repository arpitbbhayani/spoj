/*
 * PSYCHON.cpp
 *
 *  Created on: Jul 15, 2014
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

#define ASIZE 10000010

int temp[ASIZE];
vector<int> p;

void sieve() {

	for (int i = 2; i < ASIZE; i++) {

		if (temp[i] == 1) {
			continue;
		}

		p.push_back(i);

		for (int j = 1;; j++) {
			if (i * j >= ASIZE)
				break;
			temp[i * j] = 1;
		}
	}
}

int main(int argc, char * argv[]) {

	sieve();

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		si(n);

		if (n == 0 || n == 1) {
			printf("Ordinary Number\n");
			continue;
		}

		int count = 0;
		int odd = 0, even = 0;

		for (int i = 0; i < p.size();) {
			if (n % p[i] == 0) {
				count++;
				n /= p[i];
			} else {

				if (count & 1) {
					odd++;
				} else {
					even++;
				}
				count = 0;
				i++;
			}

			if (n == 1)
				break;
		}

		if (count != 0) {
			if (count & 1) {
				odd++;
			} else {
				even++;
			}
		}

		if (even > odd) {
			printf("Psycho Number\n");
		} else {
			printf("Ordinary Number\n");
		}

	}
	return 0;
}
