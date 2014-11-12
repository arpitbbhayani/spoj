/*
 * flextrade1.cpp
 *
 *  Created on: May 26, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

int main(int argc, char * argv[]) {

	char array[21] = { 'a', 'c', 'b', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'a',
			'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' };
	int n = 21;

	char ch = array[0];

	for ( int i = 1 ; i < n ; i++ ) {
		ch = ch ^ array[i];
	}

	cout << ch << endl;

	return 0;
}
