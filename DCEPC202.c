#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG 1

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define SIZE 10
ll int array[SIZE][6];

void populate() {
	int i , j;
	for ( i = 0 ; i < SIZE ; i++ ) {
		for ( j = 0 ; j >= i && j < 6 ; j++ ) {
			if ( i == 0 || j == 0 )
				array[i][j] = 1;
			else {
				array[i][j] = array[i-1][j] + array[i][j-1];
			}
		}
	}


	#if DEBUG
		printf("Matrix\n");
		for ( i = 0 ; i < SIZE ; i++ ) {
			for ( j = 0 ; j < 6 ; j++ ) {
				printf("%lld " , array[i][j]);
			}
			printf("\n");
		}
	#endif
}

int main ( int argc , char * argv[] ) {

	populate();

	int t , z;
	scanf("%d" , &t);
	for ( z = 1 ; z <= t ; z++ ) {
		int n;
		scanf("%d" , &n);
	}
	return 0;
}
