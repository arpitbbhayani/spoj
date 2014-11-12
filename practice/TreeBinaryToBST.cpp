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

void inorder(struct node * root) {
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void inordertoarray(struct node * root, int array[]) {

	if (root == NULL)
		return;

	static int index = 0;
	inordertoarray(root->left, array);
	array[index++] = root->data;
	inordertoarray(root->right, array);
}

int compar(const void * a, const void * b) {
	return (*(int *) a) > (*(int *) b);
}

void arraytoinorder(struct node * root, int array[]) {

	if (root == NULL)
		return;

	static int index = 0;
	arraytoinorder(root->left, array);
	root->data = array[index++];
	arraytoinorder(root->right, array);

}

void binarytobst(struct node * root) {

	int array[5];
	inordertoarray(root, array);

	qsort(array, 5, sizeof(array[0]), compar);

	arraytoinorder(root, array);

}

int main(int argc, char * argv[]) {

	struct node * root = newnode(10);
	root->left = newnode(2);
	root->right = newnode(7);

	root->left->left = newnode(8);
	root->left->right = newnode(4);

	inorder(root);
	cout << endl;
	binarytobst(root);
	inorder(root);
	cout << endl;

	return 0;
}

