#pragma once
#include <iostream>
using namespace std;
void solve1003(void) {
	int T;
	cin >> T;

	const int SIZE = 41;
	int cnt[SIZE][2];
	cnt[0][0] = 1, cnt[0][1] = 0;
	cnt[1][0] = 0, cnt[1][1] = 1;

	for (int i = 2; i < SIZE; i++) {
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 2][0];
		cnt[i][1] = cnt[i - 1][1] + cnt[i - 2][1];
	}

	const int LEN = 1000;
	int num[LEN] = { 0, };
	for (int i = 0; i < T; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < T; i++) {
		cout << cnt[num[i]][0] << " " << cnt[num[i]][1] << "\n";
	}
}