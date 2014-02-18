#include <stdio.h>
#include <stdlib.h>

int readline( char * str ) {

	int i = 0;
	char ch;

	while ( (ch = getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int is_upper( char c ) {
	return (c >= 'A' && c <= 'Z');
}

int main ( int argc , char * argv[] ) {

	int t = 0;
	char str1[10001] , str2[10001];

	scanf("%d" , &t);
	getchar();
	while ( t-- ) {
		int * s1 , * s2;
		s1 = (int *) calloc ( 52 , sizeof(int) );
		s2 = (int *) calloc ( 52 , sizeof(int) );

		int ls1 = readline(str1);
		int ls2 = readline(str2);

		//printf("str1 = %s\n" , str1);
		//printf("str2 = %s\n" , str2);

		int i = 0;

		for ( i = 0 ; i < ls1 ; i++ ) {
			char ch = str1[i];
			if ( is_upper(ch) ) {
				s1[ch - 'A'] ++;
			}
			else {
				s1[ch - 'a' + 26] ++;
			}
		}

		for ( i = 0 ; i < ls2 ; i++ ) {
			char ch = str2[i];
			if ( is_upper(ch) ) {
				s2[ch - 'A'] ++;
			}
			else {
				s2[ch - 'a' + 26] ++;
			}
		}

		int count = 0;
		for ( i = 0 ; i < 52 ; i++ ) {
			count += (s1[i]<s2[i] ? s1[i] : s2[i]);
		}

		printf("%d\n" , count);

		free(s1);
		free(s2);

	}

	return 0;
}
