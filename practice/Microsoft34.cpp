/*
 * Microsoft34.cpp
 *
 *  Created on: Oct 9, 2014
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

void merge(int * array1, int * array2, int * array3, int n1, int n2, int n3) {

	int i, j, k;
	i = 0, j = 0, k = 0;

	while (i < n1 && j < n2) {
		if (array1[i] < array2[j]) {
			array3[k++] = array1[i++];
		} else {
			array3[k++] = array2[j++];
		}
	}

	while (i < n1) {
		array3[k++] = array1[i++];
	}

	while (j < n2) {
		array3[k++] = array2[j++];
	}

}

int main(int argc, char * argv[]) {

	int array1[] = { 1, 2, 3, 4, 5 }, n1 = sizeof(array1) / sizeof(array1[0]);
	int array2[] = { 6, 7, 8, 9, 10 }, n2 = sizeof(array2) / sizeof(array2[0]);

	int array3[n1 + n2], n3 = n1 + n2;

	merge(array1, array2, array3, n1, n2, n3);

	for (int i = 0; i < n3; i++) {
		pi(array3[i]);
	}

	return 0;
}
