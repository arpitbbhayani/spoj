/*
 * AMR12B.cpp
 *
 *  Created on: May 30, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0
#define gc getchar
#define ll long long

#define SIZE 1000010
int array[SIZE];

void scanint(int &x) {
	register int c = gc();
	x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		x = (x << 1) + (x << 3) + c - 48;
	}
}

int main(int argc, char * argv[]) {

	int t;
	scanint(t);

	for (int z = 0; z < t; z++) {

		int n, k, a, b;
		//scanf("%d%d", &n, &k);
		scanint(n);
		scanint(k);

		for (int i = 1; i < n; i++) {
			array[i] = i + 1;
		}
		array[n] = n;

		for (int i = 0; i < k; i++) {
			//scanf("%d%d", &a, &b);
			scanint(a);
			scanint(b);
			array[b] = a;
		}

		int flag = 1;
		for (int i = n; i >= 1; i--) {
			if (array[i] == i) {
				cout << "2 " << i << endl;
				flag = 0;
			}
		}

		if (flag == 1) {
			cout << "1" << endl;
		}

	}

	return 0;
}
