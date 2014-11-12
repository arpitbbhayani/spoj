/*
 * CS14broken-keyboard.cpp
 *
 *  Created on: Sep 13, 2014
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

#define ASIZE 110

char str[ASIZE];
char keys[ASIZE];

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {

		int hash1[26] = { 0 };
		int hash2[26] = { 0 };

		scanf("%s", keys);
		scanf("%s", str);

		for (int i = 0; keys[i] != '\0'; i++) {
			hash1[keys[i] - 'a'] = 1;
		}

		for (int i = 0; str[i] != '\0'; i++) {
			hash2[str[i] - 'a'] = 1;
		}

		int count = 0;
		for (int i = 0; i < 26; i++) {
			if (hash1[i] == hash2[i] && hash1[i] == 1) {
				count++;
			}
		}

		pi(count);

	}
	return 0;
}
