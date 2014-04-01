#include <cstdio>
#include <vector>
#include <map>
#define DEBUG 0

using namespace std;

int is_power (long long int x) {
	
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x&(x-1LL)));
}

int main() {

	map< long long int,vector<long long int> > m;
	long long int i;
	for ( i = 1 ; i <= 64 ; i++ ) {
		long long int n = i;
		long long int b = 1;
		while ( n != 0 ) {
			if ( n & 1 ) {
				m[b].push_back(i);
			}
			n = n >> 1;
			b++;
		}
	}

	long long int bitarray[8][65];
	for ( long long int i = 0 ; i < 8 ; i++ ) {
		for ( long long int j = 0 ; j < 65 ; j++ ) {
			bitarray[i][j] = 0;
		}
	}


	for ( map<long long int , vector<long long int> >::iterator itr = m.begin() ; itr != m.end() ; itr++ ) {
		long long int bitNumber = itr->first;
		vector<long long int> temp = itr->second;
		for ( long long int i = 0 ; i < temp.size() ; i++ ) {
			bitarray[bitNumber][temp[i]] = 1;
		}
	}

	long long int n;
	scanf("%lld",&n);
	while ( n != -1 ) {
		long long int b = 1;

		long long int array[65];
		long long int visited[65];

		for ( long long int i = 0 ; i < 65 ; i++ ) {
			array[i] = 0;
			visited[i] = -1;
		}

		// set each bit in an array of size 64 depending
		// on if it is set in number itself
		while ( n != 0 ) {
			array[b] = n & 1;
			b++;
			n = n >> 1;
		}

		for ( long long int j = 7 ; j >= 1 ; j-- ) {
			long long int bitNumber = j;
			vector<long long int> bits = m[j];
			long long int sum = 0;

			#if DEBUG
				printf("Parity bit number : %lld\n" , bitNumber);
				printf("\nFor the bits : \n");
				for ( long long int i = 0 ; i < bits.size() ; i++ ) {
					printf("%2lld " , bits[i]);
				}
				printf("\n");
			#endif

			for ( long long int i = 0 ; i < bits.size() ; i++ ) {
				sum += (array[bits[i]]);
			}

			#if DEBUG
				printf("Sum = %lld\n" , sum);
			#endif

			if ( sum & 1 ) {
				// error

				for ( long long int i = 0 ; i < 65 ; i++ ) {
					if ( visited[i] == 1 && bitarray[bitNumber][i] == 0 ) {
						visited[i] = 0;
					}
					else if ( visited[i] == 1 && bitarray[bitNumber][i] == 1 ) {
						visited[i] = 1;
					}
					else if ( visited[i] == -1 && bitarray[bitNumber][i] == 1 ) {
						visited[i] = 1;
					}
					else if ( visited[i] == -1 && bitarray[bitNumber][i] == 0 ) {
						visited[i] = 0;
					}
					else if ( visited[i] == 0 && bitarray[bitNumber][i] == 1) {
						visited[i] = 0;
					}
					else {
						visited[i] = 0;
					}
				}

			}
			else {
				// no error in bits
				for ( long long int i = 0 ; i < bits.size() ; i++ ) {
					visited[bits[i]] = 0;
				}
			}
			#if DEBUG
				printf("Visited:\n");
				for ( long long int i = 0 ; i <= b ; i++ ) {
					printf("%2lld " , i);
				}
				printf("\n");
				for ( long long int i = 0 ; i <= b ; i++ ) {
					printf("%2lld " , visited[i]);
				}
				printf("\n");
			#endif
                }

		long long int num = 0;
		for ( long long int i = 1 ; i < 65 ; i++ ) {
			if ( !is_power(i) && visited[i] == 1 ) {
				array[i] = 1 - array[i];
			}
		}

		char number[65];
		long long int index = 0;

		for ( long long int i = 64; i >= 1 ; i-- ) {
			if ( !is_power(i) )
				number[index++] = array[i] + '0';
		}
		number[index] = 0;

		long long int i = 0;
		for ( i = 0 ; i < 65 ; i++ ) {
			if ( number[i] != '0' )
				break;
		}

		#if DEBUG
			printf("String : ");
			for ( long long int j = i ; j < index ; j++ ) {
				printf("%c" , number[j]);
			}
			printf("\n");
		#endif

		num = 0;
		long long int bitset = 0;
		for ( index-- ; index >= i ; index-- ) {
			if ( number[index] == '1' ) {
				num = num * 2LL + 1;
			}
			else {
				num = num * 2LL + 0;
			}
			bitset++;
		}
		printf("%lld\n" , num);

		scanf("%lld",&n);
	}
	return 0;
}
