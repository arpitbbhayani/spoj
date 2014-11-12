/*
 * h.cpp
 *
 *  Created on: Sep 29, 2014
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

#define ASIZE 110

double x[ASIZE];
double y[ASIZE];
double r[ASIZE];
int flag[ASIZE];

int main(int argc, char * argv[]) {

	int t;
	si(t);
	while (t != 0) {

		for (int i = 0; i < ASIZE; i++) {
			flag[i] = 0;
		}

		for (int i = 0; i < t; i++) {
			cin >> x[i] >> y[i] >> r[i];
		}

		int num_merge = 1;

		while (num_merge != 0) {

			num_merge = 0;
			int x1;

			for (int i = 0; i < t; i++) {

				for (int j = i + 1; j < t; j++) {

					if (flag[j] == 0 && flag[i] == 0) {

						// I AND J CAN BE MERGED

						if (((x[i] - x[j]) * (x[i] - x[j])
								+ (y[i] - y[j]) * (y[i] - y[j]))
								< (r[i] + r[j]) * (r[i] + r[j])) {

							num_merge = 1;

							flag[i] = 1;
							flag[j] = 0;

							x[j] = (x[i] + x[j]) / 2;
							y[j] = (y[i] + y[j]) / 2;

							r[j] = sqrt((r[i] * r[i] + r[j] * r[j]));

						}
					}

				}

				if (num_merge == 0)
					break;
			}

		}

		int count = 0;
		for (int i = 0; i < t; i++) {
			if( flag[i] == 0 ) {
				count++;
			}
		}
		pi(count + 1);

		si(t);
	}
	return 0;
}
