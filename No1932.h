#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve1932(void) {
	int n;
	cin >> n;

	const int SIZE = 500;
	int triangle[SIZE][SIZE];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	vector<vector<int>> DP(n, vector<int>(n));
	DP[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		DP[i][0] = triangle[i][0] + DP[i - 1][0];
		DP[i][i] = triangle[i][i] + DP[i - 1][i - 1];
	}

	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			DP[i][j] = triangle[i][j] + max(DP[i - 1][j - 1], DP[i - 1][j]);
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < DP[n - 1][i]) {
			max = DP[n - 1][i];
		}
	}
	cout << max;
}