/*
 * CSUB.cpp
 *
 *  Created on: Jul 8, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

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

int len;
char str[100010];

ll int readline() {

	ll int count1 = 0;
	len = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[len++] = ch;

		if (ch == '1') {
			count1++;
		}
	}
	str[len] = '\0';
	return count1;
}

int main(int argc, char * argv[]) {

	int t, l;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &l);
		getchar();

		ll int count1 = readline();

		ll int result = 0;

		result += (ll int) count1;
		result += ((count1 * (count1 - 1)) / 2);

		cout << result << endl;
	}

	return 0;
}
