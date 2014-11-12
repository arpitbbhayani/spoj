/*
 * sherlock-and-array.cpp
 *
 *  Created on: Aug 24, 2014
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

#define ASIZE 100010

int a[ASIZE];

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {

		bool found = false;
		int n;
		si(n);

		fup(i,0,n)
		{
			scanf("%d", &a[i]);
		}

		int low = 0, high = n - 1;
		ll int suml = 0, sumr = 0;

		while (low != high) {

			if( low > high )
				break;

			if (suml < sumr) {
				suml += a[low];
				low++;
			}

			else if (suml > sumr) {
				sumr += a[high];
				high--;
			}

			else {
				suml += a[low];
				sumr += a[high];
				low++;
				high--;
			}

		}

		if (suml == sumr && low == high) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
