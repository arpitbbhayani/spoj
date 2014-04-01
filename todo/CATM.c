#include <stdio.h>
#include <stdlib.h>

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

int abc ( int a ) {
	return a < 0 ? -a : a;
}

int min ( int a , int b ) {
	return a < b ? a : b;
}

int main ( int argc , char * argv[] ) {

	int t , z;
	int r , c;
	scanf("%d%d" , &r , &c);
	scanf("%d" , &t);
	for ( z = 1 ; z <= t ; z++ ) {

		int xm , ym , xc1 , yc1 , xc2 , yc2;
		scanf("%d%d%d%d%d%d" , &xm , &ym , &xc1 , &yc1 , &xc2 , &yc2 );

		// When both cats are on one side
		if ( ((xm <= xc1 && xm <= xc2) || (xm >= xc1 && xm >= xc2)) || ((ym <= yc1 && ym <= yc2) || (ym >= yc1 && ym >= yc2)) ) {
			printf("YES\n");
			continue;
		}

		// If mouse has a vertical way out
		if ( (xm < xc1 && xm > xc2) || (xm < xc2 && xm > xc2) ) {

			// this is the distance required by any of the cat to reach the mouse's row
			int dist = min(abs(xm-xc1) , abs(xm-xc2));

			if ( ym > dist || 

			continue;
		}

		// If mouse has a vertical way out
		if () {

			continue;
		}


		printf("NO\n");
	}
	return 0;
}
