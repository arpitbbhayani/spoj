/*
 * RightView.cpp
 *
 *  Created on: Jul 24, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <queue>
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

	queue<struct node *> q;
	q.push(root);

	while (!q.empty()) {
		int nodecount = q.size();

		while (nodecount > 0) {
			struct node * n = q.front();
			q.pop();

			if (nodecount == 1) {
				cout << n->data << endl;
			}

			if (n->left)
				q.push(n->left);
			if (n->right)
				q.push(n->right);

			nodecount--;
		}

	}

}

int main(int argc, char * argv[]) {

	struct node * root;

	root = get_new_node(12);
	root->left = get_new_node(10);
	root->right = get_new_node(30);

	root->right->left = get_new_node(25);
	root->right->right = get_new_node(40);

	root->right->left->left = get_new_node(15);

	print_right_view(root);

	return 0;
}
