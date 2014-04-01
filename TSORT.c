/*
http://www.codechef.com/problems/TSORT
*/

#include <stdio.h>
#include <stdlib.h>

int (compar)(const void * a , const void * b) {

	return *((int *) a) - *((int *) b);
}

int main ( int argc , char * argv[] ) {
	int t , i;
	int * a;

	scanf("%d" , &t);

	a = (int *) calloc ( t , sizeof(int) );

	for ( i = 0 ; i < t ; i++ ) {
		scanf("%d\n" , &a[i] );
	}
	qsort ( a , t , sizeof(int) , compar );

	for ( i = 0 ; i < t ; i++ ) {
		printf("%d\n" , a[i] );
	}

	return 0;
}
