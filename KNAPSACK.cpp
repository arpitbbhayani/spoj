#include <iostream>
#include <cstdio>
#include <algorithm>
#define BUF 4096

using namespace std;

char ibuf[BUF];
int ipt = BUF;
int readint() {
        while (ipt < BUF && ibuf[ipt] < '0') ipt++;
        if (ipt == BUF) {
                fread(ibuf, 1, BUF, stdin);
                ipt = 0;
                while (ipt < BUF && ibuf[ipt] < '0') ipt++;
        }
        int n = 0;
        while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
        if (ipt == BUF) {
                fread(ibuf, 1, BUF, stdin);
                ipt = 0;
                while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
        }
        return n;
}

int knapsack ( int s , int n , int size[] , int value[] ) {
	int k[n+1][s+1];

	for ( int i = 0 ; i < n+1 ; i++ ) {

		for ( int j = 0 ; j < s+1 ; j++ ) {

			if ( i == 0 || j == 0 ) {
				k[i][j] = 0;
			}
			else if ( size[i-1] <= j ) {

				k[i][j] = max( value[i-1]+k[i-1][j-size[i-1]] , k[i-1][j]);
			}
			else {
				k[i][j] = k[i-1][j];
			}
		}
	}
	return k[n][s];
}

int main( int argc , char * argv[] ) {

	int s , n;

	s = readint();
	n = readint();

	int size[n] , value[n];

	for( int i = 0 ; i < n ; i++ ) {
		size[i] = readint();
		value[i] = readint();
	}

	cout << knapsack ( s , n , size , value ) << endl;

	return 0;
}

