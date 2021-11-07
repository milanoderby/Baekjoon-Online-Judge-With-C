#pragma once
#include <iostream>
using namespace std;
void solve2581(void) {
	int m, n;
	cin >> m >> n;

	int arr[10001] = { 0, };
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i <= 100; i++) {
		if (arr[i] == 0) {
			for (int j = i + 1; j <= 10000; j++) {
				if (j % i == 0) {
					arr[j] = 1;
				}
			}
		}
	}

	int min = -1;
	int sum = 0;
	for (int i = n; i >= m; i--) {
		if (arr[i] == 0) {
			min = i;
			sum += i;
		}
	}

	if (sum == 0) {
		cout << min;
	}
	else {
		cout << sum << "\n" << min;
	}
}