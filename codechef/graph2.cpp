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

struct subset {

	int parent, rank;
};

vector<subset> info;

struct node {
	int vertex1, vertex2, distance;
};

struct cordinate {
	int x, y;
};

bool myComparator(node first, node second) {

	return first.distance < second.distance;
}

int Find(int x) {

	if (x == info[x].parent)
		return x;

	return (info[x].parent = Find(info[x].parent));

}

void Union(int a, int b) {
	int a_parent = Find(a);
	int b_parent = Find(b);

	if (a_parent == b_parent)
		return;

	if (info[a_parent].rank < info[b_parent].rank) {
		info[a_parent].parent = b_parent;
	} else if (info[a_parent].rank == info[b_parent].rank) {
		info[a_parent].rank += 1;
		info[b_parent].parent = a_parent;

	} else
		info[b_parent].parent = a_parent;

	return;
}

void krushkal(vector<node> &graph, int R) {

	int k = 1, i = 0, a, b;
	int cost = 0;

	while (k < 101) {
		a = graph[i].vertex1;
		b = graph[i].vertex2;

		if (Find(a) != Find(b)) {
			Union(a, b);
			cost += graph[i].distance;
			k++;
		}

		i++;
	}

	printf("%d\n", cost);

}

int main(int argc, char * argv[]) {

	vector<node> graph;
	vector<node>::iterator it;

	int t;
	scanf("%d", &t);
	while (t--) {

		info.clear();
		graph.clear();

		int index = 0;
		int start = 0, end = 0;

		for (int i = 0; i <= 100; i++) {
			info[i].parent = i;
			info[i].rank = 0;
		}

		for (int i = 0; i <= 100; i++) {
			start = i;
			for (int j = 1; j <= 6; j++) {
				end = start + j;
				if (end <= 100) {
					graph[index].vertex1 = start;
					graph[index].vertex2 = end;
					graph[index].distance = abs(start - end);
					index++;
				}
			}
		}

		int s, l;
		scanf("%d,%d", &l, &s);

		for (int i = 0; i < l; i++) {
			int u, v;
			scanf("%d,%d", &u, &v);

			graph[index].vertex1 = u;
			graph[index].vertex2 = v;
			graph[index].distance = abs((u - v) / 2);
			index++;

		}

		for (int i = 0; i < s; i++) {
			int u, v;
			scanf("%d,%d", &u, &v);
			graph[index].vertex1 = u;
			graph[index].vertex2 = v;
			graph[index].distance = abs((u + v) / 2);
			index++;
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

		sort(graph.begin(), graph.end(), myComparator);

		//krushkal algorithm
		krushkal(graph, index);

	}
	return 0;
}
