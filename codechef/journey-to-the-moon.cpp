/*
 * journey-to-the-moon.cpp
 *
 *  Created on: Oct 10, 2014
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

int visited[100010];
list<int> nodes[100010];
ll int count123[100000];
int index123 = 0;

int main(int argc, char * argv[]) {

	int n, m;

	si(n);
	si(m);

	for (int i = 0; i < m; i++) {
		int a, b;
		si(a);
		si(b);

		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	/*for (int i = 0; i < n; i++) {
		cout << "Child of " << i << " : ";1
		for (list<int>::iterator itr = nodes[i].begin(); itr != nodes[i].end();
				itr++) {
			cout << *itr << " ";
		}
		cout << endl;
	}*/

	ll int result = 0;
	ll int sum = 0;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 1) {
			continue;
		}

		stack<int> s;
		s.push(i);

		int temp = 1;
		visited[i] = 1;

		while (!s.empty()) {

			int x = s.top();

			s.pop();

			for (list<int>::iterator itr = nodes[x].begin();
					itr != nodes[x].end(); itr++) {

				if (visited[*itr] == 0) {
					temp++;
					s.push(*itr);
					visited[*itr] = 1;
				}
			}
		}

		result += sum * (ll int)temp;
		sum += temp;

	}

	/*ll int result = 0;
	for (int i = 0; i < index123; i++) {
		for (int j = i + 1; j < index123; j++) {
			result += (count123[i] * count123[j]);
		}
	}*/

	pll(result);

	return 0;
}
