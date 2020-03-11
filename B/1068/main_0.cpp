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

int colors[1002][1002];

// 是否独一无二
map<int, int> counts;

int main() {
	int M, N, TOL;
	scanf("%d%d%d", &M, &N, &TOL);



	int i, k;
	// 哨兵
	for (i = 0; i < 1002; ++i)
		for (k = 0; k < 1002; ++k)
			colors[i][k] = -1;

	for (i = 1; i <= N; ++i)
		for (k = 1; k <= M; ++k) {
			scanf("%d", colors[i] + k);
			++counts[colors[i][k]];
		}

	int result_i, result_k, color;
	result_i = -1;
	
	for (i = 1; i <= N; ++i)
		for (k = 1; k <= M; ++k) {
			color = colors[i][k];
			if (counts[color] == 1 &&
				(colors[i - 1][k - 1] == -1 || abs(colors[i - 1][k - 1] - color) > TOL) &&
				(colors[i - 1][k] == -1 || abs(colors[i - 1][k] - color) > TOL) &&
				(colors[i - 1][k + 1] == -1 || abs(colors[i - 1][k + 1] - color) > TOL) &&

				(colors[i][k - 1] == -1 || abs(colors[i][k - 1] - color) > TOL) &&
				(colors[i - 1][k + 1] == -1 || abs(colors[i - 1][k + 1] - color) > TOL) &&

				(colors[i + 1][k - 1] == -1 || abs(colors[i + 1][k - 1] - color) > TOL) &&
				(colors[i + 1][k] == -1 || abs(colors[i + 1][k] - color) > TOL) &&
				(colors[i + 1][k + 1] == -1 || abs(colors[i + 1][k + 1] - color) > TOL)) {
				if (result_i == -1) {
					result_i = i;
					result_k = k;
				}
				else {
					printf("Not Unique\n");
					return 0;
					// printf("=>(%d, %d): %d\n", k, i, color);
				}



			}

		}
	
	if (result_i == -1)
		printf("Not Exist");
	else
		printf("(%d, %d): %d", result_k, result_i, colors[result_i][result_k]);

	system("pause");
	return 0;
}