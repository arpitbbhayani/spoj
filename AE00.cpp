#include <iostream>
#include <cmath>

using namespace std;

int main( int argc , char * argv[] ) {

	int a,d;
	long int count = 0;
	float b,c;

	cin >> a;
	b=a;

	c=sqrt(b);
	d=c;

	for( int i=1 ; i <= d ; i++ )
		count = count + ( (a/i) - (d-i) );
	
	cout << count << endl;
	return 0;
}
