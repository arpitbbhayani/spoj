/*
 * A.cpp
 *
 *  Created on: Aug 15, 2014
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

int is_safe(int x3, int y3, int x4, int y4) {

	if (!(x3 >= -1000 && x3 <= 1000))
		return 0;
	if (!(x4 >= -1000 && x4 <= 1000))
		return 0;
	if (!(y3 >= -1000 && y3 <= 1000))
		return 0;
	if (!(y4 >= -1000 && y4 <= 1000))
		return 0;

	return 1;
}

int main(int argc, char * argv[]) {

	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2;

	x3 = x1;
	x4 = x2;
	y3 = y1;
	y4 = y2;

	if (!(x1 == x2 || y1 == y2 || y1 - y2 == x1 - x2)) {
		cout << -1 << endl;
		return 0;
	}

	if (x1 == x2) {

		int length = abs(y1 - y2);

		if (is_safe(x3 + length, y3, x4 + length, y4)) {
			printf("%d %d %d %d\n", x3 + length, y3, x4 + length, y4);
		} else if (is_safe(x3 - length, y3, x4 - length, y4)) {
			printf("%d %d %d %d\n", x3 - length, y3, x4 - length, y4);
		} else {
			pi(-1);
		}

	} else if (y1 == y2) {

		int length = abs(x1 - x2);

		if (is_safe(x3, y3 + length, x4, y4 + length)) {
			printf("%d %d %d %d\n", x3, y3 + length, x4, y4 + length);
		} else if (is_safe(x3, y3 - length, x4, y4 - length)) {
			printf("%d %d %d %d\n", x3, y3 - length, x4, y4 - length);
		} else {
			pi(-1);
		}

	} else {

		printf("%d %d %d %d\n", x3, y4, x4, y3);

	}

	return 0;
}

