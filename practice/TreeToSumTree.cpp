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
	struct node * left, *right;
};

struct node * newnode(int d) {
	struct node * t = (struct node *) malloc(sizeof(struct node) * 1);
	t->left = t->right = NULL;
	t->data = d;
	return t;
}

void inorder(struct node * root) {
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int tosumtree(struct node * root) {

	if (root == NULL)
		return 0;

	int old = root->data;

	int l = tosumtree(root->left);
	int r = tosumtree(root->right);

	root->data = l + r;

	return root->data + old;

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(10);
	root->left = newnode(-2);
	root->right = newnode(6);

	root->left->left = newnode(8);
	root->left->right = newnode(-4);

	root->right->left = newnode(7);
	root->right->right = newnode(5);

	inorder(root);
	cout << endl;
	tosumtree(root);
	inorder(root);
	cout << endl;

	return 0;
}
