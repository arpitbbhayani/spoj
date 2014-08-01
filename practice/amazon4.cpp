/*
 * amazon4.cpp
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

struct node * get_new_node(int val) {
	struct node * t = (struct node *) malloc(sizeof(struct node));
	t->left = t->right = NULL;
	t->data = val;
	return t;
}

void _print_right_view(struct node * root, int current, int * max) {

	if (current > *max) {
		cout << root->data << endl;
		*max = current;
	}

	if (root->right)
		_print_right_view(root->right, current + 1, max);

	if (root->left)
		_print_right_view(root->left, current + 1, max);

}

void print_right_view(struct node * root) {
	int current_level = 1;
	int max_level = 0;

	_print_right_view(root, current_level, &max_level);

}

int main(int argc, char * argv[]) {

	struct node * root;

	root = get_new_node(1);
	root->left = get_new_node(2);
	root->right = get_new_node(3);

	root->left->right = get_new_node(4);
	root->right->left = get_new_node(5);

	print_right_view(root);

	return 0;
}
