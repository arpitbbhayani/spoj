#include <stdio.h>

int main( int argc , char * argv[] ) {

	int t , b , j;
	long long int n , i;
	int array[100000];

	scanf("%d" , &t);

	while( t -- ) {
		i = 0;
		scanf("%lld" , &n);
		if( n == 0 ) {
			array[i++] = 1;
		}
		while ( n != 0 ) {
			b = n % 5;
			if( b == 0 ) {
				array[i++] = 5;
				n /= 5;
				n--;
				continue;
			}
			else {
				array[i++] = b;
			}
			n /= 5;
		}

		for( j = i-1 ; j >=0 ; j-- ) {
			if( array[j] == 1 )
				printf("m");
			if( array[j] == 2 )
				printf("a");
			if( array[j] == 3 )
				printf("n");
			if( array[j] == 4 )
				printf("k");
			if( array[j] == 5 )
				printf("u");
		}
		printf("\n");

	}

	return 0;
}
