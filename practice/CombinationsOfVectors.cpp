/*
 * CombinationsOfVectors.cpp
 *
 *  Created on: Oct 25, 2014
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

vector<vector<string> > sets;
vector<string> result;

void _print_comb(int index) {

	if (index == sets.size()) {
		for (int j = 0; j < result.size(); j++) {
			cout << result[j] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < sets[index].size(); i++) {
		result.push_back(sets[index][i]);
		_print_comb(index + 1);
		result.pop_back();
	}

}

void print_combinations() {
	_print_comb(0);
}

int main(int argc, char * argv[]) {

	vector<string> v1, v2, v3;
	v1.push_back("1");
	v1.push_back("2");

	v2.push_back("3");
	v2.push_back("4");

	v3.push_back("5");
	v3.push_back("6");

	sets.push_back(v1);
	sets.push_back(v2);
	sets.push_back(v3);

	print_combinations();

	return 0;
}
