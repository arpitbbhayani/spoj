/*
 * Microsoft14.cpp
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

int is_left_greater(struct node * root) {

	if (root == NULL)
		return 1;

	if (root->left == NULL || root->right == NULL)
		return 1;

	int l = is_left_greater(root->left);
	int r = is_left_greater(root->right);

	if (l && r) {

		if (root->left->data > root->right->data) {
			return 1;
		} else {
			return 0;
		}

	} else {
		return 0;
	}

	return 0;
}

int main(int argc, char * argv[]) {

	struct node * root = newnode(10);

	root->left = newnode(3);
	root->right = newnode(2);

	root->left->left = newnode(7);
	root->left->right = newnode(6);

	root->right->left = newnode(5);
	root->right->right = newnode(4);

	root->right->right->left = newnode(3);
	root->right->right->right = newnode(10);

	cout << is_left_greater(root);

	return 0;
}

