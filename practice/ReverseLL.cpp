/*
 * ReverseLL.cpp
 *
 *  Created on: Oct 1, 2014
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

void reverse(struct node ** head) {

	struct node * prev = NULL;
	struct node * current = *head;
	struct node * next = (*head)->next;

	while ( current ) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}

int main(int argc, char * argv[]) {

	struct node * head = newnode(1);
	head->next = newnode(2);
	head->next->next = newnode(3);
	head->next->next->next = newnode(4);
	head->next->next->next->next = newnode(5);
	head->next->next->next->next->next = newnode(6);
	head->next->next->next->next->next->next = newnode(7);

	struct node * p = head;

	cout << "LIST : ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	reverse(&head);

	p = head;

	cout << "LIST : ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}
