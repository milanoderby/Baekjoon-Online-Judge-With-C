#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

void solve2579(void) {
	int stair;
	cin >> stair;

	const int MAX = 305;
	int score[MAX];
	for (int i = 1; i <= stair; i++) {
		cin >> score[i];
	}

	int DP[MAX][2];
	DP[1][0] = score[1], DP[1][1] = 1;
	DP[2][0] = score[1] + score[2], DP[2][1] = 2;
	if (DP[1][0] >= score[2]) {
		DP[3][0] = score[3] + DP[1][0];
		DP[3][1] = 1;
	}
	else {
		DP[3][0] = score[3] + score[2];
		DP[3][1] = 2;
	}

	for (int i = 4; i <= stair; i++) {
		if (DP[i - 2][0] >= DP[i - 1][0] || DP[i - 1][1] == 2) {
			DP[i][0] = DP[i - 2][0] + score[i];
			DP[i][1] = 1;
		}
		else {
			DP[i][0] = DP[i - 1][0] + score[i];
			DP[i][1] = DP[i - 1][1] + 1;
		}
	}

	cout << DP[stair][0];
}