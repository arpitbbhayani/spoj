#include <iostream>
#include <queue>
#include <list>
#include <cstdio>
using namespace std;

int main ( int argc , char * argv[] ) {

	int t;

	list<int> node[61];

	int m[61][61];

	cin >> t;

	getchar();

	while ( t-- ) {

		char ch;

		int n = 0;

		node[0].clear();
		while ( (ch = getchar()) != '\n' ) {
			n++;
			if ( ch == 'Y' ) {
				node[0].push_back(n-1);
				m[0][n-1] = 1;
			}
			else {
				m[0][n-1] = 0;
			}
		}

		for ( int i = 1 ; i < n ; i++ ) {
			node[i].clear();
			n = 0;
			while ( (ch = getchar()) != '\n' ) {
				n++;
				if ( ch == 'Y' ) {
					node[i].push_back(n-1);
					m[i][n-1] = 1;
				}
				else {
					m[i][n-1] = 0;
				}
			}
		}

		/*cout << "-----------------------------------------------------------" << endl;
		for ( int i = 0 ; i < n ; i++ ) {

			cout << "Node : " << i << " -> ";
			for ( list<int>::iterator itr = node[i].begin() ; itr != node[i].end() ; itr++ ) {
				cout << *itr << " ";
			}
			cout << endl;
			
		}
		*/
		
		int max_count = 0 , max_n = 0;
		for ( int i = 0 ; i < n ; i++ ) {

			int count = 0;
			for ( list<int>::iterator itr = node[i].begin() ; itr != node[i].end() ; itr++ ) {
				int child = *itr;
				for ( list<int>::iterator itr_c = node[child].begin() ; itr_c != node[child].end() ; itr_c++ ) {
					if ( *itr_c != i && m[*itr_c][i] == 0 ) {
						count ++;
						//cout << "Adding count for grand_child = " << *itr_c << " and parent = " << i << endl;
					}
				}
			}

			if ( count > max_count ) {
				max_count = count;
				max_n = i;
			}

		}
		cout << max_n << " " << max_count << endl;


	}

	return 0;

}
