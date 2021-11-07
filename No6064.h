#pragma once
#include <iostream>
#include <vector>
using namespace std;

int getGCD(int a, int b) {

	for (int r = a % b; r != 0; ) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int getAnswer(int M, int N, int x, int y) {
	int answer;
	int gcd = getGCD(M, N);
	for (int i = 0; i < N / gcd; i++) {
		answer = M * i + x;
		if ((answer % N == y) || (y == N && answer % N == 0)) {
			return answer;
		}
	}
	return -1;
}

void solve6064(void) {
	int t;
	cin >> t;

	vector<int> M(t), N(t), x(t), y(t);

	for (int i = 0; i < t; i++) {
		cin >> M[i] >> N[i] >> x[i] >> y[i];
	}

	for (int i = 0; i < t; i++) {
		cout << getAnswer(M[i], N[i], x[i], y[i]) << "\n";
	}
}