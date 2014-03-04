#include <cstdio>
#include <cstdlib>
#include <vector>

#define DEBUG 1
#define INT_MAX 100000

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

int main ( int argc , char * argv[] ) {

	int array[101][101];
	int time[101][101];

	vector<int> edgesx[101][101];
	vector<int> edgesy[101][101];

	int pre[101][101][2];

	int t , z;
	scanf("%d" , &t);
	for ( z = 1 ; z <= t ; z++ ) {

		int i , j;
		int r , c;
		scanf("%d%d" , &r , &c);

		for ( i = 0 ; i < r ; i++ ) {
			for ( j = 0 ; j < c ; j++ ) {
				scanf("%d" , &array[i][j]);
				edgesx[i][j].clear();
				edgesy[i][j].clear();
			}
		}

		int x,y,ti;
		scanf("%d%d%d" , &x , &y , &ti);
		x--; y--;

		for ( i = 0 ; i < r ; i++ ) {
			for ( j = 0 ; j < c ; j++ ) {
				time[i][j] = INT_MAX;
			}
		}

		time[0][0] = 0;

		for ( i = 0 ; i < r ; i++ ) {
			for ( j = 0 ; j < c ; j++ ) {

				//printf("For (%d,%d)\n" , i , j);

				if ( i+1 < r ) {
					edgesx[i][j].push_back(i+1);
					edgesy[i][j].push_back(j);
					//printf("adding (%d,%d)\n" , i+1,j);
				}
	
				if ( i-1 >= 0 ) {
					edgesx[i][j].push_back(i-1);
					edgesy[i][j].push_back(j);
					//printf("adding (%d,%d)\n" , i-1,j);
				}

				if ( j+1 < c ) {
					edgesx[i][j].push_back(i);
					edgesy[i][j].push_back(j+1);
					//printf("adding (%d,%d)\n" , i,j+1);
				}

				if ( j - 1 >= 0 ) {
					edgesx[i][j].push_back(i);
					edgesy[i][j].push_back(j-1);
					//printf("adding (%d,%d)\n" , i,j-1);
				}

			}
		}

                        /*for ( i = 0 ; i < r ; i++ ) {
                                for ( j = 0 ; j < c ; j++ ) {
					printf("(%d,%d) :" , i , j);
                                        for ( int l = 0 ; l < edgesx[i][j].size() ; l++ ) {
                                                int x1 = edgesx[i][j][l];
                                                int y1 = edgesy[i][j][l];
						printf(" (%d,%d)" , x1,y1);
                                        }
					printf("\n");
                                }
                   	}*/

		int k = 0;
		for ( k = 0 ; k < (r*c)-1 ; k++ ) {
			for ( i = 0 ; i < r ; i++ ) {
				for ( j = 0 ; j < c ; j++ ) {
					for ( int l = 0 ; l < edgesx[i][j].size() ; l++ ) {
						int x1 = edgesx[i][j][l];
						int y1 = edgesy[i][j][l];
						if ( time[i][j] + array[i][j]  < time[x1][y1] ) {
							time[x1][y1] = time[i][j] + array[i][j];
							pre[i][j][0] = x1;
							pre[i][j][1] = y1;
						}
					}
				}
			}
		}

		int TIME = array[0][0];
		int tx = 0 , ty = 0;
		while ( tx != x || ty != y ) {
			int tx1 = pre[tx][ty][0];
			int ty1 = pre[tx][ty][1];
			TIME += array[tx1][ty1];
			tx = tx1; ty = ty1;
		}

		/*printf("PRE\n");
		for ( i = 0 ; i < r ; i++ ) {
			for ( j = 0 ; j < c ; j++ ) {
				printf("(%d,%d) " , pre[i][j][0] , pre[i][j][1]);
			}
			printf("\n");
		}

		time[x][y] += array[0][0];
		time[x][y] -= array[x][y];

		printf("TIME[FINAL] = %d and ti = %d\n" , time[x][y] , ti);

		int TIME = time[x][y];
		*/

		if ( ti >= TIME )
			printf("YES\n%d\n" , (ti-TIME));
		else
			printf("NO\n");
		
	}
	return 0;
}
