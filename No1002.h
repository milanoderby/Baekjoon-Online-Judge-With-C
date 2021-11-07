#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int getAbs(int num) {
	return num > 0 ? num : -1 * num;
}

double getDistance(int x1, int y1, int x2, int y2) {
	double xDis = x2 - x1;
	xDis *= xDis;
	double yDis = y2 - y1;
	yDis *= yDis;

	double distance = sqrt(xDis + yDis);
	return distance;
}

void solve1002(void) {
	int t;
	cin >> t;

	vector<int> answer(t);

	int x1, x2, y1, y2, r1, r2;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			answer[i] = -1;
		}
		else {
			double xyDist = getDistance(x1, y1, x2, y2);
			int rDif = getAbs(r1 - r2);
			int rSum = r1 + r2;

			if (rDif < xyDist && xyDist < rSum) {
				answer[i] = 2;
			}
			else if (rDif == xyDist || xyDist == rSum) {
				answer[i] = 1;
			}
			else {
				answer[i] = 0;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << answer[i] << "\n";
	}
}