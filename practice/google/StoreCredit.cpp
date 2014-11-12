/*
 * StoreCredit.cpp
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

#define ASIZE 2010

list<int> indexof[1010];
int hash[1010];
int values[ASIZE];

int main(int argc, char * argv[]) {

	int t, Z = 1;
	scanf("%d", &t);
	while (t--) {

		memset(hash, 0, sizeof(hash));
		for (int i = 0; i < 1010; i++) {
			indexof[i].clear();
		}

		int c, k, x;

		si(c);
		si(k);

		for (int i = 0; i < k; i++) {
			si(x);
			hash[x] = 1;
			values[i] = x;
			indexof[x].push_back(i + 1);
		}

		int val1, val2;
		int i = 0;
		for (i = 0; i < k; i++) {

			val1 = values[i];
			val2 = c - val1;

			if (hash[val1] != 0 && val2 >= 0 && hash[val2] != 0) {
				break;
			}
		}

		int index1, index2;

		list<int>::iterator itr;
		itr = indexof[val1].begin();
		index1 = *(itr);
		indexof[val1].remove(index1);

		if (indexof[val2].size() == 0) {
			index2 = index1;
		} else {
			itr = indexof[val2].begin();
			index2 = *(itr);
		}

		//trace2(val1, val2);
		//trace2(index1, index2);

		if (values[index1 - 1] + values[index2 - 1] == c) {
			cout << "CORRENT " << endl;
		} else {
			cout << "INCORRENT " << endl;
		}

		if (index1 < index2) {
			cout << "Case #" << Z++ << ": " << index1 << " " << index2 << endl;
		} else {
			cout << "Case #" << Z++ << ": " << index2 << " " << index1 << endl;
		}

	}
	return 0;
}
