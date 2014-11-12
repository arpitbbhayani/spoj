/*
 * b.cpp
 *
 *  Created on: Sep 29, 2014
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
#include <cmath>

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

#define PI 3.141592653589793238462643383279
#define INF 100000000
#define ASIZE 10

struct line {
	double x1, y1;
	double x2, y2;
	double m;
	double c;
};

struct line2 {
	double m;
	double c;
};

struct line array[ASIZE];

int main(int argc, char * argv[]) {

	int t;
	si(t);
	while (t != 0) {

		for (int i = 0; i < t; i++) {
			cin >> array[i].x1 >> array[i].y1 >> array[i].x2 >> array[i].y2;

			if (array[i].x2 == array[i].x1) {
				array[i].m = INF;
				array[i].c = INF;
			} else {
				array[i].m = ((array[i].y2 - array[i].y1)
						/ (array[i].x2 - array[i].x1));
				array[i].c = (array[i].y2) - array[i].m * array[i].x2;
			}
		}
		struct line2 * temp = NULL;
		queue<struct line2 *> q;

		for (int i = 70; i <= 70; i++) {
			double m1 = tan((i * PI) / 180);

			for (int j = 0; j < t; j++) {

				double m2 = array[j].m;

				double anglei = PI / 2 - atan(abs((m1 - m2) / (1 + m1 * m2)));
				double m31 = (m1 - tan(2 * anglei))
						/ (1 + m1 * tan(2 * anglei));
				double m32 = (m1 - tan(2 * anglei))
						/ (1 - m1 * tan(2 * anglei));

				temp = (struct line2 *) malloc(sizeof(struct line2));

				temp->c = 0;
				temp->m = m31;

				q.push(temp);

				cout << "Angle between : " << i << " degree and index = " << j
						<< " is : " << (angle * 180) / PI << endl;
			}

		}

		si(t);
	}
	return 0;
}
