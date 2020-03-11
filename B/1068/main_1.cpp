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

int M, N, TOL;
int colors[1002][1002];
int nearby[8][2] = { {-1, -1}, {-1, 0},  {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

// 是否独一无二
map<int, int> counts;

bool isOK(int i, int k, int color) {
	int near_i, near_k, index;
	for (index = 0; index < 8; ++index) {
		near_i = i + nearby[index][0];
		near_k = k + nearby[index][1];
		// 注意这里&&的逻辑
		if (near_i >= 1 && near_i <= N && near_k >= 1 && near_k <= M && abs(colors[near_i][near_k] - color) <= TOL)
			return false;
	}
	return true;
}

int main() {
	
	scanf("%d%d%d", &M, &N, &TOL);



	int i, k;

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
			if (counts[color] == 1 && isOK(i, k, color)) {
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