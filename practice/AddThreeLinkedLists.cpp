/*
 * AddThreeLinkedLists.cpp
 *
 *  Created on: Nov 5, 2014
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
#define trace4(a,b,c,d) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << SEPERATOR << #c << SEPERATOR << c << SEPERATOR << #d << SEPERATOR << d << endl;

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

struct node {
	int data;
	struct node * next;
};

struct node * newnode(int d) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->next = NULL;
	t->data = d;
	return t;
}

void add(struct node * n1, struct node * n2, struct node * n3,
		struct node ** n4) {

	(*n4) = newnode(-1);
	struct node * tail = *n4;

	int carry = 0;
	while (n1 || n2 || n3) {

		int a = 0, b = 0, c = 0;

		if (n1 != NULL) {
			a = n1->data;
			n1 = n1->next;
		}

		if (n2 != NULL) {
			b = n2->data;
			n2 = n2->next;
		}

		if (n3 != NULL) {
			c = n3->data;
			n3 = n3->next;
		}

		trace4(a, b, c, carry);

		int sum = (a + b + c + carry) % 10;
		carry = (a + b + c) / 10;

		trace2(sum, carry);
		tail->next = newnode(sum);
		tail = tail->next;

	}

}

int main(int argc, char * argv[]) {

	struct node * n1 = NULL;
	struct node * n2 = NULL;
	struct node * n3 = NULL;
	struct node * n4 = NULL;

	n1 = newnode(1);
	n1->next = newnode(2);
	n1->next->next = newnode(2);
	n2 = newnode(0);
	n2->next = newnode(0);
	n3 = newnode(0);
	n3->next = newnode(0);

	add(n1, n2, n3, &n4);

	struct node * p = n4;
	p = p->next;

	while (p) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;

	return 0;
}
