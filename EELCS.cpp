#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(const string& a, const string& b) {
  int A = a.size(), B = b.size();
  int L[2][B + 1];
  for (int i = 0; i <= 1; ++i) L[i][0] = 0;
  for (int i = 0; i <= B; ++i) L[0][i] = 0;
  for (int i = 1; i <= A; ++i) {
    int this_i = i % 2, pre_i = this_i ? 0 : 1;
    for (int j = 1; j <= B; ++j) {
      if (a[i - 1] == b[j - 1]) L[this_i][j] = 1 + L[pre_i][j - 1];
      else L[this_i][j] = max(L[pre_i][j], L[this_i][j - 1]);
    }
  }
  return max(L[0][B], L[1][B]);
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << longestCommonSubsequence(a, b) << endl;
}

