/*
 * CS14jigar-and-strings.cpp
 *
 *  Created on: Sep 19, 2014
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

#define ASIZE 2000

char str[ASIZE];

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);

		int hash[26] = { 0 };

		int min = INT_MAX, max = INT_MIN;

		for (int i = 0; str[i] != '\0'; i++) {
			hash[str[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (hash[i] > max) {
				max = hash[i];
			}
			if (hash[i] < min) {
				min = hash[i];
			}
		}

		int count = -1;

		while (max != min) {
			// check for each val between min and max

			int temp_count = 0;

			min++;

			for( int i = 0 ; i < 26 ; i++ ) {
				if( hash[i] != 0 ) {
					temp_count += abs(min - hash[i]);
				}
			}

			temp_count = temp_count / 2;

			if( count == -1 ) {
				count = temp_count;
			}
			else {
				if( temp_count < count ) {
					count = temp_count;
				}
			}

		}

		printf("%d\n", count);

	}
	return 0;
}
