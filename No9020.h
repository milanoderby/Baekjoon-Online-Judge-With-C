#pragma once
#include <iostream>
#include <vector>
using namespace std;
void solve9020(void) {
	const int SIZE = 10001;
	const int sqrtSIZE = 100;

	int t;
	cin >> t;

	vector<int> arr(t);
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	int prime[SIZE] = { 0, };
	for (int i = 2; i <= sqrtSIZE; i++) {
		if (prime[i] == 0) {
			for (int j = i + 1; j < SIZE; j++) {
				if (prime[j] != 1 && j % i == 0) {
					prime[j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		for (int j = arr[i] / 2; j < arr[i]; j--) {
			if (prime[j] == 0 && prime[arr[i] - j] == 0) {
				cout << j << " " << arr[i] - j << "\n";
				break;
			}
		}
	}
}