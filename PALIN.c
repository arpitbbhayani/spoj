#include <stdio.h>

int readline ( int *str ) {
	int i = 1;
	char ch;
	while ( ( ch = getchar() ) != '\n' ) {
		str[i] = ch - '0';
		i++;
	}
	str[0] = 0;
	return i;
}

int main ( int argc , char * argv[] ) {

	int t , len = 0 , i = 0 ;
	int array[1000010];
	int carry = 0;
	int a , b;

	scanf("%d" , &t);
	getchar();

	while ( t-- ) {

		len = readline ( array );
		carry = 0;

		int mid = ((len+1)/2) - 1;

		a = mid;
		b = len - a;

		while ( a > 0 && b < len && array[a] == array[b] ) {
			a--;
			b++;
		}

		int flag = 0;
		if ( array[a] < array[b] || a == 0) {
			flag = 1;
		}

		for ( i = mid ; i > 0 ; i-- ) {
			a = i;
			b = len - i;
			array[b] = array[a];
		}

		if ( flag == 1 ) {
			carry = 1;
			if ( (len-1) & 1 ) {
				array[mid+1] += carry;
				carry = array[mid+1] / 10;
				array[mid+1] %= 10;
			}
			for ( i = mid ;  i > 0 ; i -- ) {
				int _a = i;
				int _b = len - i;
				array[_a] += carry;
				carry = array[_a] / 10;
				array[_a] %= 10;
				array[_b] = array[_a];
			}
		}

		if ( carry == 1 ) {
			array[0] = 1;
			array[len - 1 ] = 1;
		}


		if ( array[0] != 0 ) printf("%d" , array[0] );
		for ( i = 1 ; i < len ; i++ ) {
			printf("%d" , array[i]);
		}
		printf("\n");
	}

	return 0;
}

