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
#include <unordered_set>

using namespace std;

#define N_MAX 1001
int K, N;

// index从1开始
int nums[N_MAX];

bool isOk() {
	int i, j;
	for (i = 1; i <= N; ++i)
		for (j = i + 1; j <= N; ++j)
			// nums[i] == nums[j]是看看有没有相同行

			// 对角线/方向时， y = x + b => nums[i] - i == nums[j] - j
			// 对角线\方向时， y = -x + b => nums[i] + i == nums[j] + j
			// 所以 nums[i]-nums[j] == ±(i - j)
			// 或者等腰直角三角形解释（两腰相等）
			if (nums[i] == nums[j] || abs(nums[i] - nums[j]) == abs(i - j))
				return false;
	return true;
}

int main() {
	scanf("%d", &K);

	int i, h;
	for (i = 0; i < K; ++i) {
		scanf("%d", &N);
		for (h = 1; h <= N; ++h)
			scanf("%d", nums + h);
		if (isOk())
			printf("YES\n");
		else
			printf("NO\n");
	}


	system("pause");
	return 0;
}