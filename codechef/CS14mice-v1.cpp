/*
 * CS14mice-v1.cpp
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

#define ASIZE 131082

int array1[ASIZE];
int array2[ASIZE];

int compar(const void * a, const void * b) {
	return *(const int *) a > *(const int *) b;
}

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		si(n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &array1[i]);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &array2[i]);
		}

		qsort(array1, n, sizeof(array1[0]), compar);
		qsort(array2, n, sizeof(array2[0]), compar);

		int diff = abs(array1[0] - array2[0]);
		//cout << "Subtracting : " << array1[0] << " and " << array2[0]
		//		<< " and diff = " << abs(array1[0] - array2[0]) << endl;
		for (int i = 1; i < n; i++) {

			//cout << "Subtracting : " << array1[i] << " and " << array2[i]
			//<< " and diff = " << abs(array1[i] - array2[i]) << endl;

			x = abs(array1[i] - array2[i]);
			if (x > diff)
				diff = x;
		}

		printf("%d\n", diff);

	}
	return 0;
}
