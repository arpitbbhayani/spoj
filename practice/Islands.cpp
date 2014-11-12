/*
 * Islands.cpp
 *
 *  Created on: Oct 16, 2014
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

int array[ASIZE][ASIZE];
int visited[ASIZE][ASIZE];
int row = 0, col = 0;

int neighborx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int neighbory[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int is_valid(int x, int y) {

	if (x < row && y < col && x >= 0 && y >= 0 && array[x][y] == 1) {
		return 1;
	}
	return 0;

}

void dfs(int x, int y) {

	for (int i = 0; i < 8; i++) {
		int newx = x + neighborx[i];
		int newy = y + neighbory[i];

		if (is_valid(newx, newy) && visited[newx][newy] == 0) {
			visited[newx][newy] = 1;
			dfs(newx, newy);
		}
	}

}

int islands() {

	memset(visited, 0, sizeof(visited));

	int count = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == 0 && array[i][j] == 1) {
				visited[i][j] = 1;
				dfs(i, j);
				count++;
			}
		}
	}

	return count;
}

int main(int argc, char * argv[]) {

	si(row);
	si(col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			si(array[i][j]);
		}
	}

	printf("%d\n", islands());

	return 0;
}

