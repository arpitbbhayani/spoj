/*
 * samsung13.cpp
 *
 *  Created on: Oct 22, 2014
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

int get1d(int x, int y, int row, int col) {
	return (x * col) + y;
}

int issafe(int x, int y, int row, int col) {
	if (x >= 0 && x < row && y >= 0 && y < col)
		return 1;
	return 0;
}

int visited[1000] = { 0 };
int dist[1000] = { 0 };

int main(int argc, char * argv[]) {

	int row, col;
	si(row);
	si(col);

	int array[row][col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			si(array[i][j]);
		}
	}

	list<int> nodes[row * col];

	int neighborx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int neighbory[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (array[i][j] == 0) {

				for (int k = 0; k < 8; k++) {
					int nx = i + neighborx[k];
					int ny = j + neighbory[k];
					if (issafe(nx, ny, row, col) && array[nx][ny] == 0) {
						nodes[get1d(i, j, row, col)].push_back(
								get1d(nx, ny, row, col));
					}
				}
			}
		}
	}

	cout << "GRAPH" << endl;

	for (int i = 0; i < row * col; i++) {
		cout << "NODE " << i << ": ";
		for (list<int>::iterator itr = nodes[i].begin(); itr != nodes[i].end();
				itr++) {
			cout << *itr << " ";
		}
		cout << endl;
	}

	int start = get1d(0, 0, row, col);
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		for (list<int>::iterator itr = nodes[x].begin(); itr != nodes[x].end();
				itr++) {

			if (visited[*itr] == 1) {
				continue;
			}
			visited[*itr] = 1;
			dist[*itr] = dist[x] + 1;
			q.push(*itr);
		}
	}

	cout << dist[get1d(row - 1, col - 1, row, col)] << endl;

	return 0;
}
