/*
 * Microsoft113.cpp
 *
 *  Created on: Aug 26, 2014
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

int strcmp_ic(const char * stra, const char * strb) {

	int i = 0, j = 0;

	char a, b;
	char a5, b5;

	while (1) {

		a = stra[i], b = strb[j];
		a5 = a | (1 << 5), b5 = b | (1 << 5);

		if (a5 == b5) {

		} else if (a5 < b5) {
			return -1;
		} else {
			return 1;
		}

		i++;
		j++;

		if (stra[i] == '\0' || strb[j] == '\0')
			break;
	}

	if (stra[i] == '\0' && strb[i] == '\0') {
		return 0;
	}

	if ( a5 < b5 )
		return -1;
	return 0;

}

int main(int argc, char * argv[]) {

	cout << strcmp_ic("arpit", "arpit") << strcmpi("arpit", "arpit") << endl;
	cout << strcmp_ic("arpit", "ARPIT") << strcmpi("arpit", "ARPIT") << endl;
	cout << strcmp_ic("arPiT", "Arpit") << strcmpi("arPiT", "Arpit") << endl;
	cout << strcmp_ic("arpit Bhayani", "Arpit Bhayani")
			<< strcmpi("arpit Bhayani", "Arpit Bhayani") << endl;
	cout << strcmp_ic("arpit", "bhayani") << strcmpi("arpit", "bhayani")
			<< endl;
	cout << strcmp_ic("arpit", "Bhayani") << strcmpi("arpit", "Bhayani")
			<< endl;
	cout << strcmp_ic("Arpit", "Bhayani") << strcmpi("Arpit", "Bhayani")
			<< endl;
	cout << strcmp_ic("Arpit", "Aramis") << strcmpi("Arpit", "Aramis") << endl;
	cout << strcmp_ic("Aramis", "Arpit") << strcmpi("Aramis", "Arpit") << endl;

	cout << strcmp_ic("Bramis", "brpit") << strcmpi("Bramis", "brpit") << endl;

	return 0;
}
