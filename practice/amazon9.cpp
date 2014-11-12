/*
 * amazon9.cpp
 *
 *  Created on: May 31, 2014
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

int is_children_sum(struct node * root) {

	int l = 0, r = 0;

	if ( root == NULL || root->left == root->right )
		return 1;

	if (root->left)
		l = root->left->data;
	if (root->right)
		r = root->right->data;

	cout << "l = " << l << " and r = " << r << " data = " << root->data << endl;

	if (root->data == l + r) {
		return (is_children_sum(root->left) && is_children_sum(root->right));
	} else {
		return 0;
	}

}

int main(int argc, char * argv[]) {

	struct node * root;

	root = newnode(5);
	root->left = newnode(2);
	root->right = newnode(3);
	root->right->right = newnode(3);
	//root->right->left = newnode(1);

	cout << is_children_sum(root) << endl;

	return 0;
}
