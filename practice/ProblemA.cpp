/*
 * ProblemA.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

float calculate_gpa( int * credits, char * grades, int n) {

	// your code goes here

	return 1.1f;
}

int main ( int argc , char * argv[] ) {

	int testcases;
	scanf("%d" , &testcases);
	while ( testcases-- ) {

		int n;
		scanf("%d" , &n);

		int * credits = ( int * ) malloc( n * sizeof(int) );
		char * grades = ( char * ) malloc( n * sizeof(int) );

		for( int i = 0 ; i < n; i++ ) {
			scanf("%d %c" , &credits[i] , &grades[i]);
		}

		cout << calculate_gpa(credits, grades, n) << endl;

	}
	return 0;
}
