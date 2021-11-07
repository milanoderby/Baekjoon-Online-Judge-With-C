#pragma once
#include <iostream>
using namespace std;
void solve1475(void) {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	int arr[10] = { 0, };

	for (; n != 0; n /= 10) {
		arr[n % 10]++;
	}

	int max = 0;
	arr[6] = (arr[6] + arr[9] + 1) / 2;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max;
}