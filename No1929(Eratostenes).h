#pragma once
#include <iostream>
using namespace std;
const int SIZE = 1000001;
const int sqrtSIZE = 1000;
void solve1929(void) {
	int m, n;
	cin >> m >> n;

	int prime[SIZE] = { 0, };
	prime[0] = 1, prime[1] = 1;
	for (int i = 2; i <= sqrtSIZE; i++) {
		if (prime[i] == 0) {
			for (int j = i + 1; j < SIZE; j++) {
				if (prime[j] != 1 && j % i == 0) {
					prime[j] = 1;
				}
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i] == 0) {
			cout << i << "\n";
		}
	}
}