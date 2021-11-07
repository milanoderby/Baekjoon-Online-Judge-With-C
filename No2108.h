#pragma once
#include <iostream>
using namespace std;
const int SIZE = 4001;

void solve2108(void) {
	int N;
	cin >> N;

	int minusArr[SIZE] = { 0, };
	int plusArr[SIZE] = { 0, };

	double avr = 0;
	int min = SIZE;
	int max = -SIZE;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num >= 0) {
			plusArr[num]++;
		}
		else {
			minusArr[-num]++;
		}
		if (max < num) {
			max = num;
		}
		if (min > num) {
			min = num;
		}
		avr += num;
	}

	avr /= N;
	int extent = max - min;

	int mid = SIZE, midCnt = 0;
	int half = N / 2 + 1;
	for (int i = SIZE - 1; i > 0; i--) {
		midCnt += minusArr[i];
		if (midCnt >= half) {
			mid = -i;
			break;
		}
	}
	if (mid == SIZE) {
		for (int i = 0; i < SIZE; i++) {
			midCnt += plusArr[i];
			if (midCnt >= half) {
				mid = i;
				break;
			}
		}
	}

	int mode[2 * SIZE] = { 0, }, modeCnt = 0;
	int inx = 0;
	for (int i = SIZE; i > 0; i--) {
		if (modeCnt < minusArr[i]) {
			modeCnt = minusArr[i];
			inx = 0;
			mode[inx] = -i;
		}
		else if (modeCnt == minusArr[i]) {
			inx++;
			mode[inx] = -i;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		if (modeCnt < plusArr[i]) {
			modeCnt = plusArr[i];
			inx = 0;
			mode[inx] = i;
		}
		else if (modeCnt == plusArr[i]) {
			inx++;
			mode[inx] = i;
		}
	}

	cout.setf(ios_base::fixed);
	cout.precision(0);

	cout << avr << "\n";
	cout << mid << "\n";
	if (inx > 0) {
		cout << mode[1] << "\n";
	}
	else {
		cout << mode[0] << "\n";
	}
	cout << extent << "\n";
}