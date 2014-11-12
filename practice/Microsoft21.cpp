/*
 * Microsoft21.cpp
 *
 *  Created on: Aug 29, 2014
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

void traverse(struct node * p) {

	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

}

void listsort(struct node * head) {

	int count[3] = { 0 };

	struct node * p = head;

	while (p) {
		count[p->val]++;
		p = p->next;
	}

	p = head;
	int index = 0;

	while (p) {

		if (count[index] == 0) {
			index++;
		} else {
			p->val = index;
			count[index]--;
			p = p->next;
		}
	}

}

int main(int argc, char * argv[]) {

	struct node * head = newnode(0);

	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);
	insert(&head, 0);

	traverse(head);
	listsort(head);
	traverse(head);

	return 0;
}
