/*
 * a2c.cpp
 *
 *  Created on: Sep 3, 2014
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

#define ASIZE 1000010
int array[ASIZE];

int main(int argc, char * argv[]) {

	for (int i = 1; i < ASIZE; i++) {
		array[i] = 1;
	}

	for (int i = 2;; i++) {
		ll int cube = i * i * i;

		if (cube > ASIZE)
			break;

		for (int j = 1; cube * j <= ASIZE; j++) {
			array[cube * j] = 0;
		}
	}

	for (int i = 1; i < ASIZE; i++) {
		//cout << "i = " << i << " and array[i] = " << array[i] << endl;
		array[i] = array[i] + array[i - 1];
	}

	int t;
	scanf("%d", &t);

	while (t--) {

		int x;
		si(x);

		if (array[x] == array[x - 1]) {
			pi(0);
		} else {
			pi(array[x]);
		}

	}
	return 0;
}
