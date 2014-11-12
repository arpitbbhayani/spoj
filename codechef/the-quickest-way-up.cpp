/*
 * the-quickest-way-up.cpp
 *
 *  Created on: Oct 7, 2014
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

#define ASIZE 10

int dist[110];
int visited[110];
list<int> nodes[110];

int last_visited[110];

int bfs(int start, int end) {

	queue<int> q;
	q.push(start);

	dist[start] = 0;

	while (!q.empty()) {

		int u = q.front();
		q.pop();

		if (visited[u] == 1) {
			continue;
		}

		visited[u] = 1;

		for (list<int>::iterator itr = nodes[u].begin(); itr != nodes[u].end();
				itr++) {
			if (dist[*itr] == INT_MAX) {
				last_visited[*itr] = u;
				dist[*itr] = dist[u] + 1;
				q.push(*itr);
			}
		}
	}

	return dist[end];
}

int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);
	while (t--) {

		for (int i = 0; i < 110; i++) {
			last_visited[i] = 0;
			dist[i] = INT_MAX;
			visited[i] = 0;
			nodes[i].clear();
		}

		int start = 0, end = 0;

		for (int i = 1; i <= 100; i++) {
			start = i;
			for (int j = 1; j <= 6; j++) {
				end = start + j;
				if (end <= 100) {
					nodes[start].push_back(end);
				}
			}
		}

		int s, l;
		scanf("%d,%d", &l, &s);

		for (int i = 0; i < l; i++) {
			int u, v;
			scanf("%d,%d", &u, &v);
			nodes[u].push_back(v);
		}

		for (int i = 0; i < s; i++) {
			int u, v;
			scanf("%d,%d", &u, &v);
			nodes[u].push_back(v);
		}

		/*cout << "GRAPH : " << endl;

		 for (int i = 1; i <= 100; i++) {
		 cout << "NODE " << i;
		 for (list<int>::iterator itr = nodes[i].begin();
		 itr != nodes[i].end(); itr++) {
		 cout << " " << *itr;
		 }
		 cout << endl;
		 }*/

		start = 1;
		end = 100;

		cout << bfs(start, end) - 1 << endl;

		/*cout << "Path :" << endl;

		 start = 100;

		 while (1) {

		 cout << start << endl;

		 if( start == 1 )
		 break;

		 start = last_visited[start];

		 }*/

	}
	return 0;
}
