#pragma once
#include <iostream>
using namespace std;
void solve2748(void) {
	int n;
	cin >> n;

	const int SIZE = 100;
	long long fibo[SIZE] = { 0, };
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n];
}