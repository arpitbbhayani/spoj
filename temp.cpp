#include <string>
#include <cstdarg>
#include <utility>

#include <queue>
#include <stack>
#include <set>
#include <list>
#include <vector>
#include <queue>
#include <bitset>
#include <map>

#include <functional>
#include <sstream>
#include <algorithm>
#include <iostream>

#include <cstddef>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdio>

#include <stdexcept>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef signed long long s64;
typedef unsigned long long u64;
typedef pair<int, int> PII;

#define all(a) a.begin(),a.end()
#define out(x) cout<<#x<<" = "<<(x)<<endl;
#define out2(x,y) out(x) out(y)
#define out3(x,y,z) out(x) out(y) out(z)
#define fillchar(a,i) memset(a,i,sizeof(a));
#define fori(i,max) for(int i=0;i<(int)(max) ;(i)++)
#define for2i(i,min,max) for(int i=min;i<(int)(max) ;(i)++)
#define forv(i,a) fori(i,(int)(a.size()))
#define forv2(i,j,a) forv(i,a) forv(j,(a)[i])
#define forIter(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

long long MAX = 1000000007;

void multiply(long long F[2][2], long long M[2][2]);
void power(long long F[2][2], long long n);
long long fib(long long n);

long long fib(long long n) {
	long long F[2][2] = { { 1, 1 }, { 1, 0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}

void multiply(long long F[2][2], long long M[2][2]) {

	long long x = ((F[0][0] * M[0][0]) % MAX + (F[0][1] * M[1][0]) % MAX) % MAX;
	long long y = ((F[0][0] * M[0][1]) % MAX + (F[0][1] * M[1][1]) % MAX) % MAX;
	long long z = ((F[1][0] * M[0][0]) % MAX + (F[1][1] * M[1][0]) % MAX) % MAX;
	long long w = ((F[1][0] * M[0][1]) % MAX + (F[1][1] * M[1][1]) % MAX) % MAX;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;

}

void power(long long F[2][2], long long n) {
	if (n == 0 || n == 1)
		return;
	long long M[2][2] = { { 1, 1 }, { 1, 0 } };

	power(F, n / 2);
	multiply(F, F);

	if (n & 1)
		multiply(F, M);
}

int main() {
	int t;
	long long int n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n == 0)
			printf("0\n");
		else if (n == 1)
			printf("2\n");
		else
			printf("%lld\n", (fib(n + 3)) % MAX);
	}

	return 0;
}
