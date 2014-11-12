#include <cstdio>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

	vector<int> buffer;
    vector< vector<int> > ans;

    void print( vector<int> &array, int n, int k, int target, int index ) {
    
    	if( target < 0 ) {
    		return;
    	}
    
    	if( target == 0 ) {
    	    ans.push_back(buffer);
    		for(int i = 0 ; i < index ; i++ ) {
    			cout << buffer[i] << " ";
    		}
    		return;
    	}
    
    	for( int i = k ; i < n ; i++ ) {
    	    buffer.push_back(array[i]);
    		print(array,n, i,target-array[i],index+1);
    		buffer.pop_back();
    	}
    
    }

int main( int argc,char * argv[] ) {

	int array[4] = {2,3,6,7};
	int n= 4;

	int target = 7;

	vector<int> candidates;
	
	for( int i = 0 ; i  < n ; i++ ) {
		candidates.push_back(array[i]);
	}
	
	sort(candidates.begin(),candidates.end());
    print(candidates,candidates.size(),0,target,0);

	return 0;
}
