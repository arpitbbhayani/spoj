/*
 * amazon2.cpp
 *
 *  Created on: May 29, 2014
 *      Author: Arpit Bhayani
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define HASH_SIZE 16

int hash[16];

int main(int argc, char * argv[]) {

	int array[] = { 4, 5, 10, 3 };
	int n = 4;

	for (int i = 0; i < HASH_SIZE; i++)
		hash[i] = 0;

	for (int i = 0; i < n; i++) {
		hash[array[i] * array[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (hash[array[i] * array[i] + array[j] * array[j]] == 1) {
				cout << "FOUND : " << array[i] << " " << array[j] << endl;
			}
		}
	}

	return 0;
}
