/*
 * StringSmallestWindow.cpp
 *
 *  Created on: Nov 2, 2014
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

int window(char * str1, char * str2) {

	int count[256] = { 0 }, num = 0;
	for (int i = 0; str2[i]; i++) {
		count[str2[i]]++;
		num++;
	}

	int i = 0, j = 0;

	int min_len = INT_MAX;

	while (str1[i] != '\0' && count[str1[i]] == 0)
		i++;
	j = i;

	if (str1[j] == '\0') {
		return INT_MAX;
	}

	int temp[256] = { 0 };
	for (int k = 0; k < 256; k++) {
		temp[k] = count[k];
	}

	while (num > 0) {
		cout << "CHAR : " << str1[j] << " and its count = " << temp[str1[j]];
		if (temp[str1[j]] <= 0) {
			temp[str1[j]]--;
			cout << " not counting" << endl;
		} else {
			temp[str1[j]]--;
			num--;
			cout << " counting" << endl;
		}
		j++;

		if (str1[j] == '\0') {
			break;
		}
	}

	cout << "String found : ";
	for (int z = i; z < j; z++) {
		printf("%c", str1[z]);
	}
	printf("\n");

	if (num == 0) {
		min_len = min(min_len, j - i + 1);
	}

	while (1) {

		char toberemoved = str1[i];

		cout << "TO BE REMOVED : " << str1[i] << endl;

		i++;
		while (str1[i] != '\0' && count[str1[i]] == 0) {
			i++;
		}

		cout << "NEW i = " << i << " char = " << str1[i] << endl;

		while (str1[j] != '\0' && str1[j] != toberemoved) {
			j++;
		}

		cout << "NEW j = " << j << " char = " << str1[j] << endl;

		if (str1[i] == '\0' || str1[j] == '\0') {
			break;
		}

		cout << "String found : ";
		for (int z = i; z < j; z++) {
			printf("%c", str1[z]);
		}
		printf("\n");

		min_len = min(min_len, j - i + 1);
	}

	return min_len;
}

int main(int argc, char * argv[]) {

	char str1[100], str2[100];

	ss(str1);
	cout << "STRING 1 : " << str1 << endl;
	ss(str2);
	cout << "STRING 2 : " << str2 << endl;

	cout << window(str1, str2) << endl;

	return 0;
}

