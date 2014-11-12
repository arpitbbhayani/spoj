/*
 * Microsoft17.cpp
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
	struct node * arbitrary;
};

struct node * newnode(int val) {
	struct node * p = (struct node *) malloc(sizeof(struct node));
	p->val = val;
	p->next = NULL;
	p->arbitrary = NULL;

	return p;
}

void copylist(struct node ** head, struct node **headnew) {

	struct node * p = *head, *q;

	while (p) {

		struct node *pn = newnode(100 + p->val);

		pn->next = p->next;
		p->next = pn;

		p = p->next->next;
	}

	p = *head;

	while (p) {

		p->next->arbitrary = p->arbitrary->next;
		p = p->next->next;

	}

	*headnew = (*head)->next;

	p = *head;
	q = *headnew;

	while (p) {

		if (p->next == NULL || q->next == NULL) {
			p->next = q->next = NULL;
			break;
		}

		p->next = p->next->next;
		q->next = q->next->next;

		p = p->next;
		q = q->next;
	}

}

int main(int argc, char * argv[]) {

	struct node * head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = newnode(6);

	head->arbitrary = head->next->next->next->next;
	head->next->arbitrary = head;
	head->next->next->arbitrary = head->next->next;
	head->next->next->next->arbitrary = head->next;
	head->next->next->next->next->arbitrary = head->next->next->next;
	head->next->next->next->next->next->arbitrary = head->next->next;

	struct node * headnew = NULL;

	copylist(&head, &headnew);

	struct node * p = head;

	while (p) {
		cout << p->val << " - " << p->arbitrary->val << endl;
		p = p->next;
	}
	cout << endl;

	p = headnew;

	while (p) {
		cout << p->val << " - " << p->arbitrary->val << endl;
		p = p->next;
	}
	cout << endl;

	return 0;
}
