/*
 * KMP_DFA.cpp
 *
 *  Created on: Oct 19, 2014
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

	char pattern[15] = "TEST";

	int dfa[255][15] = { 0 };

	int x = 0;

	for (int i = 0; pattern[i] != '\0'; i++) {

		for (int j = 0; j < 255; j++) {
			dfa[j][i] = dfa[j][x];
		}
		x = dfa[pattern[i]][x];
		dfa[pattern[i]][i] = i + 1;
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 0; j < strlen(pattern); j++) {
			printf("%d ", dfa[i][j]);
		}
		printf("\n");
	}

	char text[1024] = "THIS IS A TESTEST";
	char * pat = pattern;

	int i, j = 0;
	for (i = 0, j = 0; text[i] && j < strlen(pat); i++) {
		j = dfa[text[i]][j];
		if (j == strlen(pat)) {
			printf("PATTERN FOUND AT INDEX : %d\n", i - strlen(pat) + 1);
			j = 0;
		}
	}

	return 0;
}
