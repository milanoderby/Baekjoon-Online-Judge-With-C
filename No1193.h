#pragma once
#include <iostream>
#include <string>
using namespace std;
void solve1193(void) {
	int sum = 0;
	int added = 1;

	int n;
	cin >> n;
	int cnt;
	for (cnt = 0; sum < n; cnt++) {
		sum += added;
		added++;
	}
	int upNum, downNum;
	if (cnt % 2 == 0) {
		upNum = cnt, downNum = 1;
		for (int i = sum - n; i > 0; i--) {
			upNum--;
			downNum++;
		}
	}
	else {
		upNum = 1, downNum = cnt;
		for (int i = sum - n; i > 0; i--) {
			upNum++;
			downNum--;
		}
	}
	cout << upNum << "/" << downNum;
}