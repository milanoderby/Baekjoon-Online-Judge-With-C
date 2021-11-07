#pragma once
#include <string>
#include <iostream>
using namespace std;
void solve1152() {
	string str;
	getline(cin, str);

	int cnt = 0;
	for (int inx = 1; inx < str.length(); inx++) {
		if (str[inx] == ' ') {
			cnt++;
		}
	}
	if (str[str.length() - 1] == ' ') {
		cout << cnt;
	}
	else {
		cout << cnt + 1;
	}
}