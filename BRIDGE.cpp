#include <iostream>

using namespace std;

void swap ( int *a , int *b ) {
	int t = *a;
	*a = *b;
	*b = t;
}

void sort ( int * a , int * b , int n ) {
	for ( int  i = 0 ; i < n ; i++ ) {
		for ( int j = i + 1 ; j < n ; j++ ) {
			if ( a[i] > a[j] ) {
				swap(&a[i] , &a[j]);
				swap(&b[i] , &b[j]);
			}
			else if ( a[i] == a[j] ) {
				if ( b[i] > b[j] ) {
					swap( &b[i] , &b[j] );
				}
			}

		}
	}
}

int main ( int argc , char * argv[] ) {

	int t;
	cin >> t;

	int a[10010] , b[10010] , long_seq[10010];

	while ( t-- ) {

		int n;
		cin >> n;

		for(int i = 0 ; i < n ; i++ ) {
			cin >> a[i];
		}

		for(int i = 0 ; i < n ; i++ ) {
			cin >> b[i];
		}
		sort ( a , b , n );

		long_seq[0] = 1;
		int max = 1;

		for ( int i = 1 ; i < n ; i++ ) {
			long_seq[i] = 1;
			for ( int j = i-1 ; j >= 0 ; j-- ) {
				if ( b[j] <= b[i] ) {
					if ( long_seq[j] + 1 >  long_seq[i] ) {
						long_seq[i] = long_seq[j] + 1;
					}
				}
				if ( long_seq [i] > max ) {
					max = long_seq[i];
				}
			}
		}

		cout << max << endl;

	}

	return 0;
}
