/*
 * StrRevRec.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: Arpit Bhayani
 */

#include <stdio.h>
#include <stdlib.h>


#define si(x) scanf("%d" , &x)
#define sl(x) scanf("%ld" , &x)
#define sll(x) scanf("%lld" , &x)
#define sc(x) scanf("%c" , &x)
#define ss(x) scanf("%s" , &x)

#define pi(x) printf("%d\n" , x)
#define pl(x) printf("%ld\n" , x)
#define pll(x) printf("%lld\n" , x)
#define pc(x) printf("%c\n" , x)
#define ps(x) printf("%s\n" , x)

#define fup(i,a,b) for(int i=a;i<b;i++)
#define fdn(i,a,b) for(int i=a;i>=b;i--)

#define DEBUG 0
#define gc getchar
#define ll long long

#define SEPERATOR " : "

#define trace1(a) cout << #a << SEPERATOR << a << endl;
#define trace2(a,b) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << endl;
#define trace3(a,b,c) cout << #a << SEPERATOR << a << SEPERATOR << #b << SEPERATOR << b << #c << SEPERATOR << c << endl;

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

#define ASIZE 10

int strlenrec( char * str ) {

	if( *str == '\0' ) {
		return 0;
	}

	return strlenrec(str + 1) + 1;
}

int main ( int argc , char * argv[] ) {

	printf("%d\n", strlenrec("arpit"));
	printf("%d\n", strlenrec("bhayani"));
	printf("%d\n", strlenrec("is"));
	printf("%d\n", strlenrec("a"));
	printf("%d\n", strlenrec("good"));
	printf("%d\n", strlenrec("boy"));

	return 0;
}
