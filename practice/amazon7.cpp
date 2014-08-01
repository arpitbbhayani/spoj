/*
 * amazon7.cpp
 *
 *  Created on: May 31, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

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

#define SIZE 1024

void _max_at_levels(struct node * root, int * result, int cur) {

	if (root->data > result[cur])
		result[cur] = root->data;

	if (root->left)
		_max_at_levels(root->left, result, cur + 1);

	if (root->right)
		_max_at_levels(root->right, result, cur + 1);

}

void max_at_levels(struct node * root) {

	int result[SIZE], cur = 0;
	for (int i = 0; i < SIZE; i++) {
		result[i] = INT_MIN;
	}

	_max_at_levels(root, result, cur);

	for (int i = 0; i < SIZE; i++) {
		if (result[i] == INT_MIN)
			break;
		cout << "Level : " << i << " max value : " << result[i] << endl;
	}

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

	max_at_levels(root);

	return 0;
}
