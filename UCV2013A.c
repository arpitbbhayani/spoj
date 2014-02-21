#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define DEBUG 1

int main ( int argc , char * argv[] ) {

	while ( 1 ) {
		long long int a,b;
		long long int result = 0;
		scanf("%lld%lld" , &a,&b);

		if ( a == 0 && b == 0 ) {
			break;
		}

		long long int t = a;
		int i = 0;
		for ( i = 1 ; i <= b ; i++ ) {
			result = (result + t) % MOD;
			t = (t * a) % MOD;
		}

		printf("%lld\n" , result);

	}

	return 0;
}
