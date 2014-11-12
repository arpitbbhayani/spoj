/*
 * UCV2013H.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG 0

int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int array[256][256];
int d[256][256];

int main(int argc, char * argv[]) {

	int n, m;
	scanf("%d%d", &n, &m);

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &array[i][j]);
				d[i][j] = -1;
			}
		}

		/*for (int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
		 cout << array[i][j] << " ";
		 }
		 cout << endl;
		 }
		 cout << endl;
		 */

		int count = 1;

		if (array[0][0] == 1) {
			d[0][0] = count;
			count++;
		}

		for (int i = 1; i < n; i++) {
			if (array[0][i] == 1) {
				if (d[0][i - 1] == -1) {
					d[0][i] = count;
					count++;
				} else {
					d[0][i] = d[0][i - 1];
				}
			}
		}

		for (int i = 1; i < n; i++) {
			if (array[i][0] == 1) {
				if (d[i - 1][0] == -1) {
					d[i][0] = count;
					count++;
				} else {
					d[i][0] = d[i - 1][0];
				}
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {

				if (array[i][j] == 1) {
					d[i][j] = max(d[i - 1][j], d[i][j - 1]);
					if (d[i][j] == -1) {
						d[i][j] = count;
						count++;
					}
				}

			}
		}

		map<int, int> countmap, finalmap;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << d[i][j] << " ";
				if (d[i][j] != -1)
					countmap[d[i][j]]++;
			}
		}

		for (map<int, int>::iterator itr = countmap.begin();
				itr != countmap.end(); itr++) {
			finalmap[itr->second]++;
			//cout << itr->first << " " << itr->second << endl;
		}

		vector<int> temp;

		cout << count - 1 << endl;
		for (map<int, int>::iterator itr = finalmap.begin();
				itr != finalmap.end(); itr++) {
			//cout << itr->first << " " << itr->second << endl;
			temp.push_back(itr->first);
		}

		sort(temp.begin(),temp.end());

		for ( vector<int>::iterator itr = temp.begin(); itr != temp.end() ; itr++ ) {
			cout << *itr << " " << finalmap[*itr] << endl;
		}

		scanf("%d%d", &n, &m);

		if ( n == 0 && m == 0 )
			break;

	}
	return 0;
}
