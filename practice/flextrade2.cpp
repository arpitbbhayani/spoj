/*
 * flextrade2.cpp
 *
 *  Created on: May 26, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

struct node {
	int data;
	struct node * next;
};

struct node * get_new_node(int val) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->next = NULL;
	t->data = val;
	return t;
}

void reverse_list(struct node ** l) {
	struct node *p, *q, *r;

	p = *l;
	q = p->next;

	for (;;) {
		r = q->next;

		if (r == NULL) {
			q->next = p;
			break;
		}

		q->next = p;
		p = q;
		q = r;

	}

	(*l)->next = NULL;
	*l = q;

}

int main(int argc, char * argv[]) {

	struct node *l, *li;

	l = get_new_node(1);
	li = l;

	for (int i = 2; i <= 10; i++) {
		l->next = get_new_node(i);
		l = l->next;
	}

	struct node *p = li;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	reverse_list(&li);

	p = li;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}
