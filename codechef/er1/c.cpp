/*
 * c.cpp
 *
 *  Created on: Sep 27, 2014
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

int row = 0;
int col = 0;
ll int ** array123 = NULL;

int compar(const void * a, const void * b) {

	int i = 0;
	ll int ** aa = ( ll int **) a;
	ll int ** bb = ( ll int **) b;

	for (i = 0; i < col; i++) {

		if ((*aa)[i] != (*bb)[i])
			break;
	}

	if (i == col) {
		return 0;
	}

	return (*aa)[i] > (*bb)[i];

}

int main(int argc, char * argv[]) {

	int n, k;
	si(n);
	si(k);

	array123 = (ll int **) malloc(sizeof( ll int *) * 30);

	for (int i = 0; i < 30; i++) {
		array123[i] = ( ll int *) malloc(sizeof(ll int) * 30);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			sll(array123[i][j]);
		}
	}

	row = k;
	col = n;

	qsort(array123, row, sizeof(ll int *), compar);

	/*for (int i = 0; i < row; i++) {
	 for (int j = 0; j < col; j++) {

	 printf("%lld ", (array123[i][j]));

	 }
	 printf("\n");
	 }*/

	for (int i = 1; i < col; i++) {
		array123[0][i] = array123[0][i] + array123[0][i - 1];
	}

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {

			if (array123[i - 1][j]
					< (min(array123[i - 1][j - 1], array123[i][j - 1])
							+ array123[i][j])) {
				array123[i][j] = array123[i - 1][j];
			} else {
				array123[i][j] = min(array123[i - 1][j - 1], array123[i][j - 1])
						+ array123[i][j];
			}

		}
	}

	pll(array123[row - 1][col - 1]);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			printf("%lld ", (array123[i][j]));

		}
		printf("\n");
	}

	return 0;
}
