#include <stdio.h>
#include <stdlib.h>

#define DEGUG 1

int main ( int argc ,char * argv[] ) {

	int n , r , k;
	scanf("%d%d%d" , &n,&r,&k);

	int * array = (int *) malloc ( n * sizeof(int) );
	int i = 0;

	for ( i = 0 ; i < n ; i++ ) {
		scanf("%d" , &array[i]);
	}

	int index = 0;
	index = (r) % n;
	index = n - index;

	for ( i = 0 ; i < k ; i++ ) {
		int x , nindex;
		scanf("%d" , &x);
		nindex = (x + index) % n;
		//printf("new index = %d\n" , nindex );
		printf("%d\n" , array[nindex]);
	}

	return 0;
}
