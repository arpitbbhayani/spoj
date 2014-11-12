#include <map>
#include <cmath>
#include <set>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>

using namespace std;

class Solution {

	int ** hash;
	int ** palin;

	int _pp(const char * str, int i, int j) {

		if (i == j) {
			palin[i][j] = 1;
			hash[i][j] = 0;
			return 0;
		}

		if (hash[i][j] != -1) {
			return hash[i][j];
		}

		if (i == j - 1) {
			palin[i][j] = (str[i] == str[j]);
		} else {
			palin[i][j] = (str[i] == str[j]) && palin[i + 1][j - 1];
		}

		if (palin[i][j] == 1) {
			hash[i][j] = 0;
			return 0;
		}

		int result = INT_MAX;
		for (int k = i; k < j; k++) {
			int temp = _pp(str, i, k) + _pp(str, k + 1, j) + 1;
			result = min(result, temp);
		}

		hash[i][j] = result;
		return result;
	}

	int pp(const char * str, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				hash[i][j] = -1;
				palin[i][j] = 0;
			}
		}
		return _pp(str, 0, n - 1);
	}

public:
	int minCut(string s) {
		const char * str = s.c_str();

		int n = s.length();
		hash = (int **) malloc(sizeof(int *) * n);
		palin = (int **) malloc(sizeof(int *) * n);

		for (int i = 0; i < n; i++) {
			hash[i] = (int *) malloc(sizeof(int) * n);
			palin[i] = (int *) malloc(sizeof(int) * n);
		}

		return pp(str, s.length());

	}
};
