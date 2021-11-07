#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

void solve1149(void) {
	const int SIZE = 1050;
	int cost[SIZE][3];

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	int DP[SIZE][3];
	DP[0][0] = cost[0][0];
	DP[0][1] = cost[0][1];
	DP[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int num1 = DP[i - 1][(j + 1) % 3];
			int num2 = DP[i - 1][(j + 2) % 3];
			DP[i][j] = cost[i][j] + min(num1, num2);
		}
	}

	cout << min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2] });
}