/*
 * Google18.cpp
 *
 *  Created on: Aug 15, 2014
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

int left(int * array, int n, int x) {

	int low = 0, high = n - 1;

	while (low <= high) {

		int mid = (low + high) / 2;

		if (mid == low && array[mid] == x) {
			return low;
		}

		if (array[mid] == x && array[mid - 1] != x) {
			return mid;
		}

		if (array[mid] == x) {
			high = mid - 1;
		}
		else if (x < array[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}

	}

	return -1;
}

int right(int * array, int n, int x) {

	int low = 0, high = n - 1;

	while (low <= high) {

		int mid = (low + high) / 2;

		//cout << "low = " << low << " mid = " << mid << " and high = " << high << endl;

		if (mid == high && array[mid] == x) {
			return high;
		}

		if (array[mid] == x && array[mid + 1] != x) {
			return mid;
		}

		if (x == array[mid]) {
			low = mid + 1;
		}
		else if (x < array[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}

	}

	return -1;
}

int num_occur(int * array, int n, int x) {

	int l = left(array, n, x);
	int r = right(array, n, x);

	return r - l + 1;

}

int main(int argc, char * argv[]) {

	int n = 10;
	int array[10] = { 1, 1, 1, 1, 1, 2, 3, 3, 3, 3 };

	cout << num_occur(array, n, 2) << endl;

	return 0;
}
