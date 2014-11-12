#include <cstdio>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

set< vector<int> > s;
vector<int> buffer;
vector< vector<int> > ans;

void print( vector<int> &candidates, int n, int k, int target ) {

	if( target < 0 ) {
		return;
	}

	if( target == 0 ) {
		s.push_back(buffer);
		//for( int i = 0 ; i  < buffer.size() ; i++ ) {
		//	cout << buffer[i] << " ";
		//}
		//cout << endl;
		return;
	}
	
	for( int i = k ; i < n ; i++ ) {
		buffer.push_back(candidates[i]);
		print(candidates, n, i+1, target - candidates[i]);
		buffer.pop_back();
	}
}

int main( int argc,char * argv[] ) {

	int target = 8;
	int array[] = {10,1,2,7,6,1,5};
	int n= sizeof(array)/sizeof(array[0]);

	vector<int> candidates;
	
	for( int i = 0 ; i  < n ; i++ ) {
		candidates.push_back(array[i]);
	}
	
	sort(candidates.begin(),candidates.end());
    print(candidates,n,0,target);
	
	for( set< vector<int> >::iterator itr = s.begin() ; itr != s.end() ; itr++ ) {
		ans.push_back(*itr);
	}

	return 0;
}
