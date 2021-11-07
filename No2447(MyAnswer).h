#pragma once
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setArr(vector<vector<int>> arr, int size, int n) {
	if (n == 1) {
		return arr;
	}
	int operand = n / 3;
	for (int i = 0; i < size; i++) {
		int iValue = (i % n) / operand;
		for (int j = 0; j < size; j++) {
			int jValue = (j % n) / operand;
			if (iValue == 1 && jValue == 1) {
				arr[i][j] = 1;
			}
		}
	}
	arr = setArr(arr, size, operand);
	return arr;
}

void printArr(vector<vector<int>> arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 0) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void solve2447(void) {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N, 0));
	arr = setArr(arr, N, N);
	printArr(arr, N);
}