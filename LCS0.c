#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readline( char * str ) {
	int i = 0;
	char ch;
	while ( (ch = getchar() ) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int lcs ( int * x , int * y , char * s , char * t , int ls , int lt ) {

	int i , j , k;

	for ( i = 1 ; i < ls + 1 ; i++ ) {
		for ( j = 1 ; j < lt + 1 ; j++ ) {
			if ( s[i-1] == t[j-1] ) {
				y[j] = x[j-1] + 1;
			}
			else {
				y[j] = y[j-1] > x[j] ? y[j-1] : x[j];
			}
		}

		int * t;
		t = x;
		x = y;
		y = t;
	}

	return x[lt];
}

int main ( int argc , char * argv[] ) {

	char s[50001] , t[50001];
	int x[50002] , y[50002];

	int ls , lt;
	int d = 0;

	ls = readline(s);
	lt = readline(t);

	/*int start = 0;
	while ( start < ls && start < lt && s[start] == t[start] ) {
		start ++;
	}

	while ( start < ls && start < lt && s[ls-1] == t[lt-1] ) {
		ls--;
		lt--;
		d++;
	}
	*/

	printf("%d\n" , lcs(x,y,s,t,ls,lt));

	return 0;
}
