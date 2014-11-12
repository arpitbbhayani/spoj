#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

int jump(int A[], int n) {
            
            if( n == 0 || n == 1 ) {
                return 0;
            }
            
            int count = 0;
            
            for( int i = 0 ; i < n - 1 ; ) {
				cout << "i = " << i << endl;
                count++;                
                int jumpsize = A[i];
                
                // look for max in jumpsize elements ahead of i
                int m = INT_MIN;
                int mi = i;
                for( int j = 0 ; j < jumpsize; j++ ) {
                    if( i + j + 1 < n - 1 && i + j + 1 + A[i + j + 1] > m ) {
                        m = i + j + 1 + A[i + j + 1];
                        mi = i + j + 1;
                    }
					
					if( i + j + 1 >= n - 1) {
                        return count;
                    }
                }
                
                if( m == INT_MIN ) {
                    cout << "Not possible" << endl;
                    return -1;
                }
                else {
                    i = mi;
                }

            }
            
            return count;
            
        }
		
int main() {
	int A[] = {1,0,2};
	int n = sizeof(A) / sizeof(A[0]);
	
	cout << jump(A,n) << endl;
	return 0;
}