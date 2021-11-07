#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve2675(void) {
	int caseNum;
	cin >> caseNum;
	vector<int> r(caseNum);
	vector<string> str(caseNum);

	for (int i = 0; i < caseNum; i++) {
		cin >> r[i];
		cin >> str[i];
	}

	for (int i = 0; i < caseNum; i++) {
		for (int j = 0; j < str[i].length(); j++) {
			for (int k = 0; k < r[i]; k++) {
				cout << str[i][j];
			}
		}
	}
}