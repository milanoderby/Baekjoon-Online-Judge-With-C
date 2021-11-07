#pragma once
#include <iostream>
using namespace std;
int hanoiTower(int n, int start, int end, int cnt) {
	if (n == 1) {
		if (cnt == -1) {
			cout << start << " " << end << "\n";
			return cnt;
		}
		else {
			return cnt + 1;
		}
	}
	cnt = hanoiTower(n - 1, start, 6 - (start + end), cnt);
	if (cnt == -1) {
		cout << start << " " << end << "\n";
	}
	else {
		cnt++;
	}
	cnt = hanoiTower(n - 1, 6 - (start + end), end, cnt);
}

void solve11729(void) {
	int N;
	cin >> N;
	int count = hanoiTower(N, 1, 3, 0);
	cout << count << "\n";
	count = hanoiTower(N, 1, 3, -1);
}