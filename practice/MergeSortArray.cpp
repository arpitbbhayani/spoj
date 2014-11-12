/*
 * MergeSortArray.cpp
 *
 *  Created on: Oct 2, 2014
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

void merge(int * array, int start, int mid, int end) {
	int * b = (int *) malloc(sizeof(int) * (end));

	int i, j, k;

	i = start;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= end) {
		if (array[i] < array[j]) {
			b[k++] = array[i++];
		} else {
			b[k++] = array[j++];
		}
	}

	while (i <= mid) {
		b[k++] = array[i++];
	}

	while (j <= end) {
		b[k++] = array[j++];
	}

	for (i = start; i <= end; i++) {
		array[i] = b[i - start];
	}

	free(b);
}

void mergesort(int *array, int start, int end) {

	if (start >= end)
		return;

	int mid = (start + end) / 2;

	mergesort(array, start, mid);
	mergesort(array, mid + 1, end);
	merge(array, start, mid, end);

}

int main(int argc, char * argv[]) {

	int * array = (int *) malloc(8 * sizeof(int));
	int n = 8;

	array[0] = 1;
	array[1] = 3;
	array[2] = 2;
	array[3] = 5;
	array[4] = 4;
	array[5] = 7;
	array[6] = 6;
	array[7] = 0;

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	mergesort(array, 0, n);

	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}
