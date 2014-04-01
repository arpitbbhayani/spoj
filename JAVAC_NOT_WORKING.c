#include <stdio.h>
#include <stdlib.h>

int main( int argc , char * argv[] ) {

	char str[1024];
	char str1[1024];

	while ( scanf("%s" , str) != EOF ) {
		int i = 0 , k = 0;
		int flag_c = 0;
		int flag_j = 0;
		int error_flag = 0;

		for ( i = 0 ; str[i] != '\0' ; i++ ) {
			if ( str[i] == '_' ) {
				flag_c = 1;
			}
			if ( str[i] >= 'A' && str[i] <= 'Z' ) {
				flag_j = 1;
			}
		}

		if ( flag_c == 1 && flag_j == 1) {
			printf("Error!\n");
			continue;
		}

		if ( flag_c == 1 ) {
			for ( i = 0 ; str[i] != '\0' ; i++ ) {
				if ( str[i] == '_' ) {
					while( str[i] != '\0' && str[i] == '_' ) {
						i++;
					}
					if ( str[i] >= 'a' && str[i] <= 'z' ) {
						str1[k++] = (str[i]-'a') + 'A';
					}
				}
				else {
					str1[k++] = str[i];
				}
			}
			str1[k] = '\0';
			printf("%s\n" , str1);
		}
		else {

			if ( str[0] >= 'A' && str[0] <= 'Z' ) {
				printf("Error!\n");
				continue;
			}
			for ( i = 0 ; str[i] != '\0' ; i++ ) {
				if ( str[i] >= 'A' && str[i] <= 'Z' ) {
					if ( k != 0 )
						str1[k++] = '_';
					str1[k++] = (str[i]-'A') + 'a';
				}
				else {
					str1[k++] = str[i];
				}
			}
			str1[k] = '\0';
			printf("%s\n" , str1);
		}

	}

	return 0;
}
