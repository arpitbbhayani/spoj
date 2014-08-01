/*
 * amazon5.cpp
 *
 *  Created on: May 30, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode(int val) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->left = t->right = NULL;
	t->data = val;
	return t;
}

void _print_top_view(struct node * root, int cur, int * min, int * max) {

	if (cur < 0 && cur < *min) {
		cout << root->data << endl;
		*min = cur;
	} else if (cur > 0 && cur > *max) {
		cout << root->data << endl;
		*max = cur;
	} else if (cur == 0 && *min == *max) {
		cout << root->data << endl;
	}

	if (root->left)
		_print_top_view(root->left, cur - 1, min, max);

	if (root->right)
		_print_top_view(root->right, cur + 1, min, max);

}

void print_top_view(struct node * root) {

	int cur = 0, min = 0, max = 0;

	_print_top_view(root, cur, &min, &max);

}

int main(int argc, char * argv[]) {

	struct node * root;

	root = newnode(1);
	root->left = newnode(2);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->left->left->left = newnode(9);
	root->left->right->left = newnode(10);

	root->right = newnode(3);
	root->right->left = newnode(6);
	root->right->left->right = newnode(7);
	root->right->left->right->right = newnode(8);
	root->right->left->right->right->right = newnode(11);

	print_top_view(root);

	return 0;
}
