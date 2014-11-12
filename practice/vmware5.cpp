/*
 * vmware5.cpp
 *
 *  Created on: May 18, 2014
 *      Author: Arpit Bhayani
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define DEBUG 0

using namespace std;

int lis ( int * arr , int n ) {

	int *lis , i , j , max;

	lis = (int *) malloc ( n * sizeof(int));

	for ( i = 0 ; i < n ; i++ )
		lis[i] = 1;

	for ( i = 1 ; i < n ; i++ ) {
		for ( j = 0 ; j < i ; j++ ) {
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1 ) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	max = lis[0];
	for ( i = 1 ; i < n ; i++ ) {
		if ( lis[i] > max )
			max = lis[i];
	}

	return max;
}

int main ( int argc , char * argv[] ) {

	int array[] = {10,22,9,33,21,50,41,60,80};
	int n = 9;

	cout << "LIS : " << lis(array , 9) << endl;

	return 0;
}
