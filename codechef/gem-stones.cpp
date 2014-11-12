/*
 * gem-stones.cpp
 *
 *  Created on: Sep 6, 2014
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

int main(int argc, char * argv[]) {

	char str[110];
	int count[26] = { 0 };

	int n;
	int t;
	scanf("%d", &t);

	n = t;

	while (t--) {

		scanf("%s", str);
		int visited[26] = { 0 };

		for (int i = 0; str[i] != '\0'; i++) {
			if (visited[str[i] - 'a'] == 0) {
				visited[str[i] - 'a'] = 1;
				count[str[i] - 'a'] += 1;
			}
		}
	}

	int c = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] == n) {
			c++;
		}
	}

	pi(c);

	return 0;
}
