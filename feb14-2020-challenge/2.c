#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main ( int argc ,char * argv[] ) {

	char sa[10010] , sb[10010];
	int a[26] , b[26];
	int i;

	for ( i = 0 ; i < 26 ; i++ ){
		a[i] = b[i] = 0;
	}

	/*char ch;
	while ( (ch = getchar())!= '\n' ) {
		a[ ch-'a' ] ++;
	}
	while ( (ch = getchar()) != '\n' ) {
		b[ ch-'a' ] ++;
	}*/

	scanf("%s" , sa);
	scanf("%s" , sb);

	for ( i = 0 ; sa[i] != '\0' ; i++ ) {
		a[ sa[i]-'a' ] ++;
	}
	for ( i = 0 ; sb[i] != '\0' ; i++ ) {
		b[ sb[i]-'a' ] ++;
	}

	#if DEBUG
	for ( i = 0 ; i < 26 ; i++ ) {
		printf("%d " , a[i]);
	}
	printf("\n");
	for ( i = 0 ; i < 26 ; i++ ) {
		printf("%d " , b[i]);
	}
	printf("\n");
	#endif

	for ( i = 0 ; i < 26 ; i++ ) {
		int m = a[i] < b[i] ? a[i] : b[i];
		a[i] -= m;
		b[i] -= m;
	}

	int count = 0;
	for ( i = 0 ; i < 26 ; i++ ) {
		count += a[i];
		count += b[i];
	}
	printf("%d\n" , count);
	return 0;
}
