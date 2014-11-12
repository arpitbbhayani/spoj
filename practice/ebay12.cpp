/*
 * ebay11.cpp
 *
 *  Created on: Oct 16, 2014
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

#define ASIZE 64

char text[ASIZE], pat1[ASIZE], pat2[ASIZE];
char ans[ASIZE];
int dfa[256][ASIZE];

void filldfa(char * pat, int l) {

	memset(dfa, 0, sizeof(dfa));
	int x = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < 256; j++) {
			dfa[j][i] = dfa[j][x];
		}
		dfa[pat[i]][i] = i + 1;
	}

}

int main(int argc, char * argv[]) {

	ss(text);
	ss(pat1);
	ss(pat2);

	int lt = strlen(text), l1 = strlen(pat1), l2 = strlen(pat2);

	filldfa(pat1, l1);

	int i, j = 0, k = 0;
	for (i = 0, j = 0; i < lt && j < l1; i++) {

		ans[k++] = text[i];

		j = dfa[text[i]][j];
		if (j == l1) {

			int start = k - l1, index = 0;
			for (; index < l2; index++) {
				ans[start++] = pat2[index];
			}
			k = start;

			j = 0;
		}
	}

	ans[k] = '\0';

	ps(ans);

	return 0;
}
