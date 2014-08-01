#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DEBUG 1
#define TRUE 1

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

char a[100010];

int main ( int argc , char * argv[] ) {

	int i = 0 , j = 0;
	int la = 0;

	while ( scanf("%s" , a) != EOF ) {

		la = strlen(a);


		printf("String : %s and Length : %d\n" , a , la);

		if ( a[0] == '*' && la == 1 ) {
			break;
		}

		int substr_length = 1;
		int k = 0;

		for ( i = 0 ; i < la ; i++ ) {
			for ( j = 0 ; j < substr_length ; j++ ) {

				if ( i+j >= la )
					break;

				printf("Comparing : %c and %c\n" , a[i+j] , a[j]);

				if ( a[i+j] == a[j] ) {
				}
				else {
					substr_length = i;
					break;
				}
			}
		}

		printf("substr_index = %d\n" , substr_length);
	
	}

	return 0;
}
