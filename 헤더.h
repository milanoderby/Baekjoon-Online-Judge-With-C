#pragma once
#include <iostream>
using namespace std;



void markStarArr(int line, int cnt) {
	if (line == 3) {
		for (int i = 0; i<=) {

		}
	}
	else {
		drawBasicStar(line / 2, cnt+1);

	}
}

void drawStarArr(vector< vector<int> > arr, int lineNum) {
	for (int i = 1; i <= lineNum; i++) {
		for (int j = 1; j < 2 * lineNum; j++) {
			if (arr[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}