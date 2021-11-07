#pragma once
#include <iostream>
using namespace std;
void solve4153(void) {
	const int ArrSize = 1000;
	int a[ArrSize], b[ArrSize], c[ArrSize];
	int i;
	for (i = 0; 1; i++) {
		cin >> a[i] >> b[i] >> c[i];

		if ((a[i] == 0 && b[i] == 0) && c[i] == 0) {
			break;
		}
	}

	for (int j = 0; j < i; j++) {
		int sum = a[j] * a[j] + b[j] * b[j] - c[j] * c[j];
		if (sum == 0) {
			cout << "right" << "\n";
		}
		else {
			cout << "wrong" << "\n";
		}
	}

	return 0;
}