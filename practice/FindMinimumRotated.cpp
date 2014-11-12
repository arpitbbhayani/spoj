	#include <cstdio>
	#include <vector>
	#include <iostream>
	#include <algorithm>
	
	using namespace std;
	
	int findMin(vector<int> &num) {
        
        int n = num.size();
        
        if( n == 1 ) {
            return num[0];
        }
        
        int low = 0 , high = n-1;
        
        while ( low <= high ) {
            int mid = low + (high-low)/2;
            if( mid != n-1 && num[mid] > num[mid+1] ) {
                return num[mid + 1];
            }
            else if( mid != 0 && num[mid-1] > num[mid] ) {
                return num[mid];
            }
            else if (num[low] < num[mid] ) {
                low = mid + 1;
            }
            else {
				
                high = mid - 1;
            }
        }
        
		return num[0];
    }
	
	int main() {
		int a[] = {1,2};
		int n = sizeof(a) / sizeof(a[0]);
		
		vector<int> x;
		for(int i = 0 ; i < n ; i++ ) {
			x.push_back(a[i]);
		}
		cout << findMin(x) << endl;
		
	}