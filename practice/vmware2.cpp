/*
 * vmware2.cpp
 *
 *  Created on: May 26, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define DEBUG 0

// store max heap
int array[1024];
int size = 0;

int parent(int n) {
	return (n - 1) / 2;
}

void adjust_insert() {

	if (size == 1)
		return;

	int index = size - 1;

	while (array[parent(index)] < array[index]) {

		int t = array[parent(index)];
		array[parent(index)] = array[index];
		array[index] = t;

		index = parent(index);
		if (index == 0)
			break;
	}

}

int left(int n) {
	return 2 * n + 1;
}

int right(int n) {
	return 2 * n + 2;
}

int remove() {

	if (size == 0) {
		return -1;
	}

	size--;
	int ret = array[0];

	array[0] = array[size];

	int index = 0;

	while (1) {

		if (left(index) < size && array[left(index)] > array[right(index)]) {
			if (array[left(index)] > array[(index)]) {

				int t = array[left(index)];
				array[left(index)] = array[(index)];
				array[(index)] = t;

				index = left(index);

			} else {
				break;
			}
		} else if (right(index) < size
				&& array[right(index)] > array[left(index)]) {
			if (array[right(index)] > array[(index)]) {

				int t = array[right(index)];
				array[right(index)] = array[(index)];
				array[(index)] = t;

				index = right(index);

			} else {
				break;
			}
		} else {
			break;
		}

	}

	return ret;

}

void insert(int val) {
	array[size] = val;
	size++;

	adjust_insert();
}

int main(int argc, char * argv[]) {

	int input;
	int a[] = { 3, 2, 1, 5, 4, 8, 6, 7, 9, 10 };
	int n = 10;

	for (int i = 0; i < n; i++) {
		insert(a[i]);
	}

	for (int i = 0; i < 5; i++) {
		cout << "Value removed : " << remove() << endl;
	}
	cout << endl;

}
