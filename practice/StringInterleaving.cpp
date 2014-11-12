/*
 * StringInterleaving.cpp
 *
 *  Created on: Nov 3, 2014
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

void print_inter(char * str1, int m, char * str2, int n, char * str3,
		int index) {

	if (m == 0 && n == 0) {
		ps(str3);
		return;
	}

	if (m != 0) {
		str3[index] = *str1;
		print_inter(str1 + 1, m - 1, str2, n, str3, index + 1);
	}

	if (n != 0) {
		str3[index] = *str2;
		print_inter(str1, m, str2 + 1, n - 1, str3, index + 1);
	}
}

int main(int argc, char * argv[]) {

	char str1[100], str2[100], str3[100];
	ss(str1);
	ss(str2);

	int m = strlen(str1);
	int n = strlen(str2);
	str3[m + n] = '\0';

	print_inter(str1, m, str2, n, str3, 0);

	return 0;
}
