/*
 * PLTGRP.cpp
 *
 *  Created on: Aug 10, 2014
 *      Author: Arpit Bhayani
 */

#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define DEBUG 0
#define gc getchar
#define ll long long

void scanint(ll int &x) {
    register ll int c = gc();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = gc());

    if(c=='-') {
    	neg = 1;
    	c = gc();
    }

    for(; c>47 && c<58 ; c = gc()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 100010
ll int array[ASIZE], lis[ASIZE];

ll int lisf( ll int * array , ll int n ) {

	for( int i = 0 ; i < n ; i++ )
		lis[i] = 1LL;

	for( ll int i = 1 ; i < n ; i++ ) {
		for( ll int j = 0 ; j < i ; j++ ) {
			if( array[i] >= array[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}

	ll int max = LLONG_MIN;

	for( int i = 0 ; i < n ; i++ )
		if( lis[i] > max )
			max = lis[i];

	return max;

}

int CeilIndex(int A[], int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }

    return r;
}

int LongestIncreasingSubsequenceLength(int A[], int size) {
    // Add boundary case, when array size is one

    int *tailTable   = new int[size];
    int len; // always points empty slot

    memset(tailTable, 0, sizeof(tailTable[0])*size);

    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }

    delete[] tailTable;

    return len;
}

int main ( int argc , char * argv[] ) {

	ll int n;
	scanf("%lld" , &n);
	for ( int i = 0 ; i < n ; i++ ) {
		scanint((array[i]));
	}

	cout << lisf(array,n) << endl;
	return 0;
}
