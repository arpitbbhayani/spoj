/*
 * FROGV.cpp
 *
 *  Created on: Jul 8, 2014
 *      Author: Arpit Bhayani
 */

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

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

struct frog {
	int index;ll int x;
};

int compar(const void * a, const void * b) {

	if (((struct frog *) a)->x == ((struct frog *) b)->x) {
		return ((struct frog *) a)->index - ((struct frog *) b)->index;
	}
	return ((struct frog *) a)->x - ((struct frog *) b)->x;
}

int arr[100010];
struct frog array[100010];

int find_set(int a) {
	while (a != arr[a])
		a = arr[a];

	return a;
}

int main(int argc, char * argv[]) {

	ll int n, k, p;
	ll int x;
	scanf("%lld%lld%lld", &n, &k, &p);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		array[i].index = i + 1;
		array[i].x = x;

		arr[i + 1] = i + 1;
	}

	qsort(array, n, sizeof(array[0]), compar);

	for (int i = 1; i < n; i++) {

		if ((array[i].x - array[i - 1].x) <= k) {
			arr[find_set(array[i].index)] = find_set(array[i - 1].index);
		}

	}

	for (int i = 0; i < p; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (find_set(a) == find_set(b)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
