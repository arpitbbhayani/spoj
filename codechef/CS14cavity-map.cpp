/*
 * CS14cavity-map.cpp
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

	char str[110][110];

	int n;
	si(n);

	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				printf("%c", str[i][j]);
			else if (str[i][j] > str[i - 1][j] && str[i][j] > str[i + 1][j]
					&& str[i][j] > str[i][j - 1] && str[i][j] > str[i][j + 1]) {
				printf("X");
			} else {
				printf("%c", str[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
