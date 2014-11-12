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

<<<<<<< HEAD
int readline(char * str) {

	int i = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
=======
int readline ( char * str ) {

	int i = 0;
	char ch;
	while ( (ch=getchar()) != '\n' ) {
>>>>>>> 68bc66457c165b965488ce4bb54002e1e3445980
		str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

<<<<<<< HEAD
void remove_duplicates(char * str, int n) {

	/**
	 * Stack s1 has the answer
	 * and Stack2 saves the character that was removed last.
	 */

	stack<char> s1, s2;

	for (int i = 0; i < n; i++) {

		char ch = str[i];

		if (!s2.empty() && s2.top() == ch) {

			// do nothing

		} else if (!s1.empty() && s1.top() == ch) {
=======
void remove_duplicates ( char * str , int n ) {

	stack<char> s1,s2;

	for ( int i = 0 ; i < n ; i++ ) {

		char ch = str[i];

		if ( !s2.empty() && s2.top() == ch ) {
		}
		else if ( !s1.empty() && s1.top() == ch ) {
>>>>>>> 68bc66457c165b965488ce4bb54002e1e3445980

			// remove from the s1 stack
			s1.pop();

<<<<<<< HEAD
			if (s2.empty() || s2.top() != ch)
				s2.push(ch);
		} else {
=======
			if ( s2.empty() || s2.top() != ch )
				s2.push(ch);
		}
		else {
>>>>>>> 68bc66457c165b965488ce4bb54002e1e3445980
			s1.push(ch);
		}

	}

<<<<<<< HEAD
	while (!s1.empty()) {
=======
	while ( !s1.empty() ) {
>>>>>>> 68bc66457c165b965488ce4bb54002e1e3445980
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;

<<<<<<< HEAD
}

int main(int argc, char * argv[]) {
=======

}

int main ( int argc , char * argv[] ) {
>>>>>>> 68bc66457c165b965488ce4bb54002e1e3445980

	char str[1024];
	int n = 0;

	n = readline(str);
<<<<<<< HEAD
	remove_duplicates(str, n);
=======
	remove_duplicates(str,n);
>>>>>>> 68bc66457c165b965488ce4bb54002e1e3445980

	cout << "NEW : " << str << endl;

	return 0;
}
