/*
 * amazon1.cpp
 *
 *  Created on: May 27, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

int array[1024];
int size = 0;

int parent(int n) {
	return (n - 1) / 2;
}

int left(int n) {
	return 2 * n + 1;
}

int right(int n) {
	return 2 * n + 2;
}

void insert(int val) {

	array[size++] = val;

	if (size == 1) {
		return;
	}

	int index = size - 1;
	while (array[parent(index)] < array[index]) {
		int t = array[parent(index)];
		array[parent(index)] = array[(index)];
		array[(index)] = t;

		index = parent(index);

		if (index == 0)
			break;
	}

}

int remove() {

	if (size == 0)
		return -1;

	int ret = array[0];
	array[0] = array[size - 1];
	size--;

	int index = 0;

	while (1) {

		if (index > size)
			break;

		if (left(index) < size && array[right(index)] < array[left(index)]) {

			if (array[index] > array[left(index)])
				break;

			int t = array[index];
			array[index] = array[left(index)];
			array[left(index)] = t;

			index = left(index);
		} else if (right(index) < size
				&& array[left(index)] < array[right(index)]) {

			if (array[index] > array[right(index)])
				break;

			int t = array[index];
			array[index] = array[right(index)];
			array[right(index)] = t;

			index = right(index);
		} else {
			break;
		}
	}

	return ret;

}

int kth_largest( int k ) {
	for ( int i = 0 ; i < k-1 ; i++ )
		remove();

	return remove();
}

int main(int argc, char * argv[]) {

	int a[10] = { 3, 2, 5, 4, 1, 6, 8, 7, 10, 9 };
	int n = 10;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		insert(a[i]);
		for (int j = 0; j < size; j++) {
			cout << array[j] << " ";
		}
		cout << endl;
	}

	cout << "5th largest : " << kth_largest(5) << endl;

	return 0;
}
