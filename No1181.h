#pragma once
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 20001;

void Merging(string str[], int s1, int e1, int s2, int e2) {
	int i, j;
	int inx = s1;
	string result[SIZE];
	for (i = s1, j = s2; i <= e1 && j <= e2; inx++) {
		int len1 = str[i].length();
		int len2 = str[j].length();
		if (len1 < len2) {
			result[inx] = str[i];
			i++;
		}
		else if (len1 == len2) {
			if (str[i] < str[j]) {
				result[inx] = str[i];
				i++;
			}
			else {
				result[inx] = str[j];
				j++;
			}
		}
		else {
			result[inx] = str[j];
			j++;
		}
	}

	int s, e;
	if (i > e1) {
		s = j;
		e = e2;
	}
	else {
		s = i;
		e = e1;
	}

	for (; s <= e; s++, inx++) {
		result[inx] = str[s];
	}

	for (int k = s1; k <= e2; k++) {
		str[k] = result[k];
	}
}

void MergeSort(string str[], int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(str, start, mid);
	MergeSort(str, mid + 1, end);
	Merging(str, start, mid, mid + 1, end);
}

void solve1181(void) {
	int N;
	cin >> N;

	string str[SIZE];
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	MergeSort(str, 0, N - 1);

	cout << str[0] << '\n';
	for (int i = 1; i < N; i++) {
		if (str[i - 1] != str[i]) {
			cout << str[i] << '\n';
		}
	}
}