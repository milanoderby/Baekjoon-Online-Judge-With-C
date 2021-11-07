#pragma once
#include <iostream>
using namespace std;
void solve3053(void) {
	double r;
	cin >> r;

	const double PI = 3.1415926535897932384;
	double euclidArea = r * r * PI;
	double taxiArea = 2 * r * r;

	cout.setf(ios_base::fixed);
	cout.precision(6);

	cout << euclidArea << "\n" << taxiArea;
}