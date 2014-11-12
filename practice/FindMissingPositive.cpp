#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int f( int * A , int n ) {
        
		for( int i = 0 ; i < n ; i++ ) {
			cout << A[i] << " ";
		}
		cout << endl;
		
        for( int i = 0 ; i < n ; i++ ) {
            int index = abs(A[i]) - 1;
			cout << "For : index = " << index << endl;
            if( index >= 0 && index < n && A[index] > 0 ) {
				cout << "Marrking : index = " << index << " as negative" << endl;
                A[index] *= -1;
            }
        }
		
		for( int i = 0 ; i < n ; i++ ) {
			cout << A[i] << " ";
		}
		cout << endl;
        
        int i = 0;
        for( ; i < n ; i++ ) {
            if( A[i] > 0 ) {
                return i + 1;
            }
        }
        
        return n + 1;
    }

    int firstMissingPositive(int A[], int n) {
        
        int index = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if( A[i] <= 0 ) {
                int t = A[i];
                A[i] = A[index];
                A[index] = t;
                index++;
            }
        }
        //cout << "Index = " << index << " and a[index] = " << A[index] << endl;
        return f(&A[index], n - index);
        
    }
	
	int main( int argc, char * argv[] ) {
	int A[] = {3,4,-1,1};
	int n = sizeof(A)/ sizeof(A[0]);
	
	cout << firstMissingPositive(A,n) << endl;
	return 0;
}