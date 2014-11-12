/*
 * TreeLevelNode.cpp
 *
 *  Created on: Oct 16, 2014
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

int level(struct node * root, int n) {

	if (root == NULL) {
		return 0;
	}

	if (root->data == n) {
		return 1;
	}

	int is_left = level(root->left, n);
	int is_right = level(root->right, n);

	if (is_left || is_right) {

		if (is_left != 0) {
			return is_left + 1;
		} else {
			return is_right + 1;
		}
	}

	return 0;
}

int main(int argc, char * argv[]) {

	struct node * root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->right->left = newnode(4);
	root->left->left = newnode(5);
	root->left->left->right = newnode(6);

	cout << level(root, 1) << endl;
	cout << level(root, 2) << endl;
	cout << level(root, 3) << endl;
	cout << level(root, 4) << endl;
	cout << level(root, 5) << endl;
	cout << level(root, 6) << endl;

	return 0;
}

