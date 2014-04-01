#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int bfs ( vector<int> * node , int n , int m ) {

	int visited[n];
	stack<int> s;

	for ( int i = 0 ; i < n ; i++ ) {
		visited[i] = -1;
	}

	for ( int i = 0 ; i < n ; i++ ) {

		if ( visited[i] != -1 )
			continue;

		s.push(i);
		visited[i] = 1;
		while ( !s.empty() ) {
			int parent = s.top();
			s.pop();

			for ( vector<int>::iterator itr = node[parent].begin() ; itr != node[parent].end() ; itr++ ) {
				int child = *itr;
				//cout << "Child " << child << " with gender = " << visited[child] << " and expected " << gender << endl;
				if ( visited[child] == -1 ) {
					visited[child] = ( visited[parent] == 1 ? 0 : 1 );
					s.push(child);
				}
				else if ( visited[child] == visited[parent] ) {
					return 1;
				}
			}
		}

	}

	return 0;
}

int main ( int argc , char * argv[] ) {

	int t;
	cin >> t;

	for ( int j = 1; j <= t ; j++ ) {
		int n , m;
		cin >> n >> m;
		n++;
		vector<int> node[n];
		int v = 0;

		for ( int i = 0 ; i < m ; i++ ) {
			int a,b;
			cin >> a >> b;
			if ( a == b )
				continue;
			node[a].push_back(b);
			node[b].push_back(a);

			/*if ( gender[a] == gender[b] && (gender[a] == 1 || gender[a] == 2 )) {
				//cout << "GAY\n";
				v = 1;
				break;
			}
			else if ( gender[a] == gender[b] ) {
				gender[a] = 1;
				gender[b] = 2;
			}
			else if ( gender[a] == 0 && gender[b] == 1 ) {
				gender[a] = 2;
			}
			else if ( gender[a] == 0 && gender[b] == 2 ) {
				gender[a] = 1;
			}
			else if ( gender[a] == 1 && gender[b] == 0 ) {
				gender[b] = 2;
			}
			else if ( gender[a] == 2 && gender[b] == 0 ) {
				gender[b] = 1;
			}
			*/

		}

		v = bfs( node , n , m );
		cout << "Scenario #" << j << endl;
		if ( v == 1 )
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;

		//int val = dfs( node , n , m );
		//cout << val << endl;
	}

	return 0;
}
