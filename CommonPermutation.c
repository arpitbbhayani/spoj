/*
 * CommonPermutation.c
 *
 *  Created on: Apr 30, 2014
 *      Author: Arpit Bhayani
 */


#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define gc getchar
#define ll long long

void scanint(ll int *x) {
	register ll int c = gc();
	*x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int main ( int argc , char * argv[] ) {

	int t;
	char stra[1024];
	char strb[1024];

	while ( 1 ) {

		int la = readline( stra );
		int lb = readline( strb );

		printf("str1 : %s and length = %d\n" , stra , la);
		printf("str2 : %s and length = %d\n" , strb , lb);

	}

	return 0;
}
