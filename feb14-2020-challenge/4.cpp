#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

#define DEBUG 0
#define LLI long long int

using namespace std;

struct node {
	LLI x;
	LLI y;
};

int compar_asc ( const void * a , const void * b ) {
	return (*(LLI *)a) - (*(LLI *)b) ;
}

int main ( int argc , char * argv[] ) {

	LLI n , m , k , i;
	scanf("%lld%lld%lld" , &n,&m,&k);

	struct node * ln = (struct node *) malloc ( n * sizeof(struct node) );
	struct node * lm = (struct node *) malloc ( m * sizeof(struct node) );

	for ( i = 0 ; i < n ; i++ ) {
		scanf("%lld%lld" , &ln[i].x , &ln[i].y);
	}

	for ( i = 0 ; i < m ; i++ ) {
		scanf("%lld%lld" , &lm[i].x , &lm[i].y);
	}

	#if DEBUG
		printf("BIKERS:\n");
		for ( i = 0 ; i < n ; i++ ) {
			printf("x : %lld , y : %lld\n" , ln[i].x , ln[i].y);
		}
		printf("BIKES:\n");
		for ( i = 0 ; i < m ; i++ ) {
			printf("x : %lld , y : %lld\n" , lm[i].x , lm[i].y);
		}
		printf("k = %lld\n" , k);
	#endif

	int index = 0;
	LLI * dn = (LLI *) malloc ( n * sizeof(LLI) );

	// For each bike get the closest biker
	for ( i = 0 ; i < m ; i++ ) {
		LLI distance = 0;
		LLI min_distance = LLONG_MAX;
		int index_cross = 0;
		int j = 0;
		for ( j = 0 ; j < n ; j++ ) {

			if ( ln[j].x == -1 )
				continue;

			distance = ((lm[i].x - ln[j].x) * ( lm[i].x - ln[j].x )) + ((lm[i].y - ln[j].y) * ( lm[i].y - ln[j].y ));
			if ( distance < min_distance ) {
				min_distance = distance;
				index_cross = j;
			}
		}
		dn[index++] = min_distance;
		ln[index_cross].x = -1;
		ln[index_cross].y = -1;
	}

	#if DEBUG
		printf("DISTANCES:\n");
		for ( i = 0 ; i < index ; i++ ) {
			printf("%lld\n" , dn[i]);
		}
	#endif
	qsort ( dn , index , sizeof(LLI) , compar_asc );
	printf("%lld\n" , dn[k-1]);
	

	return 0;
}
