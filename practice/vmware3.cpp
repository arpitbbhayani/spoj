/*
 * vmware3.cpp
 *
 *  Created on: May 17, 2014
 *      Author: Arpit Bhayani
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

#define DEBUG 0

using namespace std;

class QueueUsingStack {
private:
	stack<int> a;
public:
	int queue_pop();
	void queue_push( int val );
};

void QueueUsingStack::queue_push( int val ) {
	this->a.push(val);
}

int QueueUsingStack::queue_pop() {

	int val = -1;
	stack<int> a_temp;

	while ( !a.empty() ) {
		a_temp.push(a.top());
		a.pop();
	}
	val = a_temp.top();

	a_temp.pop();

	while ( !a_temp.empty() ) {
		a.push(a_temp.top());
		a_temp.pop();
	}

	return val;
}

int main ( int argc , char * argv[] ) {

	QueueUsingStack q;

	q.queue_push(10);
	cout << q.queue_pop() << endl;
	q.queue_push(40);
	q.queue_push(20);
	q.queue_push(30);

	cout << q.queue_pop() << endl;
	cout << q.queue_pop() << endl;
	cout << q.queue_pop() << endl;

	return 0;
}
