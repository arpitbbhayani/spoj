/*
 * RemoveAdjectneDulicates.cpp
 *
 *  Created on: May 23, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

void remove_duplicates ( char * str , int n ) {

	stack<char> s1,s2;

	for ( int i = 0 ; i < n ; i++ ) {

		char ch = str[i];

		if ( !s2.empty() && s2.top() == ch ) {
		}
		else if ( !s1.empty() && s1.top() == ch ) {

			// remove from the s1 stack
			s1.pop();

			if ( s2.empty() || s2.top() != ch )
				s2.push(ch);
		}
		else {
			s1.push(ch);
		}

	}

	while ( !s1.empty() ) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;


}

int main ( int argc , char * argv[] ) {

	char str[1024];
	int n = 0;

	n = readline(str);
	remove_duplicates(str,n);

	cout << "NEW : " << str << endl;

	return 0;
}
