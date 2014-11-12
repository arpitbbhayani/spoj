/*
 * Google21.cpp
 *
 *  Created on: Aug 17, 2014
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

int board[8][8];
int xmove[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };
int ymove[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };

int is_safe(int x, int y) {

	if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1)
		return 1;

	return 0;
}

bool _solve_kt(int x, int y, int count) {

	if (count == 60) {
		return true;
	}

	int nextx = 0, nexty = 0;

	for (int k = 0; k < 8; k++) {

		nextx = xmove[k] + x;
		nexty = ymove[k] + y;

		if (is_safe(nextx, nexty) == true) {
			board[nextx][nexty] = count;

			if (_solve_kt(nextx, nexty, count + 1) == true) {
				return true;
			} else {
				board[nextx][nexty] = -1;
			}
		}
	}

	return false;
}

void solve_kt(int x, int y) {

	if (_solve_kt(x, y, 1) == true) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				cout << board[i][j] << " ";
			cout << endl;
		}

	} else {
		cout << "No Solution" << endl;
	}

}

int main(int argc, char * argv[]) {

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = -1;

	int x = 3, y = 2;

	board[x][y] = 0;

	solve_kt(x, y);

	return 0;
}
