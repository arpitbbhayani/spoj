/*
 * Microsoft24.cpp
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
	struct node * left, *right, *parent;
	int val;
};

struct node * newnode(int d) {

	struct node * p = (struct node *) malloc(sizeof(struct node));
	p->left = p->right = p->parent = NULL;
	p->val = d;
	return p;

}

struct node * inorder_successor(struct node * root) {

	struct node * p = root;

	if (p->right) {

		p = p->right;

		while (p->left) {
			p = p->left;
		}

		return p;
	} else {


		while (p != NULL && p->parent != NULL) {

			if (p == p->parent->left)
				return p->parent;

			p = p->parent;
		}

	}

	return newnode(-1);
}

int main(int argc, char * argv[]) {

	struct node * root = newnode(20);

	root->parent = NULL;

	root->left = newnode(15);
	root->left->parent = root;

	root->right = newnode(25);
	root->right->parent = root;

	root->left->left = newnode(10);
	root->left->left->parent = root->left;

	root->left->right = newnode(17);
	root->left->right->parent = root->left;

	root->right->left = newnode(22);
	root->right->left->parent = root->right;

	root->right->right = newnode(27);
	root->right->right->parent = root->right;

	root->right->left->left = newnode(21);
	root->right->left->left->parent = root->right->left;

	root->right->left->right = newnode(23);
	root->right->left->right->parent = root->right->left;

	cout << root->val << " - " << inorder_successor(root)->val << endl;
	cout << root->left->val << " - " << inorder_successor(root->left)->val
			<< endl;
	cout << root->right->val << " - " << inorder_successor(root->right)->val
			<< endl;
	cout << root->left->left->val << " - "
			<< inorder_successor(root->left->left)->val << endl;
	cout << root->left->right->val << " - "
			<< inorder_successor(root->left->right)->val << endl;
	cout << root->right->left->val << " - "
			<< inorder_successor(root->right->left)->val << endl;
	cout << root->right->right->val << " - "
			<< inorder_successor(root->right->right)->val << endl;
	cout << root->right->left->left->val << " - "
			<< inorder_successor(root->right->left->left)->val << endl;
	cout << root->right->left->right->val << " - "
			<< inorder_successor(root->right->left->right)->val << endl;

	return 0;
}
