#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;


int main() {
	int M, N, A, B, cover;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &cover);

	int i, k;
	int value, result;
	for (i = 0; i < M; ++i) {
		for (k = 0; k < N; ++k) {
			scanf("%d", &value);
			result = (value >= A && value <= B) ? cover : value;

			if (k == 0)
				printf("%03d", result);
			else
				printf(" %03d", result);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}