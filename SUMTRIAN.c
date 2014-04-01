/*
http://www.codechef.com/problems/SUMTRIAN
*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc , char * argv[] ) {
	int t = 0 , n , i , j;
	int ** array;
	scanf("%d" , &t );

	while ( t-- ) {
		scanf("%d" , &n);

		array = (int **) calloc ( n , sizeof(int *) );
		for ( i = 0 ; i < n ; i++ ) {
			array[i] = (int *) calloc ( n , sizeof(int) );
		}

		for ( i = 0 ; i < n ; i++ ) {
			for ( j = 0 ; j <= i ; j++ ) {
				scanf("%d" , & array[i][j] );
			}
		}

		for ( i = n-2 ; i >= 0 ; i-- ) {
			for ( j = 0 ; j <= i ; j++ ) {
				array[i][j] += array[i+1][j] > array[i+1][j+1] ? array[i+1][j] : array[i+1][j+1] ; 
			}
		}

		printf("%d\n" , array[0][0] );
		
		for ( i = 0 ; i < n ; i++ ) {
			free ( array[i] );
		}
		free ( array );

	}

	return 0;
}
