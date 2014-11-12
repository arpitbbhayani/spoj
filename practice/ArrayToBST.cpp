/*
 * ArrayToBST.cpp
 *
 *  Created on: Sep 28, 2014
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
	struct node * left, *right;
	int data;
};

struct node * newnode(int d) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->left = t->right = NULL;
	t->data = d;
	return t;
}

void preorder(struct node * root) {

	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}

void create_tree(int * array, int start, int end, struct node ** root) {

	if (start > end)
		return;

	int mid = (start + end) / 2;
	(*root) = newnode(array[mid]);
	create_tree(array, start, mid - 1, &((*root)->left));
	create_tree(array, mid + 1, end, &((*root)->right));
}

int main(int argc, char * argv[]) {

	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(array) / sizeof(array[0]);

	struct node * root = NULL;

	create_tree(array, 0, n - 1, &root);

	preorder(root);
	cout << endl;

	return 0;
}
