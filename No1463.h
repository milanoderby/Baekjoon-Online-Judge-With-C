#pragma once
#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 100001;
int DP[SIZE];

int getDP(int num) {
	int cnt = 0;
	while (num >= SIZE) {
		if (num % 3 == 0) {
			num /= 3;
			cnt++;
		}
		else if (num % 2 == 0) {
			num /= 2;
			cnt++;
		}
		else {
			num--;
			cnt++;
		}
	}
	return cnt + DP[num];
}

void solve1463(void) {
	int N;
	cin >> N;

	const int MAX = 100000;
	DP[2] = 1, DP[3] = 1;

	for (int i = 4; i <= SIZE; i++) {
		int num1, num2, num3;
		if (i % 2 == 0) {
			num1 = DP[i / 2];
		}
		else {
			num1 = MAX;
		}
		if (i % 3 == 0) {
			num2 = DP[i / 3];
		}
		else {
			num2 = MAX;
		}
		num3 = DP[i - 1];
		DP[i] = min(min(num1, num2), num3) + 1;
	}

	if (N >= SIZE) {
		int min = getDP(N);
		for (int i = 1; i < min; i++) {
			if (min > getDP(N - i) + i) {
				min = getDP(N - i) + i;
			}
		}
		cout << min;
	}
	else {
		cout << DP[N];
	}
}