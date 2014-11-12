/*
 * CS14bigger-is-greater.cpp
 *
 *  Created on: Sep 13, 2014
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
#define ss(x) scanf("%s" , x)

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

#define ASIZE 110
char str[ASIZE];

int findNearestGreater(int e, int len) {

	int index = e;
	for (int i = e; i < len; i++) {
		if (str[i] > str[e - 1] && str[index] >= str[i]) {
			index = i;
		}
	}
	return index;
}

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	int len, e;
	char temp;
	int index;

	while (t--) {
		ss(str);
		len = strlen(str);
		e = len;
		while ((--e) > 0) {
			if (str[e] > str[e - 1])
				break;
		}

		if (e == 0) {
			printf("no answer\n");
			continue;
		} else {
			index = findNearestGreater(e, len);
			//swap(index, e);

			for (int i = 0; i <= e-2; i++)
				printf("%c", str[i]);

			printf("%c", str[index]);

			for (int i = len - 1; i >= e; i--) {
				if (i == index) {
					printf("%c", str[e-1]);
				} else {
					printf("%c", str[i]);
				}
			}

			printf("\n");
		}
	}
	return 0;
}
