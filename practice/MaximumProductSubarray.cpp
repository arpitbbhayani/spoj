class Solution {
public:

    vector<int> zeroindex;
    int numn = 0 , nump = 0, numz = 0;
    
    int maxproductwithoutzero( int A[], int start, int end ) {
        
        if( start > end ) {
            return 0;
        }
        
        if( start == end ) {
            return A[start];
        }
        
        int nn = 0, np = 0;
        
        for( int i = start; i <= end; i++ ) {
            if( A[i] < 0 ) {
                nn++;
            }
            else {
                np++;
            }
        }
        
        if( nn % 2 == 0 ) {
            int result = 1;
            for( int i = start; i <= end; i++ ) {
                result *= A[i];
            }
            return result;
        }
        
        // number of negatives are odd
        
        if( nn == 1 ) {
            int templ = 1, temph = 1;
            int l = start, h = end;
            while(A[l] > 0) {
                templ *= A[l];
                l++;
            }
            
            while(A[h] > 0) {
                temph *= A[h];
                h--;
            }
            
            return max(templ, temph);
        }
        else {
            
            int templ = 1, temph = 1;
            int l = start, h = end;
            while(A[l] > 0) {
                templ *= A[l];
                l++;
            }
            templ *= A[l];
            
            while(A[h] > 0) {
                temph *= A[h];
                h--;
            }
            temph *= A[h];
            
            //cout << "templ = " << templ << " and temph = " << temph << " l = " << l << " and h = " << h << endl; 
            
            if(abs(templ) > abs(temph)) {
                l++;
                while(l < h) {
                    templ *= A[l];
                    l++;
                }
                return templ;
            }
            else {
                h--;
                while(l < h) {
                    temph *= A[h];
                    h--;
                }
                return temph;
            }
            
        }
        
    }

    int maxProduct(int A[], int n) {
        
        if( n == 1 ){
            return A[0];
        }
        
        for( int i = 0 ; i < n ;i++ ) {
            if( A[i] < 0 ) numn++;
            if( A[i] > 0 ) nump++;
            if( A[i] == 0 ) {
                zeroindex.push_back(i);
                numz++;
            }
        }
        
        if( numz == 0 ) {
            return maxproductwithoutzero(A,0,n-1);
        }
        else {
            
            int result = 0;
            
            int start = 0, end = 0;
            for( int i = 0 ; i < zeroindex.size() ; i++ ) {
                end = zeroindex[i] - 1;
                result = max(result,maxproductwithoutzero(A,start,end));
                start = zeroindex[i] + 1;
            }
            end = n-1;
            result = max(result,maxproductwithoutzero(A,start,end));
            
            return result;
        }
        
    }
};