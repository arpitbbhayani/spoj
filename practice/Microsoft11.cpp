/*
 * Microsoft11.cpp
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

void rotate(int ** array, int n, int ** rotated) {

	int col = n - 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			rotated[j][col] = array[i][j];
		}
		col--;
	}

}

int main(int argc, char * argv[]) {

	int n = 4;

	int ** array = (int **) malloc(n * sizeof(int *));
	int ** rotated = (int **) malloc(n * sizeof(int *));

	for (int i = 0; i < n; i++) {
		array[i] = (int *) malloc(n * sizeof(int));
		rotated[i] = (int *) malloc(n * sizeof(int));
	}

	int k = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = k++;
		}
	}

	cout << "\nOriginal" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	rotate(array, n, rotated);

	cout << "\nRotated" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << rotated[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
