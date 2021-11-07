#pragma once
#include <iostream>
using namespace std;

void solve2292(void) {
	int n;
	cin >> n;
	if (n==1) {
		cout << 1;
		return;
	}
	int cnt;
	int r = 6;
	int sum = 1;

	for (cnt = 1; sum + 1 <= n; cnt++) {
		sum += r;
		r += 6;
	}
	cout << cnt;
}