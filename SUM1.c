#include <stdio.h>

int main( int argc , char * argv[] ) {

	int t;
	scanf("%d" , &t);

	while ( t-- ) {
		long long int n;
		long long int n3 , n5 , n15;

		scanf("%lld" , &n);

		n3 = (n-1) / 3;
		n5 = (n-1) / 5;
		n15 = (n-1) / 15;

		long long int sum3 = 3 * (n3) * (n3+1) / 2;
		long long int sum5 = 5 * (n5) * (n5+1) / 2;
		long long int sum15 = 15 * (n15) * (n15+1) / 2;

		printf("%lld\n" , (sum3+sum5)-sum15);
			
	}
 
	return 0;
}
