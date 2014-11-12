//https://www.hackerrank.com/challenges/insertion-sort

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


long long int merge( int *Arr, int start, int mid, int end){


	int firstHalfSize = mid - start + 1, i, j, k;
	long long int cost = 0;

	int A[firstHalfSize];


	for(i = 0; i < firstHalfSize; i++)
		A[i] = Arr[start + i];


	i = 0;
	j = mid + 1;
	k = start;

	while( i < firstHalfSize && j <= end){

		
		if( A[i] <= Arr[j] ){

			Arr[k] = A[i];
			i++;		
		}
		else{

			Arr[k] = Arr[j];
			j++;
			cost = cost + firstHalfSize - i;

		}

		k++;

	} 


	while( i < firstHalfSize){


		Arr[k] = A[i];
		i++;		
		k++;
	
	}		
	

	return cost;
}


long long int mergeSort(int *Arr , int start, int end){


	if( start >= end)
		return 0;

	int mid = (start + end) / 2;
	long long int  cost1 , cost2, cost;

	cost1 = mergeSort( Arr,  start , mid);
	cost2 = mergeSort( Arr,  mid + 1, end);

	cost = merge( Arr, start, mid , end);

	return  cost + cost1 + cost2; 
	
}


int main(){

	int testCases, N;
	
	scanf("%d", &testCases);

	while( testCases-- ){


			scanf("%d", &N);

			int Arr[N];

			for(int i = 0; i < N; i++)
				scanf("%d", Arr + i);

			
		       printf("%lld\n", mergeSort(Arr, 0, N - 1));


	}

	return 0;
}
