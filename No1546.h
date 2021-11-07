#pragma once
#include <iostream>
#include <vector>
using namespace std;
void solve1546(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		sum += arr[i];
	}

	double newAvr = (double)sum * 100 / (n * max);
	cout << fixed;
	cout.precision(2);
	cout << newAvr;
}