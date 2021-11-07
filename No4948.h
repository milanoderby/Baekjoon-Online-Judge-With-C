#pragma once
#include <iostream>
#include <vector>
using namespace std;
void solve4948(void) {
	const int SIZE = 123456 * 2 + 1;
	const int sqrtSIZE = 500;
	const int arrSIZE = 1000;
	vector<int> num(arrSIZE);
	int arrsize = 0;
	for (; 1; arrsize++) {
		cin >> num[arrsize];
		if (num[arrsize] == 0) {
			break;
		}
	}

	int prime[SIZE] = { 0, };
	prime[0] = 1, prime[1] = 1;
	for (int i = 2; i <= sqrtSIZE; i++) {
		if (prime[i] == 0) {
			for (int j = i + 1; j < SIZE; j++) {
				if ((prime[j] != 1) && (j % i == 0)) {
					prime[j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < arrsize; i++) {
		int cnt = 0;
		for (int j = num[i] + 1; j <= 2 * num[i]; j++) {
			if (prime[j] == 0) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}