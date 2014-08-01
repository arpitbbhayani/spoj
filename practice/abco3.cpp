/*
 * abco3.cpp
 *
 *  Created on: May 26, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

int main ( int argc , char * argv[] ) {

	int array[4] = {4,1,8.9};
	int n = 4;

	int count = 0  , sum = 0;

	for ( int i = 0 ; i < n ; i++ ) {
		cout << array[i] << " ";
	}
	cout << endl;

	for ( int i = 0 ; i < n ; i++ ) {

		sum = 0;

		for ( int j = i ; j < n ; j++ ) {

			sum += array[j];
			if ( sum != 0 && sum % 9 == 0 ) {
				count ++;
			}

		}
		cout << endl;
	}

	cout << count << endl;

	return 0;
}
