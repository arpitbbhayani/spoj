/*
 * Microsoft16.cpp
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
};

struct node * newnode(int data) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

void inorder(struct node * root) {

	if (root == NULL)
		return;

	inorder(root->left);
	pi(root->data);
	inorder(root->right);

}

int inorder_successor(struct node * p, struct node * root) {

	if (p->right) {

		struct node * q = p->right;
		while (q->left)
			q = q->left;

		return q->data;

	} else {

		struct node * q = NULL;

		while (root) {

			cout << "root = " << root->data;

			if (p->data > root->data) {
				cout << " goin right" << endl;
				root = root->right;
			} else if (p->data < root->data) {
				cout << " goin left" << endl;
				q = root;
				root = root->left;
			} else {
				cout << " break" << endl;
				break;
			}

		}

		if (q == NULL)
			return -1;

		return q->data;

	}

	return -1;

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(10);

	root->left = newnode(5);
	root->right = newnode(15);

	root->left->left = newnode(2);
	root->left->right = newnode(7);

	root->right->left = newnode(12);
	root->right->right = newnode(17);

	root->right->right->left = newnode(16);
	root->right->right->right = newnode(18);

	cout << inorder_successor(root->right->right, root) << endl;

	return 0;
}
