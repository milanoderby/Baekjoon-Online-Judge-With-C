#pragma once
#include <iostream>
#include <vector>
using namespace std;
void solve10250(void) {
	int t;
	cin >> t;

	vector<int> h(t);
	vector<int> w(t);
	vector<int> n(t);
	for (int i = 0; i < t; i++) {
		cin >> h[i] >> w[i] >> n[i];
	}

	for (int i = 0; i < t; i++) {
		int remainder = n[i] % h[i];
		if (remainder == 0) {
			cout << h[i];
		}
		else {
			cout << remainder;
		}

		int portion = (n[i] - 1) / h[i];

		if (portion < 9) {
			cout << 0;
		}
		cout << portion + 1 << "\n";
	}
}