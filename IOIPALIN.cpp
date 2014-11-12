/*
 * IOIPALIN.cpp
 *
 *  Created on: Nov 6, 2014
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

#define ASIZE 5002

char str1[ASIZE];

int maxi(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char * argv[]) {

	int i = 0, j = 0, n = 0;
	int k = 0;
	si(n);

	int ** array = (int **) calloc((n + 1), sizeof(int *));
	for (int i = 0; i <= n; i++) {
		array[i] = (int *) calloc((n + 1), sizeof(int));
	}

	ss(str1);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (str1[i - 1] == str1[n - j]) {
				array[i][j] = array[i - 1][j - 1] + 1;
			} else {
				array[i][j] = maxi(array[i - 1][j], array[i][j - 1]);
			}

		}
	}

	pi(n - array[n][n]);
	return 0;
}
