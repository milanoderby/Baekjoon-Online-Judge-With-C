#pragma once
#include <iostream>
using namespace std;
void solve2231(void) {
	int N;
	cin >> N;

	int cipher = 0;
	int n = N;
	for (; n != 0; n /= 10) {
		cipher++;
	}
	int i;
	for (i = N - 9 * cipher; i < N; i++) {
		int sum = i;
		int num = i;
		for (; num != 0; num /= 10) {
			sum += num % 10;
		}
		if (sum == N) {
			cout << i;
			break;
		}
	}
	if (i == N) {
		cout << 0;
	}
}