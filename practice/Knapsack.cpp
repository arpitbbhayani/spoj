#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int **dp;

int k( int weight[], int value[], int n, int knapsack_capacity ) {

	if( dp[knapsack_capacity][n] != -1 ) {
		return dp[knapsack_capacity][n];
	}

	if( n == 0 || knapsack_capacity == 0 ) {
		dp[knapsack_capacity][n] = 0;
		return 0;
	}
	
	if( weight[n-1] > knapsack_capacity ) {
		return k(weight, value, n-1, knapsack_capacity); // same as valexcl
	}

	int valincl = value[n-1] + k(weight,value, n-1, knapsack_capacity-weight[n-1]);
	int valexcl = k(weight,value,n-1,knapsack_capacity);

	dp[knapsack_capacity][n] = max(valincl, valexcl);
	return max(valincl, valexcl);
}

int main() {
	int weight[] = {10,20,30};
	int value[] = {60,100,120};
	
	int knapsack_capacity = 50;
	int n = sizeof(weight)/sizeof(weight[0]);
	
	dp = (int **) malloc(sizeof(int *) * (knapsack_capacity+1));
	for( int i = 0 ; i < knapsack_capacity+1 ; i++ ) {
		dp[i] = (int *) malloc(sizeof(int) * (n+1));
	}
	
	for( int i = 0 ; i < knapsack_capacity+1 ; i++ ) {
		for( int j = 0 ; j < n+1; j++ ) {
			dp[i][j] = -1;
		}
	}
	
	k(weight,value,n,knapsack_capacity);
	
	cout << dp[knapsack_capacity][n] << endl;
	

}