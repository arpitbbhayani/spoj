#include <cstdio>
#include <cstdlib>
#include <stack>

#define DEBUG 0

using namespace std;

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int array[1001][1001];

void dfs ( int n ) {

	int i , j ;
	int visited[n+1];

	stack<int> s;

	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( array[i][j] == 1 ) {
				for ( int k = 1 ; k <= n ; k++ ) {
					if ( array[j][k] == 1 && array[i][k] == 1 ) {
						array[i][k] = 0;
					}
				}
			}
		}
	}


	#if DEBUG
		printf("Matrix:\n");
		for ( i = 1 ; i <= n ; i++ ) {
			printf("Node %d: " , i);
			for ( j = 1 ; j <= n ; j++ ) {
				printf("%d " , array[i][j] );
			}
			printf("\n");
		}
	#endif

}

int main ( int argc , char * argv[] ) {

	int n , m;
	int i , j;
	scanf("%d%d" , &n , &m);

	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			array[i][j] = 0;
		}
	}

	for ( i = 1 ; i <= m ; i++ ) {
		int a,b;
		scanf("%d%d" , &a,&b);
		array[b][a] = 1;
	}


	#if DEBUG
		printf("Adjecency List : \n");
		for ( i = 1 ; i <= n ; i++ ) {
			printf("Node %d:" , i);
			for ( j = 1 ; j <= n ; j++ ) {
				if ( array[i][j] != 0 )
					printf(" %d" , j);
			}
			printf("\n");
		}
	#endif

	dfs(n);

	int count = 0;
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( array[i][j] == 1 ) {
				count ++;
			}
		}
	}
	printf("%d\n" , count);
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			if ( array[i][j] == 1 ) {
				printf("%d %d\n" , i,j);
				count ++;
			}
		}
	}

	return 0;
}
