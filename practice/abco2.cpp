/*
 * abco2.cpp
 *
 *  Created on: May 26, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

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

void _traverse_vertically(struct node * root, map<int, vector<int> > &m,
		int d) {

	if (root == NULL)
		return;

	m[d].push_back(root->data);

	_traverse_vertically(root->left, m, d - 1);
	_traverse_vertically(root->right, m, d + 1);

}

void traverse_vertically(struct node * root) {

	int flag = 1;
	int d = 0;
	map<int, vector<int> > m;
	_traverse_vertically(root, m, d);

	for (map<int, vector<int> >::iterator itr = m.begin(); itr != m.end();
			itr++) {

		vector<int> l = itr->second;

		if (flag == 0) {
			for (int j = 0; j < l.size(); j++) {
				cout << l[j] << " ";
			}
		} else {
			for (int j = l.size()-1; j >= 0; j--) {
				cout << l[j] << " ";
			}
		}
		cout << endl;
		flag = 1 - flag;

	}

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

	traverse_vertically(root);

	return 0;
}
