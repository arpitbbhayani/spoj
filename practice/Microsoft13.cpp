/*
 * Microsoft13.cpp
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

struct node * f, *s, *m;
struct node * prev;

void correct_tree(struct node * root) {

	if (root == NULL)
		return;

	correct_tree(root->left);

	if (prev != NULL && root->data < prev->data) {

		if (f == NULL) {
			f = prev;
			m = root;
		} else {
			s = root;
		}

	}

	prev = root;

	correct_tree(root->right);

}

void inorder(struct node * root) {

	if (root == NULL)
		return;

	inorder(root->left);
	pi(root->data);
	inorder(root->right);

}

int main(int argc, char * argv[]) {

	struct node * root1 = newnode(10);

	root1->left = newnode(5);
	root1->left->left = newnode(2);
	root1->left->right = newnode(20);

	root1->right = newnode(8);

	correct_tree(root1);

	if (f != NULL && s != NULL) {
		int t = f->data;
		f->data = s->data;
		s->data = t;
	} else if (f != NULL && s == NULL) {
		int t = f->data;
		f->data = m->data;
		m->data = t;
	}

	inorder(root1);

	return 0;
}
