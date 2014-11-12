/*
 * Google14.cpp
 *
 *  Created on: Aug 14, 2014
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

	int array[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int jump[11] = { 0 };
	int n = 10;

	jump[0] = 0;

	for (int i = 1; i < n; i++) {

		jump[i] = INT_MAX;

		for (int j = 0; j < i; j++) {

			if (i <= j + array[j]) {
				jump[i] = min(jump[i], jump[j] + 1);
			}

		}

	}

	cout << jump[n - 1] << endl;

	return 0;
}
