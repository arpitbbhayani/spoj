/*
 * Microsoft33.cpp
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

struct node_tree {
	struct node_tree * left, *right;
	int data;
};

struct node_tree * newnode_tree(int d) {
	struct node_tree * t = (struct node_tree *) malloc(
			sizeof(struct node_tree));
	t->left = t->right = NULL;
	t->data = d;
	return t;
}

struct node_list {
	struct node_list * next;
	int data;
};

struct node_list * newnode_list(int d) {
	struct node_list * t = (struct node_list *) malloc(
			sizeof(struct node_list));
	t->next = NULL;
	t->data = d;
	return t;
}

struct node_list * head = NULL;

struct node_tree * create_tree(int n) {

	// Inorder

	if (n <= 0)
		return NULL;

	struct node_tree * l = create_tree(n / 2);

	struct node_tree * root = newnode_tree(head->data);
	head = head->next;

	struct node_tree * r = create_tree(n - n / 2 - 1);

	root->left = l;
	root->right = r;

	return root;

}

void preorder(struct node_tree * root) {

	if (root == NULL)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}

int main(int argc, char * argv[]) {

	head = newnode_list(1);
	head->next = newnode_list(2);
	head->next->next = newnode_list(3);
	head->next->next->next = newnode_list(4);
	head->next->next->next->next = newnode_list(5);
	head->next->next->next->next->next = newnode_list(6);
	head->next->next->next->next->next->next = newnode_list(7);

	struct node_tree * root = NULL;

	root = create_tree(7);
	preorder(root);
	cout << endl;

	return 0;
}
