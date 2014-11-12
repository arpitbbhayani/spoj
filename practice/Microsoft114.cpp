/*
 * Microsoft114.cpp
 *
 *  Created on: Aug 27, 2014
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

struct node {
	int val;
	struct node * left;
	struct node * right;
};

struct node * newnode(int val) {
	struct node * p = (struct node *) malloc(sizeof(struct node));
	p->left = p->right = NULL;
	p->val = val;
	return p;
}

int is_height_balanced(struct node * root, int * height) {

	if (root == NULL)
		return 0;

	int lh = 0, rh = 0;

	int l = is_height_balanced(root->left, &lh);
	int r = is_height_balanced(root->right, &rh);

	*height = max(lh, rh) + 1;

	cout << "For node : " << root->val << " lh = " << lh << " and  rh = " << rh
			<< endl;

	if (abs(lh - rh) > 1)
		return 0;

	return l && r;

}

int main(int argc, char * argv[]) {

	int h = 0;
	struct node * root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);

	root->left->left = newnode(4);
	root->left->right = newnode(5);

	//root->left->left->left = newnode(6);

	cout << is_height_balanced(root, &h) << endl;
	cout << h << endl;

	return 0;
}

