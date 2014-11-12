/*
 * Microsoft31.cpp
 *
 *  Created on: Sep 28, 2014
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

struct node * newnode(int d) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->data = d;
	t->next = NULL;
	return t;
}

int is_palin_stack(struct node * head) {

	stack<int> s;

	struct node * start1, *start2;
	struct node * p = head, *q = head->next;

	while (p && q && q->next) {

		s.push(p->data);

		p = p->next;
		q = q->next->next;
	}

	if (q != NULL)
		s.push(p->data);

	start1 = head;
	start2 = p->next;

	while (start2 != NULL) {

		if (s.top() != start2->data) {
			break;
		}
		s.pop();
		start2 = start2->next;
	}

	if (s.empty()) {
		return 1;
	} else {
		return 0;
	}

}

void list_reverse(struct node ** head) {

	struct node * prev, *current, *next = NULL;

	prev = NULL;
	current = *head;
	next = current->next;

	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}

int is_palin_rev(struct node * head) {

	struct node * p = head, *q = p->next;

	while (p && q && q->next) {
		p = p->next;
		q = q->next->next;
	}

	struct node * mid = p->next;

	cout << "Middle : " << mid->data << endl;

	list_reverse(&mid);

	p = head;
	q = mid;

	cout << "P : ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	cout << "Q : ";
	while (q) {
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;

	p = head;
	q = mid;

	int is_palin = 1;

	while (q) {
		if (p->data != q->data) {
			is_palin = 0;
			break;
		}

		p = p->next;
		q = q->next;
	}

	return is_palin;
}

int main(int argc, char * argv[]) {

	struct node * head1 = newnode(1);
	head1->next = newnode(2);
	head1->next->next = newnode(3);
	head1->next->next->next = newnode(4);

	struct node * head2 = newnode(1);
	head2->next = newnode(2);
	head2->next->next = newnode(3);
	head2->next->next->next = newnode(4);
	head2->next->next->next->next = newnode(5);

	struct node * head3 = newnode(1);
	head3->next = newnode(2);
	head3->next->next = newnode(2);
	head3->next->next->next = newnode(1);

	struct node * head4 = newnode(1);
	head4->next = newnode(2);
	head4->next->next = newnode(3);
	head4->next->next->next = newnode(2);
	head4->next->next->next->next = newnode(1);

	cout << "Using stack" << endl;
	cout << "PALIN : " << is_palin_stack(head1) << endl;
	cout << "PALIN : " << is_palin_stack(head2) << endl;
	cout << "PALIN : " << is_palin_stack(head3) << endl;
	cout << "PALIN : " << is_palin_stack(head4) << endl;

	cout << "Using list reversal" << endl;
	cout << "PALIN : " << is_palin_rev(head1) << endl;
	cout << "PALIN : " << is_palin_rev(head2) << endl;
	cout << "PALIN : " << is_palin_rev(head3) << endl;
	cout << "PALIN : " << is_palin_rev(head4) << endl;

	return 0;
}
