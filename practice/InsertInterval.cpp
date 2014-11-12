	#include <cstdio>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        if( intervals.size() == 0 ) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        stack<Interval> s;

        int i = 0;
        while( i < intervals.size() && intervals[i].start < newInterval.start ) {
            i++;
        }
        
        intervals.insert(intervals.begin() + i, newInterval );
        
		for( int i = 0 ; i < intervals.size(); i++ ) {
			cout << intervals[i].start << "," << intervals[i].end << endl;
		}
		cout << "---------------------" << endl;
        
        s.push(intervals[0]);
        for( i = 1 ; i < intervals.size(); i++ ) {
            Interval curr = intervals[i];
            Interval ons = s.top();
			
            if( curr.start > ons.end ) {
                s.push(curr);
            }
			else if ( curr.start >= ons.start && curr.start <= ons.end ) {
				if( curr.end > ons.end ) {
                    ons.end = curr.end;
					s.pop();
					s.push(ons);
                }
			}
        }
        
        intervals.clear();
        while( s.empty() == false ) {
            intervals.push_back(s.top());
            s.pop();
        }
        
        reverse(intervals.begin(), intervals.end());
        return intervals;
        
    }
	
	
	int main( int argc,char * argv[] ) {

		vector<Interval> a;
		a.push_back(Interval(2,5));
		a.push_back(Interval(6,7));
		a.push_back(Interval(8,9));
		
		vector<Interval> result = insert(a,Interval(0,1));
		
		for( int i = 0 ; i < result.size(); i++ ) {
			cout << result[i].start << "," << result[i].end << endl;
		}

	return 0;
}
