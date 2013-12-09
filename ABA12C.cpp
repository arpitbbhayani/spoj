#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int knapsack ( int s , int n , int size[] , int value[] ) {
	int k[n+1][s+1];

	for ( int i = 0 ; i < n+1 ; i++ ) {

		for ( int j = 0 ; j < s+1 ; j++ ) {

			if ( i == 0 || j == 0 ) {
				k[i][j] = 0;
			}
			else if ( size[i-1] <= j ) {

				k[i][j] = max( value[i-1]+k[i-1][j-size[i-1]] , k[i-1][j]);
			}
			else {
				k[i][j] = k[i-1][j];
			}
		}
	}
	
	/*for ( int i = 0 ; i < n+1 ; i++ ) {

		for ( int j = 0 ; j < s+1 ; j++ ) {
			printf("%d " , k[i][j]);
		}
		printf("\n");
	}
	*/
	return k[n][s];
}

int main( int argc , char * argv[] ) {

	int t;
	int s , n;

	scanf("%d" , &t);

	while ( t-- ) {

		scanf("%d%d" , &s , &n);
	
		int size[n] , value[n];

		for( int i = 0 ; i < n ; i++ ) {
			scanf("%d" , &value[i]);
			size[i] = 1;
		}

		printf("%d\n" , knapsack ( s , n , size , value ));

	}

	return 0;
}

