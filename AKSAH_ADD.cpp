#include <stdio.h>
int main(int argc, char * argv[]) {
	int a, org, n;
	scanf("%d", &a);

	org = a;
	n = 0;

	while ( a != 0 ) {
		int d = a % 10;
		n = n * 10 + d;
		a = a / 10;
	}

	if ( org == n )
		printf("Palindrome\n");
	else
		printf("Not a Palindrome\n");

	return 0;
}
