/*
 * memory_allocation_example.c
 *
 *  Created on: Aug 25, 2014
 *      Author: Arpit Bhayani
 */

#include <stdio.h>
#include <stdlib.h>

struct info {
	int a;
	int b;
};

int main(int argc, char * argv[]) {

	int * array = NULL;

	/*
	 * Suppose we want to create an array of SIZE = 16
	 * and reference it with variable name 'array'
	 */

	array = (int *) malloc(16 * sizeof(int));

	for (int i = 0; i < 16; i++) {
		array[i] = i;
	}

	printf("\nPrinting array : ");
	for (int i = 0; i < 16; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	/*
	 * Since memory is of no use to us now;
	 * so freeing it.
	 */
	free(array);

	/*
	 * For structures:
	 * Suppose we wish to allocate an array 'b' of size 16 and of type structure info.
	 */

	struct info * b = NULL;

	b = (struct info *) malloc(16 * sizeof(struct info));

	for (int i = 0; i < 16; i++) {
		b[i].a = i;
		b[i].b = 2 * i;
	}

	printf("\nPrinting array of structure info :\n");
	for (int i = 0; i < 16; i++) {
		printf("%d - %d\n", b[i].a, b[i].b);
	}
	printf("\n");

	/*
	 * Since memory is of no use to us now;
	 * so freeing it.
	 */
	free(b);

	return 0;
}
