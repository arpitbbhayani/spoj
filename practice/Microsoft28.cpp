/*
 * Microsoft28.cpp
 *
 *  Created on: Aug 30, 2014
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
	struct node * next;
	int val;
};

struct node * newnode(int d) {
	struct node * p = (struct node *) malloc(sizeof(struct node));
	p->next = NULL;
	p->val = d;
	return p;
}

void insert(struct node ** head, int d) {
	struct node * p = newnode(d);
	p->next = (*head);
	*head = p;
}

void third(struct node ** list3, struct node * list1, struct node *list2) {

	struct node * p = list1, *q = list2, *r = *list3;

	while (1) {

		if (p == NULL)
			break;

		if (q == NULL) {

			if (r == NULL) {
				(*list3) = newnode(p->val);
				r = *list3;
			} else {
				r->next = newnode(p->val);
				r = r->next;
			}

			p = p->next;

		} else if (q->val > p->val) {

			if (r == NULL) {
				(*list3) = newnode(p->val);
				r = *list3;
			} else {
				r->next = newnode(p->val);
				r = r->next;
			}

			p = p->next;

		} else if (q->val == p->val) {
			p = p->next;
			q = q->next;

		} else if (q->val < p->val) {
			q = q->next;
		}

	}

}

int is_intersect(struct node * list1, struct node * list2) {

	int l1 = 0, l2 = 0;

	struct node * p = list1;
	while (p) {
		l1++;
		p = p->next;
	}

	struct node * q = list2;
	while (q) {
		l2++;
		q = q->next;
	}

	p = list1;
	q = list2;

	if (l1 > l2) {
		for (int i = 0; i < l1 - l2; i++)
			p = p->next;
	} else {
		for (int i = 0; i < l2 - l1; i++)
			q = q->next;
	}

	while ( p && q ) {
		if( p == q ) {
			return 1;
		}
		p = p->next;
		q = q->next;
	}
	return 0;
}

int main(int argc, char * argv[]) {

	struct node * list1 = newnode(9);

	insert(&list1, 8);
	insert(&list1, 7);
	insert(&list1, 6);
	insert(&list1, 5);
	insert(&list1, 4);
	insert(&list1, 3);
	insert(&list1, 2);
	insert(&list1, 1);

	struct node * list2 = newnode(11);
	insert(&list2, 10);
	insert(&list2, 9);
	//	list2->next->next->next = list1->next->next->next->next;

	struct node * p = list1;

	cout << "LIST 1: ";
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	p = list2;
	cout << "LIST 2: ";
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	cout << is_intersect(list1, list2) << endl;

	return 0;
}
