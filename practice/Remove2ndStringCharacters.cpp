/*
 * Remove2ndStringCharacters.cpp
 *
 *  Created on: Jul 25, 2014
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

void mask(char * first, char * second) {

	int count[26];

	for (int i = 0; i < 26; i++)
		count[i] = 0;

	for (int i = 0; second[i] != '\0'; i++) {
		count[second[i] - 'a'] = 1;
	}

	int index = 0;
	for (int i = 0; first[i] != '\0'; i++) {

		if (first[i] >= 'a' && first[i] <= 'z' && count[first[i] - 'a'] == 1) {
		} else {
			first[index++] = first[i];
		}
	}

	first[index] = '\0';

}

int main(int argc, char * argv[]) {

	char first[100] = "test strsinmgaaa";
	char second[100] = "mask";

	cout << "First : " << first << endl;
	mask(first, second);
	cout << "First : " << first << endl;

	return 0;
}
