/*
 * MaxSumMicrosoft.cpp
 *
 *  Created on: Nov 7, 2014
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

#define ASIZE 20
int array[ASIZE];

int hash[20];

int maxsum(int * array, int n) {

	for (int i = 0; i < ASIZE; i++) {
		hash[i] = -1;
	}

	int start = 0, end = 0;
	int result = array[0];

	hash[array[0]] = 0;
	int sum = array[0];

	for (int i = 1; i < n; i++) {

		int index = hash[array[i]];

		if (index == -1) {
			end = i;
			sum += array[end];
			//cout << "Sum += " << array[end] << endl;
			result = max(sum, result);
		} else {
			if (index < start) {
				// do nothing
			} else {
				int newstart = hash[array[i]] + 1;
				while (start != newstart) {
					//cout << "Sum -= " << array[start] << endl;
					sum -= array[start++];
				}
				end = i;
				sum += array[end];
				//cout << "Sum += " << array[end] << endl;
				result = max(sum, result);
			}
		}
		hash[array[i]] = i;
	}
	result = max(sum, result);

	return result;
}

int main(int argc, char * argv[]) {

	int n;
	si(n);

	for (int i = 0; i < n; i++) {
		si(array[i]);
	}

	cout << maxsum(array, n) << endl;
	return 0;
}
