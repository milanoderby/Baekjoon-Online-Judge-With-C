#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findSubString(string subject, string object) {
	int cnt = 0;
	int oInx = 0;
	int tmpInx = 0;
	for (int sInx = 0; sInx < subject.length()-object.length()+1; ) {
		if (subject[tmpInx] == object[oInx]) {
			if (oInx == object.length() - 1) {
				cnt++;
				sInx++;
				tmpInx = sInx;
				oInx = 0;
			}
			else {
				tmpInx++;
				oInx++;
			}
		}
		else {
			sInx++;
			tmpInx = sInx;
			oInx = 0;
		}
	}
	return cnt;
}
void solve2941() {
	string str;
	cin >> str;

	int croAlphaNum[8] = { 0, };
	string croAlpha[8] = { "dz=", "z=", "c=", "c-", "d-", "lj", "nj", "s=" };
	for (int i = 0; i < 8; i++) {
		croAlphaNum[i] = findSubString(str, croAlpha[i]);
	}
	int resultNum = str.length();
	for (int i = 0; i < 8; i++) {
		resultNum -= croAlphaNum[i];
	}
	cout << resultNum;
}