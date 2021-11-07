#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void setChessBoard(char chess[][8], int color) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == color) {
				chess[i][j] = 'B';
			}
			else {
				chess[i][j] = 'W';
			}
		}
	}
}
int compareBoard(vector<vector<char>> board, int iInx, int jInx, char cmpB[8][8]) {
	int cnt = 0;
	for (int i = iInx; i < iInx + 8; i++) {
		for (int j = jInx; j < jInx + 8; j++) {
			if (board[i][j] != cmpB[i - iInx][j - jInx]) {
				cnt++;
			}
		}
	}
	return cnt;
}

void solve1018(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	char cB1[8][8], cB2[8][8];
	setChessBoard(cB1, 0);
	setChessBoard(cB2, 1);

	int nMax = n - 8;
	int mMax = m - 8;
	int min = 64;
	for (int i = 0; i <= nMax; i++) {
		for (int j = 0; j <= mMax; j++) {
			int cnt1 = compareBoard(board, i, j, cB1);
			int cnt2 = compareBoard(board, i, j, cB2);
			int minCnt = cnt1 < cnt2 ? cnt1 : cnt2;
			if (minCnt < min) {
				min = minCnt;
			}
		}
	}
	cout << min;

	return 0;
}