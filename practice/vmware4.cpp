/*
 * vmware4.cpp
 *
 *  Created on: May 22, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

void merge ( int * a , int l , int m , int h ) {

	int b[1024];
	int i , j , k;

	i = k = l;
	j = m+1;

	while ( i <= m && j <= h ) {
		if ( a[i] < a[j] ) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}

	if ( i > m ) {
		while ( j <= h ) {
			b[k++] = a[j++];
		}
	}

	if ( j > h ) {
		while ( i <= m ) {
			b[k++] = a[i++];
		}
	}

	k = l;
	while ( k <= h ) {
		a[k] = b[k];
		k++;
	}

}

void mergesort( int *a , int l , int h ) {

	if ( l >= h )
		return;

	int m = (l+h)/2;
	mergesort(a,l,m);
	mergesort(a,m+1,h);
	merge(a,l,m,h);

}

int main ( int argc , char * argv[] ) {

	int a[] = {4,1,5,2,6,7,8,-1,4,0,2};
	int n = (sizeof(a)/sizeof(a[0]));

	mergesort(a,0,n-1);

	for ( int i = 0 ; i < n ; i++ ) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
