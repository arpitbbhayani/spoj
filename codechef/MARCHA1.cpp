/*
 * MARCHA1.cpp
 *
 *  Created on: Sep 15, 2014
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

#define ASIZE 32

int array[ASIZE];

int compar(const void * a, const void * b) {
	return *(const int *) a > *(const int *) b;
}

int is_sum(int n, int m) {

	if( m == 0 )
		return 1;

	if( n == 0 && m != 0 )
		return false;

	if(array[n-1] > m) {
		return is_sum(n-1,m);
	}

	int l = is_sum(n-1,m);
	int r = is_sum(n-1,m - array[n-1]);

	return l || r;
}

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {

		int n, m;
		si(n);
		si(m);

		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
		}

		if (is_sum(n, m)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

	}
	return 0;
}
