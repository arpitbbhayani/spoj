/*
 * even-tree.cpp
 *
 *  Created on: Oct 7, 2014
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

int parent[110];
int cou[110];

int main(int argc, char * argv[]) {

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cou[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		parent[a] = b;
		cou[b] += cou[a];

		int root = parent[b];

		while (root != 0) {
			cou[root] += cou[a];
			root = parent[root];
		}
	}

	//for (int i = 0; i <= n; i++) {
	//	printf("%d - %d\n", i, cou[i]);
	//}

	int c = 0;

	for (int i = 1; i <= n; i++) {
		if (!(cou[i] & 1)) {
			c++;
		}
	}

	cout << c - 1 << endl;

	return 0;
}
