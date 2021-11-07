#pragma once
#include <iostream>
#include <vector>
using namespace std;
void solve4344(void) {
	int testNum;
	cin >> testNum;
	vector<double> avrRate(testNum);
	
	for (int i = 0; i < testNum; i++) {
		int studentNum;
		cin >> studentNum;
		vector<int> arr(studentNum);
		double avr = 0;
		for (int j = 0; j < studentNum; j++) {
			cin >> arr[j];
			avr += arr[j];
		}
		avr /= studentNum;

		int cnt = 0;
		for (int k = 0; k < studentNum; k++) {
			if (arr[k] > avr) {
				cnt++;
			}
		}
		avrRate[i] = (double)(cnt*100) / studentNum;
	}

	for (int i = 0; i < testNum; i++) {
		cout << fixed;
		cout.precision(3);
		cout << avrRate[i] << "%" << endl;
	}
}