	#include <cstdio>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
	
	vector<int> spiralOrder(int matrix[][2], int row, int col) {
        
        vector<int> result;
        
        if( row == 0 ) {
            return result;
        }
        
        if( row == 0 && col == 0 ) {
            return result;
        }
        
        if( row == 1 && col == 1 ) {
            result.push_back(matrix[0][0]);
            return result;
        }
        
        int left = 0, right = col;
        int top = 0, bottom = row;
        
        
        while(top < bottom && left < right) {
            
			cout << "left = " << left << " right = " << right << " top = " << top << " bottom = " << bottom << endl;
			if( top < bottom ) {
				for( int i = left; i < right ; i++ ) {
					//result.push_back(matrix[top][i]);
					cout << "1 : " << matrix[top][i] << endl;
				}
				top++;
			}

			cout << "left = " << left << " right = " << right << " top = " << top << " bottom = " << bottom << endl;
			if( left < right ) {
				for( int i = top; i < bottom; i++) {
					//result.push_back(matrix[i][right-1]);
					cout << "2 : " << matrix[i][right-1] << endl;
				}
				right--;
			}
            
			cout << "left = " << left << " right = " << right << " top = " << top << " bottom = " << bottom << endl;
            if( top < bottom ) {
                for( int i = right - 1; i >= left ; i-- ) {
                    //result.push_back(matrix[bottom-1][i]);
					cout << "3 : " << matrix[bottom-1][i] << endl;
                }
                bottom--;
            }
            
			cout << "left = " << left << " right = " << right << " top = " << top << " bottom = " << bottom << endl;
            if( left < right ) {
                for( int i = bottom - 1 ; i >= top ; i-- ) {
					cout << "4 : " << matrix[i][left] << endl;
                    //result.push_back(matrix[i][left]);
                }
                left++;
            }
            
        }
        
        return result;
        
    }
	
	int main( int argc,char * argv[] ) {

	int array[][2] = {{1,11},{2,12},{3,13}};
	int row = 3;
	int col = 2;

	vector<int> out = spiralOrder(array,row,col);
	
	for( int i = 0 ; i < out.size(); i++ ) {
		cout << out[i] << " ";
	}
	cout << endl;
	
	return 0;
}
