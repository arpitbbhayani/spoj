/*
 http://www.codechef.com/problems/TSORT
 */

#include <stdio.h>
#include <stdlib.h>

int hash[1000010];

int main(int argc, char * argv[]) {
	int t, i, x;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d\n", &x);
		hash[x]++;
	}

	int count = t;
	int index = 0;

	while( count != 0 ) {

		for( i = 0 ; i < hash[index] ; i++ ) {
			printf("%d\n", index);
			count--;
		}
		index++;

	}

	return 0;
}
