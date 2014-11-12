/*
 * TreeCloneRandomPointer.cpp
 *
 *  Created on: Oct 31, 2014
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
	struct node * left, *right;
	struct node * random;
};

struct node * newnode(int d) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->left = t->right = NULL;
	t->data = d;
	return t;
}

void inorder(struct node * root) {

	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);

}

void addleft(struct node * root) {

	if (root == NULL) {
		return;
	}

	struct node * temp = root->left;
	root->left = newnode(root->data);
	root->left->left = temp;

	addleft(root->left->left);
	addleft(root->right);
}

void setrandom(struct node * root) {

	if (root == NULL) {
		return;
	}

	if (root->random != NULL)
		root->left->random = root->random->left;

	setrandom(root->left->left);
	setrandom(root->right);

}

void extractsubtree(struct node * root, struct node ** root2) {

	if (root == NULL) {
		(*root2) = NULL;
		return;
	}

	(*root2) = root->left;
	root->left = root->left->left;

	extractsubtree(root->left, &((*root2)->left));
	extractsubtree(root->right, &((*root2)->right));
}

void clone(struct node * root, struct node ** root2) {

	// Modify tree to store same element as left child.

	addleft(root);
	setrandom(root);
	extractsubtree(root, root2);

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);

	root->right->left = newnode(6);
	root->right->right = newnode(7);

	root->random = NULL;
	root->left->random = root->right;
	root->right->random = root;
	root->left->left->random = root->left;
	root->left->right->random = root->right;

	struct node * root2 = NULL;

	inorder(root);
	cout << endl;

	clone(root, &root2);

	inorder(root);
	cout << endl;

	inorder(root2);
	cout << endl;

	return 0;
}
