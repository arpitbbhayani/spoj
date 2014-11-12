/*
 * TreeAllNodesAtDistanceK.cpp
 *
 *  Created on: Oct 28, 2014
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
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->left = t->right = NULL;
	t->data = d;
	return t;
}

list<struct node *> l;
struct node * array[10];

int fill_array(struct node * n, struct node * root, int len) {

	if (root == NULL) {
		return -1;
	}

	array[len] = root;
	if (root == n) {
		return len + 1;
	}

	int l = -1, r = -1;

	l = fill_array(n, root->left, len + 1);
	if (l == -1)
		r = fill_array(n, root->right, len + 1);

	if (l != -1) {
		return l;
	}
	if (r != -1) {
		return r;
	}
	return -1;
}

void addKDistDown(struct node * n, int k) {

	if (n == NULL) {
		return;
	}

	if (k == 0) {
		l.push_back(n);
		return;
	}

	addKDistDown(n->left, k - 1);
	addKDistDown(n->right, k - 1);

}

void printK(struct node * n, struct node * root, int k) {

	int len = 0;
	len = fill_array(n, root, 0);

	addKDistDown(n, k);

	int ancestor = 0;
	for (int i = len - 2; i >= 0; i--) {

		ancestor++;
		int tempk = k - ancestor;

		if (tempk == 0) {
			l.push_back(array[i]);
			break;
		}

		if (array[i]->left == array[i + 1]) {

			/*cout << array[i + 1]->data << " is left child of " << array[i]->data
					<< endl;
			cout << "Calling down method for k = " << k << " and node = "
					<< array[i]->right->data << endl;*/
			addKDistDown(array[i]->right, tempk - 1);

		} else if (array[i]->right == array[i + 1]) {

			/*cout << array[i + 1]->data << " is right child of "
			 << array[i]->data << endl;
			 cout << "Calling down method for k = " << k << " and node = "
			 << array[i]->left->data << endl;*/

			addKDistDown(array[i]->left, tempk - 1);
		}
	}

	cout << "K Distance node: ";
	for (list<struct node *>::iterator itr = l.begin(); itr != l.end(); itr++) {
		cout << (*itr)->data << " ";
	}
	cout << endl;

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(20);
	root->left = newnode(8);
	root->right = newnode(22);

	root->right->left = newnode(23);

	root->left->left = newnode(4);
	root->left->right = newnode(12);

	root->left->right->left = newnode(10);
	root->left->right->right = newnode(14);

	printK(root->left->left, root, 4);

	return 0;
}
