/*
 * SplitLL.cpp
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

void splitList(struct node * h, struct node ** h1, struct node ** h2) {

	struct node * p = h;

	*h1 = p;
	p = p->next;
	*h2 = p;
	p = p->next;

	struct node * q = *h1;
	struct node * r = *h2;
	int chance = 0;

	while (p != NULL) {

		if (chance == 0) {
			q->next = p;
			q = q->next;
		} else {
			r->next = p;
			r = r->next;
		}
		p = p->next;
		chance = 1 - chance;
	}

	q->next = NULL;
	r->next = NULL;

}

int main(int argc, char * argv[]) {

	struct node * l = NULL, *l1 = NULL, *l2 = NULL;

	l = newnode(6);
	addToHead(&l, 5);
	addToHead(&l, 4);
	addToHead(&l, 3);
	addToHead(&l, 2);
	addToHead(&l, 1);
	addToHead(&l, 0);

	printList(l);

	splitList(l, &l1, &l2); 	// l -> l1,l2

	printList(l1);
	printList(l2);
	printList(l);

	return 0;
}
