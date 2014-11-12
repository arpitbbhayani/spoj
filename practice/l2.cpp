/*
 * l2.cpp
 *
 *  Created on: Nov 9, 2014
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

#define ASIZE 10
#define MOD 1000000007

ll int array[3][4] = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };
ll int array2[3][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

ll int fun(int row, int col) {

	int i = 0;
	for (i = 0; i < col; i++) {
		if (array[0][i] == 0) {
			break;
		} else {
			array2[0][i] = 1;
		}
	}

	for (; i < col; i++) {
		array2[0][i] = 0;
	}

	for (i = 0; i < row; i++) {
		if (array[i][0] == 0) {
			break;
		} else {
			array2[i][0] = 1;
		}
	}

	for (; i < row; i++) {
		array2[i][0] = 0;
	}

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {

			if (array[i][j] == 1) {
				array2[i][j] = (array2[i - 1][j] + array2[i][j - 1]) % MOD;
			} else {
				array2[i][j] = 0;
			}
		}
	}

	return array2[row - 1][col - 1];
}

int main(int argc, char * argv[]) {

	int row = 3;
	int col = 4;

	cout << fun(row, col) << endl;

	return 0;
}
