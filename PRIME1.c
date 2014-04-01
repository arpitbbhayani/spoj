/*
 * PRIME1.c
 *
 *  Created on: Mar 8, 2014
 *      Author: Arpit Bhayani
 */

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define gc getchar
#define ll long long

void scanint(int *x) {
	register int c = gc();
	*x = 0;
	for (; (c < 48 || c > 57); c = gc())
		;
	for (; c > 47 && c < 58; c = gc()) {
		*x = (*x << 1) + (*x << 3) + c - 48;
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

#define SIZE 1000000001
char array[SIZE];

int main(int argc, char * argv[]) {

	int t, i, j;

	array[0] = 1;
	array[1] = 1;

	for (i = 2; i < SIZE; i++) {
		if (array[i] == 1)
			continue;
		array[i] = 0;
		for (j = 2; j*i < SIZE; j++) {
			array[i * j] = 1;
		}
	}

	//printf("Generated\n");
	scanf("%d", &t);

	while (t--) {
		int n, m;

		scanf("%d%d" , &n , &m);

		for (i = n; i <= m; i++) {
			if (array[i] == 0) {
				printf("%d\n", i);
			}
		}

		printf("\n");

	}
	return 0;
}
