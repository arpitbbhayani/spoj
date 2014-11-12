/*
 * b.cpp
 *
 *  Created on: Oct 31, 2014
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
char str[1010];
char max_num[1010];
int max_len = 0;

void compar(char * b, int n) {

	char str1[1010];
	int i = 0;
	for (; i < n; i++) {
		if (b[i] != '0') {
			break;
		}
	}

	int len1 = 0;
	for (; i < n; i++) {
		if (b[i] >= 'A' && b[i] <= 'Z') {
			str1[len1++] = '9';
		} else {
			str1[len1++] = b[i];
		}
	}
	str1[len1] = '\0';

	//cout << "Comparing:" << max_num << " and " << str1 << endl;

	if (max_len == 0) {
		strcpy(max_num, str1);
		max_len = len1;
		//cout << "MAX : " << max_num << endl;
		return;
	}

	if (len1 < max_len) {
		// do nothing
	} else if (len1 > max_len) {
		strcpy(max_num, str1);
		max_len = len1;
	} else {

		int i = 0;
		while (str1[i] != '\0') {
			if (str1[i] != max_num[i]) {
				break;
			}
			i++;
		}

		if (str1[i] != '\0') {
			if (str1[i] > max_num[i]) {
				strcpy(max_num, str1);
				max_len = len1;
			}
		}
	}

	//cout << "MAX : " << max_num << endl;
}

int main(int argc, char * argv[]) {

	ss(str);

	int f = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {

			f = 1;

			int j = i, k = i;
			while (1) {
				if (j == 0) {
					break;
				}

				if (str[j - 1] >= '0' && str[j - 1] <= '9') {
					j--;
				} else {
					break;
				}
			}

			while (1) {
				if (str[k] == '\0') {
					break;
				}

				if (str[k + 1] >= '0' && str[k + 1] <= '9') {
					k++;
				} else {
					break;
				}
			}

			compar(&str[j], k - j + 1);
		}
	}

	if (f == 0) {
		int z = 0;
		for (z = 0; str[z] != '\0'; z++) {
			if (str[z] != '0')
				break;
		}

		if (str[z] == '\0') {
			cout << "0\n";
		} else {
			printf("%s\n", &str[z]);
		}

	} else {
		printf("%s\n", max_num);
	}

	return 0;
}
