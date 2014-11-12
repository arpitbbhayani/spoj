	#include <cstdio>
	#include <vector>
	#include <iostream>
	#include <algorithm>
	
	using namespace std;
	
	vector<vector<int> > threeSum(vector<int> &num, int target) {
        
		int n = num.size();
		
        vector<int> temp;
        vector< vector<int> > ans;
        
        sort(num.begin(), num.end());
		
        for(int i = 0 ; i < (n - 3) ; i++ ) {
		
			if( i != 0 && num[i] == num[i-1] ) {
                continue;
            }
			
			for( int j = i+1 ; j < n-2 ; j++ ) {
			
				if( j != 1 && num[j] == num[j-1] ) {
					continue;
				}
			
			
				int k = j + 1, l = n - 1;
            
				while ( k < l ) {
				
					int sum = num[i] + num[j] + num[k] + num[l];
					
					if( sum == target ) {
						temp.clear();
						temp.push_back(num[i]);
						temp.push_back(num[j]);
						temp.push_back(num[k]);
						temp.push_back(num[l]);
						ans.push_back(temp);
						
						k++;
						l--;
						
						while( k < l && num[l] == num[l+1]) {
							l--;
						}
						
						while(k < l && num[k] == num[k-1] ) {
							k++;
						}
						
						
					}
					else if( sum < target ) {
						k++;
					}
					else {
						l--;
					}
				}
			}
        }
        
        /*for( int i = ans.size() - 1 ; i >= 0 ; i-- ) {
            
            for( int j = i - 1 ; j >= 0 ; j-- ) {
                
                if( ans[i][0] == ans[j][0] && ans[i][1] == ans[j][1] && ans[i][2] == ans[j][2] ) {
                    ans.erase(ans.begin() + j);
                }
                
            }
            
        }*/
        
        
        /*for( set< vector<int> >::iterator itr = s.begin() ; itr != s.end() ; itr++ ) {
            ans.push_back(*itr);
        }*/
        
        return ans;
    }
	
	
	int main() {
		int a[] = {0,0,0,0};
		int n = sizeof(a) / sizeof(a[0]);
		
		vector<int> x;
		for(int i = 0 ; i < n ; i++ ) {
			x.push_back(a[i]);
		}
		vector< vector<int> > ans = threeSum(x,0);
		
		for( int i = 0 ; i < ans.size() ; i++ ) {
			cout << ans[i][0] << " - " << ans[i][1] << " - " << ans[i][2] << " - " << ans[i][3] << endl;
		}
		
	}