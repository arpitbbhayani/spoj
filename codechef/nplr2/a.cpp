/*
 * a.cpp
 *
 *  Created on: Oct 2, 2014
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

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {
		ll int x1, y1, x2, y2;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

		if (x1 > x2) {
			int te;
			te = x1;
			x1 = x2;
			x2 = te;

			te = y1;
			y1 = y2;
			y2 = te;
		}

		if (x1 == x2) {

			if (y1 > y2) {
				int te;
				te = x1;
				x1 = x2;
				x2 = te;

				te = y1;
				y1 = y2;
				y2 = te;
			}

		}

		ll int dx = (x2 - x1);
		ll int dy = (y2 - y1);

		if (dy == dx) {
			cout << dx - 1 << endl;
			continue;
		}

		int count = 0;

		if (x1 != x2) {

			ll int x;
			ll int ox = x1 + 1;
			for (x = x1 + 1; x < x2; x++) {
				ll int y = y1 + dy * (x - x1) / dx;
				if ((dy * (x - x1)) % dx == 0) {
					break;
					count++;
				}
			}

			dx = abs((x - ox));
			for (; x < x2; x += (dx)) {
				count++;
			}

		} else {

			ll int y;
			ll int oy = y1 + 1;
			for (y = y1 + 1; y < y2; y++) {
				ll int x = x1 + dx * (y - y1) / dy;
				if ((dx * (y - y1)) % dy == 0) {
					//count++;
					break;
				}
			}

			dy = abs((y - oy));
			for (; y < y2; y += dy) {
				count++;
			}

		}

		printf("%lld\n", count);

	}
	return 0;
}

