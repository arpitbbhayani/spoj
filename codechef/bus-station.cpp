/*
 * bus-station.cpp
 *
 *  Created on: Aug 22, 2014
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

	int n;
	scanf("%d", &n);

	int * array = ( int *) malloc(n * sizeof(int));

	ll int sum = 0;
	int index=  0;
	int max = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
		sum += array[i];

		if (array[i] > max)
			max = array[i];
	}

	index = 0;
	int number = 0;

	for( index = 0 ; index < n ; index++ ) {
		number += array[index];
		if( number >= max )
			break;
	}

	while (1) {

		if (number > sum || index == n)
			break;

		if (sum % number == 0) {

			int i = 0;
			ll int s = 0;
			for (i = 0; i < n; i++) {
				s += array[i];
				if (s == number) {
					s = 0;
				} else if (s > number) {
					break;
				}
			}

			if (i == n)
				printf("%d ", number);

		}

		index++;

		//number+=array[index];
		number++;

	}

	printf("\n");

	return 0;
}
