/*
 * Microsoft25.cpp
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
	struct node * left, *right;
	int val;
};

struct node * newnode(int d) {

	struct node * p = (struct node *) malloc(sizeof(struct node));
	p->left = p->right = NULL;
	p->val = d;
	return p;

}

int is_bst(struct node * root) {
	static struct node * prev = NULL;

	if (root == NULL)
		return 1;

	int l = 0, r = 0;

	l = is_bst(root->left);

	if (prev == NULL) {
		prev = root;
		return 1;
	}

	if (prev->val < root->val) {

	} else {
		return 0;
	}

	prev = root;

	r = is_bst(root->right);

	return l && r;
}

int main(int argc, char * argv[]) {

	struct node * root = newnode(20);

	root->left = newnode(15);
	root->right = newnode(25);
	root->left->left = newnode(10);
	root->left->right = newnode(17);
	root->right->left = newnode(22);
	root->right->right = newnode(27);
	root->right->left->left = newnode(21);
	root->right->left->right = newnode(23);

	cout << is_bst(root) << endl;

	return 0;
}
