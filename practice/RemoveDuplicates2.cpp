	#include <cstdio>
	#include <vector>
	#include <iostream>
	#include <algorithm>
	
	using namespace std;
	
	int removeDuplicates(int A[], int n) {
        
        int count = 1;
        int last = A[0];
        int index = 1;
        
        for( int i = 1 ; i < n ; i++ ) {
            
            if( A[i] == last && count == 1 ) {
                A[index++] = A[i];
                count++;
            }
            else if( A[i] == last ) {
                
            }
            else {
                count = 1;
                last = A[i];
            }
            
        }
        return index;
    }
	
	int main() {
		int a[] = {0};
		int n = sizeof(a) / sizeof(a[0]);
		
		int l = removeDuplicates(a,n);
		
		for( int i = 0 ; i < l ; i++ ) {
			cout << a[i] << " ";
		}
		cout << endl;
		
	}