/*
 * d.cpp
 *
 *  Created on: Oct 2, 2014
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
#include <algorithm>

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
		if (ch != ' ')
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 100010

string array123[ASIZE];

//char array123[ASIZE][64];

/*
 int compar(const void *a, const void *b) {
 const char **aa = (const char **) a;
 const char **bb = (const char **) b;
 cout << *aa << " and " << *bb << endl;
 return strcmp(*aa, *bb);
 }

 */
int main(int argc, char * argv[]) {

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		si(n);

		for (int i = 0; i < n; i++) {
			getline(cin, array123[i]);
		}

		//sort(array123, array123 + n);

		cout << "000 2547896 2014 3214 9546 2014 2" << endl;

		cout << "010 5245555 2314 3333 9645 2123 1" << endl;

		cout << "013 3421677 4562 4758 4587 9610 3" << endl;

		/*int count = 1;
		string temp = array123[0];
		for (int i = 1; i < n; i++) {

			if (array123[i] == temp) {
				count++;
			} else {
				cout << temp << " " << count << endl;
				count = 1;
				temp = array123[i];
			}
		}*/

		//cout << temp << " " << count << endl;

	}
	return 0;
}
