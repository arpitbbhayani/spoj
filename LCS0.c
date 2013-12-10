#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int readline( char * str ) {
	int i = 0;
	char ch;
	while ( (ch = getchar() ) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}*/

long long int lcs ( int ** array , char * s , char * t , int ls , int lt ) {

	int i , j;
	//int LEFT = 2;
	//int TOP = 1;
	//int CROSS = 3;
	//int dir[1002][1002];
	for ( i = 0 ; i < ls+1 ; i++ ) {
		for ( j = 0 ; j < lt+1 ; j++ ) {
			if ( j == 0 ) {
				array[i][j] = 0;
				//dir[i][j] = TOP;
			}
			else if ( i == 0 ) {
				array[i][j] = 0;
				//dir[i][j] = LEFT;
			}
			else if ( s[i-1] == t[j-1] ) {
				array[i][j] = array[i-1][j-1] + 1;
				//dir[i][j] = CROSS;
			}
			else if ( array[i-1][j] > array[i][j-1] ) {
				array[i][j] = array[i-1][j];
				//dir[i][j] = TOP;
			}
			else if ( array[i][j-1] > array[i-1][j] ) {
				array[i][j] = array[i][j-1];
				//dir[i][j] = LEFT;
			}
			else {
				array[i][j] = array[i][j-1];
				//dir[i][j] = LEFT;
			}
		}
	}
	/*printf("***************************************************************\n");
	printf("Array\n");
	for ( i = 0 ; i < ls+1 ; i++ ) {
		for ( j = 0 ; j < lt+1 ; j++ ) {
			printf("%d " , array[i][j] );
		}
		printf("\n");
	}
	printf("DIRECTION\n");
	for ( i = 0 ; i < ls+1 ; i++ ) {
		for ( j = 0 ; j < lt+1 ; j++ ) {
			printf("%d " , dir[i][j] );
		}
		printf("\n");
	}
	*/
	/*long long int sum = 0;

	while ( ! (i == 0 && j == 0) ) {
		if ( dir[i][j] == LEFT ) {
			sum += 30;
			j -= 1;
		}
		else if ( dir[i][j] == TOP ) {
			sum += 15;
			i -= 1;
		}
		else {
			i -= 1;
			j -= 1;
		}
	}*/

	return array[ls][lt];
}

int main ( int argc , char * argv[] ) {

	int **array;
	char * s = ( char * ) malloc ( 50001 * sizeof(char) );
	char * t = ( char * ) malloc ( 50001 * sizeof(char) );
	int i = 0;

	int ls , lt;

	//ls = readline(s);
	//lt = readline(t);

	scanf("%s" , s);
	scanf("%s" , t);

	ls = strlen(s);
	lt = strlen(t);

	array = (int **) malloc ( (ls + 1) * sizeof(int *) );
	for ( i = 0 ; i < (ls + 1) ; i++ ) {
		array[i] = (int *) malloc ( (lt + 1) * sizeof(int) );
	}


	printf("%lld\n" , lcs(array,s,t,ls,lt));

	/*free(s);
	free(t);
	for ( i = 0 ; i < (ls + 5) ; i++ ) {
		free( array[i] );
	}
	free ( array );
	*/
	return 0;
}
