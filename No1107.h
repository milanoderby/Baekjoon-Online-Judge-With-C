#pragma once
#include <iostream>
using namespace std;
int getNearNum(int num, int arr[], int M) {
	int answer = num;
	while (num != 0) {
		int cmp = num % 10;
		for (int i = 0; i < M; i++) {
			if (arr[i] == cmp) {
				return -1;
			}
		}
		num /= 10;
	}

	if (answer == 0) {
		for (int i = 0; i < M; i++) {
			if (arr[i] == answer) {
				return -1;
			}
		}
	}

	return answer;
}

int getCipher(int num) {
	if (num == 0) {
		return 1;
	}
	int cnt = 0;
	for (; num != 0; num /= 10) {
		cnt++;
	}
	return cnt;
}

void solve1107(void) {
	const int SIZE = 10;
	int N, M;
	cin >> N >> M;

	int arr[SIZE] = { 0, };
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	if (N == 100) {
		cout << 0;
		return 0;
	}

	if (M == 10) {
		int answer = (N > 100) ? (N - 100) : (100 - N);
		cout << answer;
		return 0;
	}

	if (M == 9) {
		int i;
		for (i = 0; i < M; i++) {
			if (arr[i] == 0) {
				break;
			}
		}
		if (i == M) {
			if (N < 50) {
				cout << N + 1;
				return 0;
			}
			else {
				int answer = (N > 100) ? (N - 100) : (100 - N);
				cout << answer;
				return 0;
			}
		}
	}

	if (M == 0) {
		int cipher = getCipher(N);
		int upDown = (N > 100) ? (N - 100) : (100 - N);
		int answer = cipher < upDown ? cipher : upDown;
		cout << answer;
		return 0;
	}

	int cnt1;
	for (int i = N; 1; i++) {
		if ((cnt1 = getNearNum(i, arr, M)) != -1)
		{
			break;
		}
	}

	int cnt2;
	for (int i = N; i >= 0; i--) {
		if ((cnt2 = getNearNum(i, arr, M)) != -1)
		{
			break;
		}
	}

	int minClick, minChannel;
	if (cnt2 != -1) {
		minClick = (cnt1 - N) < (N - cnt2) ? (cnt1 - N) : (N - cnt2);
		minChannel = (cnt1 - N) < (N - cnt2) ? cnt1 : cnt2;
	}
	else {
		minClick = cnt1 - N;
		minChannel = cnt1;
	}

	int cipher = getCipher(minChannel);
	int sum = cipher + minClick;
	int upDown = (N > 100) ? (N - 100) : (100 - N);
	int result = sum < upDown ? sum : upDown;
	cout << result;
}