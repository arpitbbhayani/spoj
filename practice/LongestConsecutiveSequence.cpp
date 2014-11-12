#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int l( int A[] , int n ) {
	map<int,int> m;
	for( int i = 0 ; i < n ; i++ ) {
		m[A[i]] = 1;
	}
	
	for( map<int,int>::iterator itr = m.begin(); itr != m.end(); itr++ ) {
		int a = itr->first;
		if( m.find(a-1) != m.end() ) {
			itr->second = m[a-1] + 1;
		}
	}
	
	int m1 = INT_MIN;
	for( map<int,int>::iterator itr = m.begin(); itr != m.end(); itr++ ) {
		m1 = max(m1,itr->second);
	}
	
	return m1;
}

int main( int argc, char * argv[] ) {
	int A[] = {4,98,3,99,100,1,2};
	int n = sizeof(A)/ sizeof(A[0]);
	
	cout << l(A,n) << endl;
	return 0;
}