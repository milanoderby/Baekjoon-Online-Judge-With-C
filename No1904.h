#pragma once
#include <iostream>
using namespace std;
void solve1904(void) {
	int N;
	cin >> N;

	int a, b, c;
	a = 1, b = 2;
	for (int i = 3; i <= N; i++) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}

	cout << c;
}