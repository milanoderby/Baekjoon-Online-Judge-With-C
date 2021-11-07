#pragma once
#include <iostream>
using namespace std;
const unsigned int MAX = 4200000000;

int getAnswer(int a, int unitProfit) {
	unsigned int min = 0, max = MAX / unitProfit;
	unsigned int mid = (min + max) / 2;
	while (min + 1 < max) {
		int profit = mid * unitProfit;
		if (profit <= a) {
			min = mid;
		}
		else {
			max = mid;
		}
		mid = (min + max) / 2;
	}
	return mid + 1;
}

void solve1712(void) {
	int a, b, c;
	cin >> a >> b >> c;

	int unitProfit = c - b;
	if (unitProfit <= 0) {
		cout << -1;
		return 0;
	}
	cout << getAnswer(a, unitProfit);
}