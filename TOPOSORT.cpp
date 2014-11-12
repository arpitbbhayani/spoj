/*
 * TOPOSORT.cpp
 *
 *  Created on: Oct 26, 2014
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

#define ASIZE 10010

int n;
list<int> nodes[ASIZE];
int visited[ASIZE];
int in[ASIZE];
list<int> l;

class cmp {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

int topo_sort() {

	priority_queue<int, vector<int>, cmp> q;

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	if (q.size() == 0) {
		return 1;
	}

	while (!q.empty()) {
		int parent = q.top();
		l.push_back(parent);
		q.pop();

		visited[parent] = 1;
		for (list<int>::iterator itr = nodes[parent].begin();
				itr != nodes[parent].end(); itr++) {

			int child = *itr;
			if (visited[child] == 1) {
				return 1;
			}
			in[child]--;
			if (in[child] == 0) {
				q.push(child);
			}
		}
	}

	return 2;
}

int main(int argc, char * argv[]) {

	int m;
	si(n);
	si(m);

	for (int i = 0; i < m; i++) {
		int x, y;
		si(x);
		si(y);
		nodes[x].push_back(y);
		in[y]++;
	}

	int r = topo_sort();

	if (r == 1) {
		cout << "Sandro fails." << endl;
	} else {

		list<int>::iterator itr = l.begin();

		for (; itr != l.end(); itr++) {
			cout << *itr << " ";
		}
		cout << endl;

	}
	return 0;
}
