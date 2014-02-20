#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

/**
	Python impl:

	def egcd(a, b):
		x,y, u,v = 0,1, 1,0
		while a != 0:
			q, r = b//a, b%a
			m, n = x-u*q, y-v*q
			b,a, x,y, u,v = a,r, u,v, m,n
		return b, x, y
*/

// Extended Euclidean_algorithm ( from CLRS )
int ext_gcd (int a, int b, int *x , int *y) {
	if (a == 0) {
		*x = 0; *y = 1;
		return b;
	}
	int x1, y1;
	int d = ext_gcd (b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return d;
}

// Euclidean_algorithm
int gcd ( int a , int b ) {
	if ( b == 0 )
		return a;
	return gcd( b , a % b );
}

int main ( int argc ,char * argv[] ) {

	int t;
	scanf("%d" , &t);

	while ( t-- ) {
		int a,b,c;
		scanf("%d%d%d" , &a,&b,&c);

		if ( c > a && c > b ) {
			printf("-1\n");
			continue;
		}

		if ( a < b ) {
			a ^= b;
			b ^= a;
			a ^= b;
		}

		#if DEBUG
			printf("a:%d ,b:%d and c:%d\n" , a , b , c);
		#endif

		int s = 0 , t = 0;
		int g = ext_gcd(a,b,&s,&t);

		#if DEBUG
			printf("gcd:%d\n" , g);
			printf("s:%d and t:%d\n" ,s,t);
		#endif

		if ( c % g != 0 ) {
			printf("-1\n");
			continue;
		}

		s = (s < 0) ? -s : s;
		t = (t < 0) ? -t : t;

		#if DEBUG
			printf("new -> s:%d and t:%d\n" , s,t);
		#endif


		printf("%d\n" , s+t);

	}

	return 0;
}
