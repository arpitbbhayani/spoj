/*
 * MergeIntervals.cpp
 *
 *  Created on: Sep 5, 2014
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

struct Interval {
	int start;
	int end;
};

int compar(const void * a, const void * b) {

	struct Interval * x = (struct Interval *) a;
	struct Interval * y = (struct Interval *) b;

	return x->start > y->start;

}

#define ASIZE 4

int main(int argc, char * argv[]) {

	int n = ASIZE;
	struct Interval intervals[ASIZE];

	int start[ASIZE] = { 1, 5, 2, 6 };
	int end[ASIZE] = { 3, 7, 4, 8 };

	for (int i = 0; i < n; i++) {
		intervals[i].start = start[i];
		intervals[i].end = end[i];
	}

	qsort(intervals, n, sizeof(intervals[0]), compar);

	stack<struct Interval> s;

	s.push(intervals[0]);

	for (int i = 0; i < n; i++) {
		if (s.top().end < intervals[i].start) {
			// Non Overlapping
			s.push(intervals[i]);
		} else {

			// Can be merged
			if (s.top().end < intervals[i].end) {
				s.top().end = intervals[i].end;
			} else {
				// do nothing
			}

		}
	}

	while (!s.empty()) {
		cout << s.top().start << " - " << s.top().end << endl;
		s.pop();
	}

	return 0;
}

