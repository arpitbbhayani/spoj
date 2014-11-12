/*
 * Histogram.cpp
 *
 *  Created on: Sep 10, 2014
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

int get_max_area(int * hist, int n) {

	stack<int> s;

	int tp = 0, area_with_top = 0;
	int max_area = 0;

	int i = 0;

	while (i < n) {

		if (s.empty() || hist[i] > hist[s.top()])
			s.push(i++);

		else {

			tp = s.top();
			s.pop();

			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			cout << "i = " << i << " AREA = " << hist[tp] << " X "
					<< (s.empty() ? i : i - s.top() - 1) << " = "
					<< area_with_top;

			if (s.empty()) {
				cout << "s is empty so " << i;
			} else {
				cout << " i - s.top() - 1 s.top = " << s.top() << " i = " << i;
			}
			cout << endl;

			if (area_with_top > max_area) {
				max_area = area_with_top;
			}
		}
	}

	while (!s.empty()) {
		tp = s.top();
		s.pop();

		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

		cout << "2 AREA = " << hist[tp] << " X "
				<< (s.empty() ? i : i - s.top() - 1) << " = " << area_with_top
				<< endl;

		if (area_with_top > max_area) {
			max_area = area_with_top;
		}
	}

	return max_area;
}

int main(int argc, char * argv[]) {

	int n = 10;
	int hist[10] = { 6, 2, 5, 4, 5, 4, 4, 5, 1, 6 };

	//int n = 3;
	//int hist[3] = { 6, 2, 5 };

	cout << get_max_area(hist, n) << endl;

	return 0;
}
