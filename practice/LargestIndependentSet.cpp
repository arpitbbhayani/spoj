/*
 * LargestIndependentSet.cpp
 *
 *  Created on: Oct 27, 2014
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

int liss[9];

int is_leaf(struct node * root) {
	return root->left == NULL && root->right == NULL;
}

void fun(struct node * root) {

	if (root == NULL)
		return;

	fun(root->left);
	fun(root->right);

	if (is_leaf(root)) {
		liss[root->data] = 1;
		return;
	}

	int ex = 0, in = 0;
	int in1 = 0, in2 = 0;

	if (root->left != NULL) {
		ex += liss[root->left->data];
	}

	if (root->right != NULL) {
		ex += liss[root->right->data];
	}

	if (root->left != NULL && root->left->left != NULL) {
		in1 += liss[root->left->left->data];
	}

	if (root->left != NULL && root->left->right != NULL) {
		in1 += liss[root->left->right->data];
	}

	if (root->right != NULL && root->right->left != NULL) {
		in2 += liss[root->right->left->data];
	}
	if (root->right != NULL && root->right->right != NULL) {
		in2 += liss[root->right->right->data];
	}
	in = in1 + in2 + 1;

	liss[root->data] = max(in, ex);

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);

	root->left->left = newnode(4);
	root->left->right = newnode(5);

	root->left->right->left = newnode(7);
	root->left->right->right = newnode(8);

	root->right->right = newnode(6);

	for (int i = 1; i <= 8; i++) {
		liss[i] = 0;
	}

	fun(root);
	pi(liss[root->data]);

	for (int i = 1; i < 9; i++) {
		cout << "liss of " << i << " = " << liss[i] << endl;
	}

	return 0;
}
