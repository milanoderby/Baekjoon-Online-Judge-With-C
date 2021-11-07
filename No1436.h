#pragma once
#include <iostream>
using namespace std;
void solve1436(void) {
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 666; 1; i++) {
		int num = i;
		while (num >= 100) {
			if (num % 1000 == 666) {
				cnt++;
				break;
			}
			num /= 10;
		}
		if (cnt == N) {
			cout << i;
			break;
		}
	}
}