#pragma once
#include <iostream>
using namespace std;
const int SIZE = 1000000;

void Merging(int arr[], int start1, int end1, int start2, int end2) {
	int result[SIZE];
	int i, j;
	int inx = start1;
	for (i = start1, j = start2; i <= end1 && j <= end2; inx++) {
		if (arr[i] <= arr[j]) {
			result[inx] = arr[i];
			i++;
		}
		else {
			result[inx] = arr[j];
			j++;
		}
	}

	int s, e;
	if (i > end1) {
		s = j;
		e = end2;
	}
	else {
		s = i;
		e = end1;
	}

	for (; s <= e; s++, inx++) {
		result[inx] = arr[s];
	}

	for (int m = start1; m <= end2; m++) {
		arr[m] = result[m];
	}
}

void MergeSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);
	Merging(arr, start, mid, mid + 1, end);
}
void solve2751(void) {
	int N;
	cin >> N;

	int arr[SIZE];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	MergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}