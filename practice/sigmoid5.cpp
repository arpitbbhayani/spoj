/*
 * sigmoid5.cpp
 *
 *  Created on: May 22, 2014
 *      Author: Arpit Bhayani
 */


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

#define DEBUG 0

using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * get_new_node ( int val ) {
	struct node * t = (struct node *) malloc ( sizeof(struct node) );
	t -> left = t -> right = NULL;
	t -> data = val;
	return t;
}

int max_num = 0;
int FLAG = 1;

void is_bst ( struct node * root ) {

	if ( root == NULL )
		return;

	is_bst ( root->left );

	if ( root->data >= max_num ) {
		max_num = root->data;
	}
	else {
		FLAG = 0;
	}

	is_bst ( root->right );

}

int main ( int argc , char * argv[] ) {

	struct node * root;

	root = get_new_node(20);
	root->left = get_new_node(8);
	root->right = get_new_node(22);

	root->left->left = get_new_node(4);
	root->left->right = get_new_node(12);

	root->left->right->left = get_new_node(14);
	root->left->right->right = get_new_node(10);

	is_bst(root);

	cout << "is-bst = " << FLAG << endl;
	cout << endl;
}
