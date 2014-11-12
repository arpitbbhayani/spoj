#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

char array[310][310];
int visited[310][310];
int countarray[310][310];

int nx[8] = {-1,-1,-1, 0,0,1,1,1};
int ny[8] = {-1,0 ,1 ,-1,1,-1,0,1};

int issafe(int x, int y, int n) {
	if( x >= 0 && x < n && y >= 0 && y < n ) {
		return 1;
	}
	return 0;
}

int ismineahead(int i,int j, int n) {

	if( array[i][j] == '*' ) {
		visited[i][j] = 1;
		return 9;
	}

	int count = 0;
	for( int k = 0 ; k < 8 ; k++ ) {
		int newx = i + nx[k];
		int newy = j + ny[k];
		if( issafe(newx,newy,n) && array[newx][newy] == '*' ) {
			count++;
		}
	}
	return count;
}

void dfs( int i , int j, int n ) {

	if( countarray[i][j] == 0 ) {
		for( int k = 0 ; k < 8 ; k++ ) {
			int newx = i + nx[k];
			int newy = j + ny[k];			
			if( issafe(newx,newy,n) && visited[newx][newy] == 0 ) {
				//cout << "Marking : newx = " << newx << " and newy = " << newy << endl;
				visited[newx][newy] = 1;
				if(countarray[newx][newy] == 0) {
					dfs(newx,newy,n);
				}
			}
		}
	}
}

int count ( int n ) {
	int c = 0;
	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 0 ; j < n ; j++ ) {
			if( countarray[i][j] == 0 && visited[i][j] == 0) {
				c++;
				visited[i][j] = 1;
				dfs(i,j,n);
			}
		}
	}
	
	for( int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			if( visited[i][j] == 0 ) {
				c++;
			}
		}
	}
	
	return c;
}

int main() {
	int t, x = 1;
	scanf("%d" , &t);
	
	while( t-- ) {
		int n;
		scanf("%d" , &n);
		for( int i = 0 ; i < n ; i++ ) {
			scanf("%s" , array[i]);
			for( int j = 0 ; j < n ;j++ ) {
				visited[i][j] = 0;
				countarray[i][j] = 0;
			}
		}
		
		for( int i = 0 ; i < n ; i++ ) {
			for(int j = 0 ; j < n ; j++ ) {
				countarray[i][j] = ismineahead(i,j,n);
			}
		}

		printf("Case #%d: %d\n", x++,count(n));
	}
}