#pragma once
#include <iostream>
#include <vector>
using namespace std;
void solve9461(void) {
	int T;
	cin >> T;

	vector<int> N(T);
	int max = 0;
	for (int i = 0; i < T; i++) {
		cin >> N[i];
		if (max < N[i]) {
			max = N[i];
		}
	}
	const int SIZE = 101;
	long long P[SIZE] = { 0, };
	P[1] = 1, P[2] = 1, P[3] = 1, P[4] = 2, P[5] = 2;
	for (int i = 6; i <= max; i++) {
		P[i] = P[i - 5] + P[i - 1];
	}

	for (int i = 0; i < T; i++) {
		cout << P[N[i]] << "\n";
	}
}