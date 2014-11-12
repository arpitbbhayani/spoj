/*
 * Microsoft111.cpp
 *
 *  Created on: Aug 25, 2014
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
	int val;
	struct node * next;
};

struct node * newnode(int val) {
	struct node * p = (struct node *) malloc(sizeof(struct node));
	p->val = val;
	p->next = NULL;

	return p;
}

void printlist(struct node * p) {

	cout << "LIST : ";
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	cout << endl;

}

void deletekth(struct node * head, int k) {

	int count = 0;

	struct node * p = head;
	struct node * prev = NULL;

	while (p) {

		count++;
		if (count == k) {

			struct node * temp = prev;
			prev->next = p->next;

			free(p);

			p = temp;

			count = 0;
		}

		prev = p;
		p = p->next;

	}

}

int main(int argc, char * argv[]) {

	struct node * head = newnode(1);

	struct node * p = head;

	for (int i = 2; i <= 10; i++) {
		p->next = newnode(i);
		p = p->next;
	}

	printlist(head);
	deletekth(head, 5);
	printlist(head);

	return 0;
}
