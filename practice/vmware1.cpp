/*
 * vmware1.cpp
 *
 *  Created on: May 22, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
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

int path_found = 0;

void _print_path(struct node * root, int * path, int &pathLen, int DATA) {

	if (root == NULL)
		return;

	if (path_found == 0) {

		if (root->data == DATA) {
			path_found = 1;
		}
		else {
			path[pathLen++] = root->data;
		}

		_print_path(root->left, path, pathLen, DATA);
		_print_path(root->right, path, pathLen, DATA);

	}

}

void get_path(struct node * root, int val , vector<int> &pathVector ) {

	int path[1024];
	int pathLen = 0;

	_print_path(root, path, pathLen, val);

	for (int i = 0; i < pathLen; i++) {
		pathVector.push_back(path[i]);
		//cout << path[i] << " ";
	}
	//cout << endl;
}

void get_all_common_ancestor( struct node * root , int val1 , int val2 ) {

	vector<int> path1 , path2;

	path_found = 0;
	get_path( root , val1 , path1);

	path_found = 0;
	get_path( root , val1 , path2);

	int i = 0;
	while ( path1[i] == path2[i] && i < path1.size() && i < path2.size()) {
		cout << path1[i] << " ";
		i++;
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

	root->left->left->right = get_new_node(10);

	get_all_common_ancestor(root , 2,3);

	return 0;
}
