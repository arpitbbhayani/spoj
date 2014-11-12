/*
 * Google15.cpp
 *
 *  Created on: Aug 14, 2014
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

#define pi(x) printf("%d" , &x)
#define pl(x) printf("%ld" , &x)
#define pll(x) printf("%lld" , &x)
#define pc(x) printf("%c" , &x)
#define ps(x) printf("%s" , &x)

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

struct minheapcomparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};

priority_queue<int> l;
priority_queue<int, vector<int>, minheapcomparator> r;

int check_size() {
	if (l.size() == r.size())
		return 0;
	if (l.size() > r.size()) {
		return -1;
	} else {
		return 1;
	}
}

int median(int current_element, int &median) {

	int c = check_size();
	switch (c) {

	case 0:

		//cout << l.size() << " 0and0 " << r.size() << endl;
		if (current_element < median) {
			l.push(current_element);
			median = l.top();
		} else {
			r.push(current_element);
			median = r.top();
		}

		break;
	case -1:

		//cout << l.size() << " -1and-1 " << r.size() << endl;
		if (current_element < median) {

			int t = l.top();
			l.pop();
			r.push(t);

			l.push(current_element);

			median = (l.top() + r.top()) / 2;

		} else {
			r.push(current_element);
			median = (l.top() + r.top()) / 2;
		}

		break;
	case 1:

		//cout << l.size() << " 1and1 " << r.size() << endl;
		if (current_element < median) {
			l.push(current_element);
			median = (l.top() + r.top()) / 2;
		} else {

			int t = r.top();
			r.pop();
			l.push(t);

			r.push(current_element);
			median = (l.top() + r.top()) / 2;
		}

		break;

	default:
		cout << "NOOOOOO" << endl;

	}

	return median;

}

int main(int argc, char * argv[]) {

	int m, n = 12;
	int a[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };

	fup(i,0,n)
	{
		int k = median(a[i], m);
		cout << k << endl;
	}

	return 0;
}
