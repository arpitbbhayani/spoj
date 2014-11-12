/*
 * TreeHeight.cpp
 *
 *  Created on: Oct 13, 2014
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
	struct node * left;
	struct node * right;
};

struct node * newnode(int d) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->left = t->right = NULL;
	t->data = d;
	return t;
}

int is_complete(struct node * root) {

	queue<struct node *> q;

	q.push(root);

	while (!q.empty()) {

		struct node * n = q.front();
		q.pop();

		if (n->left == NULL || n->right == NULL) {

			if (n->left == NULL && n->right != NULL) {
				return 0;
			}

			break;
		}

		if (n->left) {
			q.push(n->left);
		}

		if (n->right) {
			q.push(n->right);
		}
	}

	while (!q.empty()) {
		struct node * n = q.front();
		q.pop();

		if (!(n->left == NULL && n->right == NULL)) {
			return 0;
		}
	}

	return 1;

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);

	root->right->left = newnode(5);
	root->right->right = newnode(6);

	cout << is_complete(root) << endl;

	return 0;
}
