#pragma once
#include <iostream>
using namespace std;
const int SIZE = 100001;

struct Point {
	int x;
	int y;
};
void Merging(Point p[], int s1, int e1, int s2, int e2) {
	int i, j;
	Point result[SIZE];
	int inx = s1;
	for (i = s1, j = s2; i <= e1 && j <= e2; inx++) {
		if (p[i].y < p[j].y) {
			result[inx].x = p[i].x;
			result[inx].y = p[i].y;
			i++;
		}
		else if (p[i].y == p[j].y) {
			if (p[i].x < p[j].x) {
				result[inx].x = p[i].x;
				result[inx].y = p[i].y;
				i++;
			}
			else {
				result[inx].x = p[j].x;
				result[inx].y = p[j].y;
				j++;
			}
		}
		else {
			result[inx].x = p[j].x;
			result[inx].y = p[j].y;
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

	for (; s <= e; s++) {
		result[inx].x = p[s].x;
		result[inx].y = p[s].y;
		inx++;
	}
	for (int m = s1; m <= e2; m++) {
		p[m].x = result[m].x;
		p[m].y = result[m].y;
	}
}

void MergeSort(Point p[], int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(p, start, mid);
	MergeSort(p, mid + 1, end);
	Merging(p, start, mid, mid + 1, end);
}

void solve11651(void) {
	int N;
	cin >> N;

	Point p[SIZE];
	for (int i = 0; i < N; i++) {
		cin >> p[i].x >> p[i].y;
	}

	MergeSort(p, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << p[i].x << " " << p[i].y << "\n";
	}
}