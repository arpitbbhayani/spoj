/*
 * SegregateEOLL.cpp
 *
 *  Created on: Jul 18, 2014
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

struct node {
	int data;
	struct node * next;
};

struct node * newnode(int val) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->data = val;
	t->next = NULL;
	return t;
}

void addToHead(struct node ** head, int val) {
	struct node * n = newnode(val);
	n->next = (*head);
	*head = n;
}

void printList(struct node * head) {
	struct node * p = head;

	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void segregateEO(struct node ** h) {

	struct node * p = *h;

	int gotEven = 0, gotOdd = 0;

	struct node * evenFirst = NULL;
	struct node * oddFirst = NULL;
	struct node * evenLast = NULL;
	struct node * oddLast = NULL;

	while (gotEven == 0 || gotOdd == 0) {

		if (p->data % 2 == 0) {
			gotEven = 1;

			if (evenFirst == NULL) {
				evenLast = p;
				evenFirst = p;
			} else {
				evenLast->next = p;
				evenLast = evenLast->next;
			}

		} else {
			gotOdd = 1;

			if (oddFirst == NULL) {
				oddLast = p;
				oddFirst = p;
			} else {
				oddLast->next = p;
				oddLast = oddLast->next;
			}
		}

		p = p->next;
	}

	while (p) {
		if (p->data % 2 == 0) {
			evenLast->next = p;
			evenLast = evenLast->next;
		} else {
			oddLast->next = p;
			oddLast = oddLast->next;
		}
		p = p->next;

	}

	evenLast->next = NULL;
	oddLast->next = NULL;

	evenLast->next = oddFirst;

	*h = evenFirst;

}

int main(int argc, char * argv[]) {

	struct node *l = NULL;

	l = newnode(6);
	addToHead(&l, 7);
	addToHead(&l, 1);
	addToHead(&l, 4);
	addToHead(&l, 5);
	addToHead(&l, 10);
	addToHead(&l, 12);
	addToHead(&l, 8);
	addToHead(&l, 15);
	addToHead(&l, 17);

	printList(l);

	segregateEO(&l); 	// l3 -> l1 intersect l2

	printList(l);

	return 0;
}

