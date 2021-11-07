#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void solve1011(void) {
	const int sqrt_maxnum = 46341;
	int n;
	cin >> n;
	vector<unsigned int> dist(n);

	unsigned int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		dist[i] = y - x;
	}


	for (int i = 0; i < n; i++) {
		int min = 0, max = sqrt_maxnum;
		int mid = (min + max) / 2;
		while (min + 1 < max) {
			if (pow(mid, 2) < dist[i]) {
				min = mid;
			}
			else if (pow(mid, 2) >= dist[i]) {
				max = mid;
			}
			mid = (min + max) / 2;
		}

		if (dist[i] <= 1) {
			cout << dist[i] << endl;
		}
		else if (pow(mid, 2) + mid < dist[i]) {
			cout << 2 * mid + 1 << endl;
		}
		else {
			cout << 2 * mid << endl;
		}
	}
}