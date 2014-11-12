/*
 * linkedin22.cpp
 *
 *  Created on: Oct 22, 2014
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
#define MAX_TICKETS 100
int hash[MAX_TICKETS];

int main(int argc, char * argv[]) {

	int n, m, x;
	si(n);
	si(m);

	int max_t = 0;
	for (int i = 0; i < 2; i++) {
		si(x);
		trace1(x);
		for (int j = x; j > 0; j--) {
			hash[j]++;
		}
		max_t = max(max_t, x);
	}

	for (int i = 1; i <= max_t; i++) {
		cout << hash[i] << " ";
	}
	cout << endl;

	int sum = 0;
	while (m) {

		if (max_t < 0) {
			break;
		}

		if (hash[max_t] == 0) {
			max_t--;
		} else {
			sum += max_t;
			hash[max_t]--;
			m--;
		}
	}

	pi(sum);
	return 0;
}
