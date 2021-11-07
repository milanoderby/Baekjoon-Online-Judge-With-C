#pragma once
#include <iostream>
#include <vector>
using namespace std;

int getPersonNum(int k, int n) {
	if (k == 0) {
		return n;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += getPersonNum(k - 1, i);
	}
	return answer;
}

void solve2775(void) {
	int t;
	cin >> t;

	vector<int> k(t);
	vector<int> n(t);

	for (int i = 0; i < t; i++) {
		cin >> k[i];
		cin >> n[i];
	}

	for (int i = 0; i < t; i++) {
		cout << getPersonNum(k[i], n[i]) << "\n";
	}
}