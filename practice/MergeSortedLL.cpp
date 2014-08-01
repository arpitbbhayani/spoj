/*
 * MergeSortedLL.cpp
 *
 *  Created on: Jul 17, 2014
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

void sortedMerge(struct node ** h1, struct node ** h2) {

	struct node *p = *h1;
	struct node *q = *h2;

	if (q->data <= p->data) {
		// Add q to list 1 and make it HEAD
		*h1 = q;
		q = q->next;
	} else {
		p = p->next;
	}

	struct node * last = *h1;

	while (p && q) {

		if (p->data <= q->data) {
			last->next = p;
			p = p->next;
			last = last->next;
		} else {
			last->next = q;
			q = q->next;
			last = last->next;
		}
	}

	if (p == NULL) {
		last->next = q;
	}

	if (q == NULL) {
		last->next = p;
	}

}

int main(int argc, char * argv[]) {

	struct node * l1 = NULL, *l2 = NULL;

	l1 = newnode(15);
	addToHead(&l1, 10);
	addToHead(&l1, 5);

	l2 = newnode(9);
	addToHead(&l2, 6);
	addToHead(&l2, 3);

	printList(l1);
	printList(l2);

	sortedMerge(&l1, &l2); 	// l1 = l1 + l2;

	printList(l1);

	return 0;
}
