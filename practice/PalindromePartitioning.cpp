/*
 * PalindromePartitioning.cpp
 *
 *  Created on: Nov 4, 2014
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
int hash[100][100];
int palin[100][100];

int _pp(const char * str, int i, int j) {

	if (i == j) {
		palin[i][j] = 1;
		hash[i][j] = 0;
		return 0;
	}

	if (hash[i][j] != -1) {
		return hash[i][j];
	}

	int result = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp = _pp(str, i, k) + _pp(str, k + 1, j) + 1;
		result = min(result, temp);
	}

	if (i == j - 1) {
		palin[i][j] = (str[i] == str[j]);
	} else {
		palin[i][j] = (str[i] == str[j]) && palin[i + 1][j - 1];
	}

	if (palin[i][j] == 1) {
		hash[i][j] = 0;
		return 0;
	}

	hash[i][j] = result;
	return result;
}

int pp(const char * str, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			hash[i][j] = -1;
		}
	}
	return _pp(str, 0, n - 1);
}

int main(int argc, char * argv[]) {
	char str[100];
	ss(str);
	int n = strlen(str);
	cout << pp(str, n) << endl;
	return 0;
}
