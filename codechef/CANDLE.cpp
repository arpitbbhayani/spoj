/*
 * CANDLE.cpp
 *
 *  Created on: Sep 16, 2014
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
#include <sstream>

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

	int t;
	scanf("%d", &t);
	while (t--) {
		int array[10];

		int n = 10;

		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
		}

		int min_count = array[1], min_value = 1;

		for (int i = 2; i < n; i++) {
			if (array[i] < min_count) {
				min_count = array[i];
				min_value = i;
			}

		}


		if( array[0] < min_count ) {
			min_count = array[0];
			min_value = 0;
		}


		stringstream ss;
		string result;

		for( int i = 0 ; i <= min_count ; i++ ) {
			ss << min_value;
		}

		if( min_value == 0 ) {
			result = "1" + ss.str();
		}
		else {
			result = ss.str();
		}

		printf("%s\n" , result.c_str());

	}
	return 0;
}
