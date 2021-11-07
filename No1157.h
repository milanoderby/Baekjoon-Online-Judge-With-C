#pragma once
#include <iostream>
#include <string>
using namespace std;
void solve1157(void) {
	string str;
	cin >> str;
	int arr[26] = { 0, };
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			arr[str[i] - 'a']++;
		}
		else {
			arr[str[i] - 'A']++;
		}
	}

	int maxCnt = 0;
	int maxInx = 0;
	int matchCnt = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > maxCnt) {
			matchCnt = 0;
			maxCnt = arr[i];
			maxInx = i;
		}
		else if (arr[i] == maxCnt) {
			matchCnt = 1;
		}
	}

	if (matchCnt == 1) {
		cout << "?";
	}
	else {
		printf("%c", 'A' + maxInx);
	}
}