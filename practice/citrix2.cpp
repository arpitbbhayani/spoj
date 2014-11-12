/*
 * citrix2.cpp
 *
 *  Created on: Oct 31, 2014
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

int ispseudo(char * a, char * b) {

	int hasha[26] = { 0 };
	int hashb[26] = { 0 };

	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			hasha[a[i] - 'a'] = 1;
		} else if (a[i] >= 'A' && a[i] <= 'Z') {
			hasha[a[i] - 'A'] = 1;
		} else {
		}
	}

	for (int i = 0; b[i] != '\0'; i++) {
		if (b[i] >= 'a' && b[i] <= 'z') {
			hashb[b[i] - 'a'] = 1;
		} else if (b[i] >= 'A' && b[i] <= 'Z') {
			hashb[b[i] - 'A'] = 1;
		} else {
		}
	}

	for (int i = 0; i < 26; i++) {
		if (hasha[i] != hashb[i]) {
			trace1(i)
			return 0;
		}
	}
	return 1;

}

int main(int argc, char * argv[]) {

	char * a = "aBcd";
	char * b = "bc-abcdabcdabcdad";

	cout << ispseudo(a, b) << endl;

	return 0;
}
