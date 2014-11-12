#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int array[10][10];

void img(int n) {
	for( int i = 0 ; i < n-1 ; i++ ) {
		for( int j = i + 1 ; j < n ; j++ ) {
			int t = array[i][j];
			array[i][j] = array[j][i];
			array[j][i]  = t;
		}
	}
	
	int start = 0;
	int end = n-1;
	for( int j = 0 ; j < n/2 ; j++ ) {
		for( int i = 0 ; i < n ; i++ ) {
			int t = array[i][start];
			array[i][start] = array[i][end];
			array[i][end] = t;
		}
		start++;
		end--;
	}

}

int main( int argc, char * argv[] ) {

	int n;
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			cin >> array[i][j];
		}
	}
	
	img(n);

	for( int i = 0 ; i < n ; i++ ) {
		for(int j = 0 ; j < n ; j++ ) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}