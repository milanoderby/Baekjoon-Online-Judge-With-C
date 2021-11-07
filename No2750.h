#pragma once
#include <iostream>
using namespace std;
void solve2750(void) {
	int N;
	cin >> N;

	const int SIZE = 1000;
	int arr[SIZE];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		int inx = i;
		for (int j = i + 1; j < N; j++) {
			if (arr[inx] > arr[j]) {
				int tmp = arr[inx];
				arr[inx] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}