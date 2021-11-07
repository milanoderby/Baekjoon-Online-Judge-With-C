#pragma once
#pragma once
#include <iostream>
using namespace std;

void Process(int dx, int dy, int N) {
	if ((dx / N) % 3 == 1 && (dy / N) % 3 == 1)
		cout << " ";
	else {
		if (N / 3 == 0)
			cout << "*";
		else
			Process(dx, dy, N / 3);
	}
}

void solve2447() {
	int N;
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			Process(i, j, N);
		}
		cout << "\n";
	}
}