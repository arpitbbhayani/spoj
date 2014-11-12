/*
 * Microsoft210.cpp
 *
 *  Created on: Sep 28, 2014
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

int compar(const void * a, const void * b) {
	int * x = (int *) a;
	int * y = (int *) b;

	return *x < *y;
}

int main(int argc, char * argv[]) {

	/**
	 * Three line segments form a right triangle if and only if their three sides a, b, and c satisfy a2+b2=c2 where c is the longest side.
	 * Three line segments form an acute triangle if and only if their three sides a, b, and c satisfy a2+b2>c2 where c is the longest side.
	 * Three line segments form an obtuse triangle if and only if their three sides a, b, and c satisfy a2+b2<c2 where c is the longest side.
	 */

	int array[3];
	int a, b, c;

	for (int i = 0; i < 3; i++)
		si(array[i]);

	qsort(array, 3, sizeof(int), compar);

	c = array[0] * array[0];
	b = array[1] * array[1];
	a = array[2] * array[2];

	if (c == a + b) {
		ps("right angled triangle");
	} else if (c < a + b) {
		ps("acute angled triangle");
	} else if (c > a + b) {
		ps("obtuse angled triangle");
	}

	return 0;
}
