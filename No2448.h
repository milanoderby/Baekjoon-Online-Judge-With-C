#pragma once
#include <iostream>
#include <vector>
using namespace std;

void markBasicStar(vector< vector<int>>* arr, int m, int n) {
	for (int i = 0; i < 3; i++) {
		(*arr)[i+m][3 - i + n] = 1;
		(*arr)[i+m][3 + i + n] = 1;
		for (int j = 1; j < 5; j++) {
			if (i==2) {
				(*arr)[i + m][j + n] = 1;
			}
		}
	}
}

void markStarArr(vector< vector<int>>* arr, int line, int m, int n) {
	if (line == 3) {
		markBasicStar(arr, m, n);
	}
	else {
		markStarArr(arr, line / 2, m, n + line / 2);
		markStarArr(arr, line / 2, m + line / 2, n);
		markStarArr(arr, line / 2, m + line / 2, n + line);
	}
}

void drawStarArr(vector< vector<int> >* arr, int lineNum) {
	for (int i = 0; i < lineNum; i++) {
		for (int j = 1; j < 2 * lineNum; j++) {
			if ((*arr)[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

/* mainÇÔ¼ö
#include <iostream>
#include <vector>
#include "No2448.h"
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> arr(n+1, vector<int>(2 * n, 0));

	markStarArr(&arr, n, 0, 0);
	drawStarArr(&arr, n);

	return 0;
}
*/