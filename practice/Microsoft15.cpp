/*
 * Microsoft15.cpp
 *
 *  Created on: Aug 18, 2014
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
	struct node * left;
	struct node * right;
	struct node * parent;
};

struct node * newnode(int data) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->data = data;
	t->left = t->right = t->parent = NULL;
	return t;
}

void inorder(struct node * root) {

	if (root == NULL)
		return;

	inorder(root->left);
	pi(root->data);
	inorder(root->right);

}

int inorder_successor(struct node * p) {

	if (p->right) {

		struct node * q = p->right;
		while (q->left)
			q = q->left;

		return q->data;

	} else {

		struct node * q = p->parent;

		while (q != NULL && q->parent != NULL) {

			if (q->parent->left == q)
				return q->parent->data;

			q = q->parent;

		}

	}

	return -1;

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(1);

	root->parent = NULL;

	root->left = newnode(2);
	root->right = newnode(3);

	root->left->parent = root;
	root->right->parent = root;

	root->left->left = newnode(7);
	root->left->right = newnode(6);

	root->left->left->parent = root->left;
	root->left->right->parent = root->left;

	root->right->left = newnode(5);
	root->right->right = newnode(4);

	root->right->left->parent = root->right;
	root->right->right->parent = root->right;

	root->right->right->left = newnode(3);
	root->right->right->right = newnode(10);

	root->right->right->left->parent = root->right->right;
	root->right->right->left->parent = root->right->right;

	cout << inorder_successor(root->left->right) << endl;

	return 0;
}
