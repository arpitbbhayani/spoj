/*
 * SGARDEN.cpp
 *
 *  Created on: Jul 9, 2014
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

using namespace std;

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define MOD 1000000007

#define DEBUG 0
#define gc getchar
#define ll long long

void scanint(int &x) {
	register int c = gc();
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

#define ASIZE 100003

vector<int> p;

int temp[ASIZE];

void primes() {
	temp[1] = 1;

	for (int i = 2; i < 500; i++) {

		if (temp[i] == 1)
			continue;

		if (temp[i] == 0) {
			p.push_back(i);

			for (int j = 1;; j++) {
				if (i * j >= 500)
					break;
				temp[i * j] = 1;
			}
		}
	}

}

map<int, int> final_map;

int array[ASIZE];

void getPrimeFactors(int n, map<int, int> &a) {

	for (int i = 0; i < p.size(); i++) {
		if (n % p[i] == 0) {
			a[p[i]]++;
			n /= p[i];

			i--;

			if (n == 1)
				break;

		}

		if (n == 1)
			break;
	}

}


ll int power2( int a , int b ) {

	ll int result = (ll) a;

	stack<int> s;

	while (b) {
		s.push(b%2);
		b = b >> 1;
	}

	s.pop();

	while( !s.empty() ) {

		result = (result * result) % MOD;

		if ( s.top() == 1 )
			result = (result * a) % MOD;

		s.pop();
	}

	return result;
}


int main(int argc, char * argv[]) {

	primes();

	map<int, int> pf;
	int t;
	si(t);

	while (t--) {

		set<int> s;

		final_map.clear();

		int n;
		si(n);

		for (int i = 1; i <= n; i++) {
			scanint(array[i]);
		}

		for (int i = 1; i <= n; i++) {
			int cycle = 0;
			int location = i;

			while (1) {
				cycle++;
				location = array[location];
				if (location == i)
					break;
			}

			s.insert(cycle);

		}

#if DEBUG
		cout << "LCM OF ";
		for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
			cout << *itr << " ";
		}
		cout << endl;
#endif

		for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {

			pf.clear();

			getPrimeFactors(*itr, pf);

			for (map<int, int>::iterator itr = pf.begin(); itr != pf.end();
					itr++) {
				if (final_map.find(itr->first) != final_map.end()) {
					if (final_map[itr->first] < itr->second) {
						final_map[itr->first] = itr->second;
					}
				} else {
					final_map[itr->first] = itr->second;
				}
			}
		}

		ll int result = 1;

		for (map<int, int>::iterator itr = final_map.begin();
				itr != final_map.end(); itr++) {
			result = (result * power2(itr->first , itr->second)) % MOD;
		}

		printf("%lld\n", result);

	}
	return 0;
}
