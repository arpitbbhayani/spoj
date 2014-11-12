/*
 * countingsort4.cpp
 *
 *  Created on: Aug 23, 2014
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
	char str[14];
	int index;
	struct node * next;
};

struct node ** head, **tail;

struct lis {
	struct node * head;
	struct node * tail;
};

int visited[100];
struct lis has123[100];

void insert(int x, struct node * p) {

	if (visited[x] == 0) {
		visited[x] = 1;
		has123[x].tail = has123[x].head = p;
		return;
	}

	has123[x].tail->next = p;
	has123[x].tail = p;

}

int main(int argc, char * argv[]) {

	int n;
	si(n);

	for (int i = 0; i < n; i++) {

		int x = 0;
		struct node * p = (struct node *) malloc(sizeof(struct node));
		p->next = NULL;
		p->index = i;

		scanf("%d %s", &x, p->str);

		insert(x, p);

	}

	for (int i = 0; i < 100; i++) {

		struct node * p = has123[i].head;

		while (p != NULL) {

			//cout << "checking for p = " << p->str << endl;

			if (p->index >= n / 2) {
				printf("%s ", p->str);
			} else {
				printf("- ");
			}
			p = p->next;
		}


	}

	printf("\n");

	return 0;
}
