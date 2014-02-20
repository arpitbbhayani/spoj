#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int compar_asc ( const void * a , const void * b ) {
	return (*(int *)a) - (*(int *)b);
}

int main ( int argc ,char * argv[] ) {

	int t;
	scanf("%d" , &t);

	#if DEBUG
		printf("Number of cases : %d\n" , t);
	#endif

	while ( t-- ) {
		int n , i;
		int shelf[10010];
		scanf("%d" , &n);

		#if DEBUG
			printf("Number of shelves : %d\n" , n);
		#endif

		for ( i = 0 ; i < 10010 ; i++ ) {
			shelf[i] = 0;
		}

		for ( i = 1 ; i <= n ;i++ ) {
			int x;
			scanf("%d" , &x);
			// number of books in ith shelf is x
			shelf[i] = x;
		}

		int q;
		scanf("%d" , &q);

		#if DEBUG
			printf("Number of queries : %d\n" , q);
		#endif

		for ( i = 0 ; i < q ; i++ ) {
			int type;
			scanf("%d" , &type);

			#if DEBUG
				printf("Type : %d\n" , type);
			#endif

			if ( type == 0 ) {
				// Find the number of books on the shelf between the shelves x and y
				// both inclusive
				int x , y , k;
				scanf("%d%d%d" , &x , &y , &k);

				#if DEBUG
					printf("x,y,k : %d,%d,%d\n" , x,y,k);
				#endif

				int books[1010] , j;
				for ( j = 0 ; j < 1010 ; j++ ) {
					books[j] = 0;
				}
				for ( j = x ; j <= y ; j++ ) {
					books[shelf[j]] ++;
				}
				for ( j = 0 ; j < 1010 ; j++ ) {
					k -= books[j];
					if ( k <= 0 )
						break;
				}
				printf("%d\n" , j);

			}
			else if ( type == 1 ) {
				// Update number of books in xth shelf to k
				int x , k;
				scanf("%d%d" , &x , &k);
				#if DEBUG
					printf("x,k : %d,%d\n" , x,k);
				#endif
				shelf[x] = k;
			}
		}

	}

	return 0;
}
