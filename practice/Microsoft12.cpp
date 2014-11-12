/*
 * Microsoft12.cpp
 *
 *  Created on: Aug 17, 2014
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
	int data;
	struct node * next;
};

struct node * newnode(int val) {

	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->next = NULL;
	t->data = val;

	return t;
}

void insert_at_head(struct node ** h, int val) {
	struct node * t = newnode(val);
	t->next = (*h);
	(*h) = t;
}

void traverse(struct node * p) {

	cout << "LIST : ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}

void sort_012(struct node * head) {

	int count[3] = { 0 };
	struct node * p = head;

	while (p) {
		count[p->data]++;
		p = p->next;
	}

	p = head;

	int index = 0;

	while (p) {

		p->data = index;
		count[index]--;

		if (count[index] == 0)
			index++;

		p = p->next;
	}

}

int main(int argc, char * argv[]) {

	struct node * head = NULL;

	head = newnode(1);
	insert_at_head(&head, 0);
	insert_at_head(&head, 2);
	insert_at_head(&head, 0);
	insert_at_head(&head, 2);
	insert_at_head(&head, 1);
	insert_at_head(&head, 0);
	insert_at_head(&head, 1);
	insert_at_head(&head, 1);
	insert_at_head(&head, 2);

	traverse(head);

	sort_012(head);

	traverse(head);

	return 0;
}
