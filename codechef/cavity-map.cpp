/*
 * cavity-map.cpp
 *
 *  Created on: Aug 21, 2014
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

#define ASIZE 110

char array123[ASIZE][ASIZE];

int main(int argc, char * argv[]) {

	int n;

	scanf("%d", &n);

	getchar();

	for (int i = 0; i < n; i++) {
		scanf("%s" , &array123[i]);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if(i == 0 || j == 0 || i == n-1 || j == n-1) {
				cout << array123[i][j];
				continue;
			}

			if ((array123[i][j] > array123[i - 1][j])
					&& (array123[i][j] > array123[i + 1][j])
					&& (array123[i][j] > array123[i][j - 1])
					&& (array123[i][j] > array123[i][j + 1])) {

				cout << "X";
			} else {
				cout << array123[i][j];
			}

		}
		cout << endl;
	}

	return 0;
}
