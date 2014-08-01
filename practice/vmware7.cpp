/*
 * vmware7.cpp
 *
 *  Created on: May 22, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

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

void zigzag(struct node * root) {
	stack<struct node *> s1, s2;

	s1.push(root);

	while ( 1 ) {

		while (!s1.empty()) {

			struct node * t = s1.top();

			cout << t->data << " ";
			s1.pop();

			if (t->right)
				s2.push(t->right);
			if (t->left)
				s2.push(t->left);

		}

		while (!s2.empty()) {
			struct node * t = s2.top();

			cout << t->data << " ";
			s2.pop();

			if (t->left)
				s1.push(t->left);
			if (t->right)
				s1.push(t->right);

		}

		if ( s1.empty() && s2.empty() )
			break;

	}

	cout << endl;
}

int main(int argc, char * argv[]) {

	struct node * root;

	root = get_new_node(1);
	root->left = get_new_node(2);
	root->right = get_new_node(3);

	root->left->left = get_new_node(4);
	root->left->right = get_new_node(5);

	root->right->left = get_new_node(6);
	root->right->right = get_new_node(7);

	root->right->right->right = get_new_node(8);

	zigzag(root);

	return 0;
}
