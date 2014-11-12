/*
 * Microsoft38.cpp
 *
 *  Created on: Oct 9, 2014
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

int main(int argc, char * argv[]) {

	char str[64];
	FILE * fp = fopen("Microsoft38.txt", "r");

	int tail = 5;

	char array[tail][64];

	for (int i = 0; i < tail; i++) {
		char * ret = fgets(str, sizeof(str), fp);
		if (ret == NULL) {
			break;
		}
		strcpy(array[i], str);
	}

	int start = 0, end = tail - 1;

	//printf("START : %s and END : %s\n", array[start], array[end]);

	while (fgets(str, sizeof(str), fp) != NULL) {
		// vacant the start
		start = (start + 1) % tail;

		// add it to end + 1
		end = (end + 1) % tail;
		strcpy(array[end], str);

		//printf("START : %s and END : %s\n", array[start], array[end]);

	}

	fclose(fp);

	ps(array[start]);

	return 0;
}
