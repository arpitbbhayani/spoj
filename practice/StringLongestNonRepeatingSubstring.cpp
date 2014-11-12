/*
 * StringLongestNonRepeatingSubstring.cpp
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

int main(int argc, char * argv[]) {

	char str[100];
	ss(str);

	//http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

	int hash[256];
	for (int i = 0; i < 256; i++)
		hash[i] = -1;

	int maxstart = 0, maxend = 0;
	int start = 0, end = 0;
	int maxlen = INT_MIN;

	for (int i = 1; str[i] != '\0'; i++) {
		int index = hash[str[i]];
		if (index == -1) {
			hash[str[i]] = i;
			// include in current
			end = i;
		} else {
			if (index < start) {

				// do nothing
			} else {
				start = index + 1;
				end = i;
				hash[str[i]] = i;
			}
		}

		if (end - start + 1 > maxlen) {
			//trace2(start, end);
			maxlen = end - start + 1;
			maxstart = start;
			maxend = end;
		}

		//maxlen = max(maxlen, end - start + 1);

	}

	cout << maxlen << endl;
	for (int i = maxstart; i <= maxend; i++) {
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
