/*
 * f.cpp
 *
 *  Created on: Sep 29, 2014
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
int array123[1024];
int index = 0;
int hash123[11] = { 0 };

set<set<int> > s[22];

void fun(int n, int VALUE) {

	if (n < 0)
		return;

	set<int> temp;

	if (n == 0) {
		for (int i = 0; i < index; i++) {
			//printf("%d ", array[i]);
			temp.insert(array123[i]);
		}
		//printf("\n");
		s[VALUE].insert(temp);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (hash123[i] == 0) {
			hash123[i] = 1;
			array123[index++] = i;

			fun(n - i, VALUE);

			index--;
			hash123[i] = 0;
		}
	}

}

int hash[25];
int temp_array[25];
int global_count = -1;

int fun2(int hash_size, int n, int ii) {

	if (ii >= n) {

		int local_count = 0;
		for (int i = 0; i < 25; i++) {
			if (hash[i] == 1) {
				local_count++;
			}
		}

		if (local_count > global_count) {
			global_count = local_count;
		}

		return -1;
	}

	cout << "NUMBER : " << temp_array[ii] << endl;

	for (set<set<int> >::iterator itr = s[temp_array[ii]].begin();
			itr != s[temp_array[ii]].end(); itr++) {

		set<int> I = *itr;

		int temp_hash[25];

		for (int i = 0; i < 25; i++) {
			temp_hash[i] = hash[i];
		}

		cout << "For combination : ";
		for (set<int>::iterator itr2 = I.begin(); itr2 != I.end(); itr2++) {
			cout << *itr2 << " ";
		}
		cout << endl;

		for (set<int>::iterator itr2 = I.begin(); itr2 != I.end(); itr2++) {

			cout << "For number " << *itr2 << endl;

			if (*itr2 > hash_size) {
				return 0;
			}

			if (hash[*itr2] == 1) {

				cout << "hash value of " << *itr2 << " is already 1" << endl;

				int local_count = 0;
				for (int i = 0; i < 25; i++) {
					if (hash[i] == 1) {
						local_count++;
					}
				}

				if (local_count > global_count) {
					global_count = local_count;
				}

				return 0;

			} else {
				/*cout << "hash value of " << *itr2 << " is 0" << endl;*/
				temp_hash[*itr2] = 1;
			}
		}

		for (int i = 0; i < 25; i++) {
			hash[i] = temp_hash[i];
		}

		fun2(hash_size, n, ii + 1);

	}

	return 0;
}

int main(int argc, char * argv[]) {

	for (int i = 0; i < 22; i++) {
		fun(i, i);
	}

	/*for (int i = 0; i < 22; i++) {
	 for (set<set<int> >::iterator itr = s[i].begin(); itr != s[i].end();
	 itr++) {
	 set<int> i = *itr;
	 for (set<int>::iterator itr2 = i.begin(); itr2 != i.end(); itr2++) {
	 cout << *itr2 << " ";
	 }
	 cout << endl;
	 }
	 }*/

	int Z = 1;
	int a, b;
	si(a);
	si(b);
	while (1) {

		if (a == 0 && b == 0)
			break;

		for (int i = 0; i < b; i++) {
			si(temp_array[i]);
		}

		global_count = -1;
		for (int i = 0; i < 25; i++)
			hash[i] = 0;

		fun2(a, b, 0);
		cout << "Game " << Z++ << ": " << global_count << endl;

		si(a);
		si(b);
	}
	return 0;
}
