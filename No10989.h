#pragma once
#include <stdio.h>
using namespace std;
const int SIZE = 10001;

void solve10979(void) {
	int N;
	scanf("%d", &N);

	int saveArr[SIZE] = { 0, };

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		saveArr[num]++;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < saveArr[i]; j++) {
			printf("%d\n", i);
		}
	}
}