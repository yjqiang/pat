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

#define N_MAX 100000

int nums[N_MAX];
// left_maxs[i] = nums[0], nums[1],... nums[i]范围内最大值
int left_maxs[N_MAX];
// right_mins[i] = nums[N-1], nums[N-2], ... nums[i]最小值
 int right_mins[N_MAX];

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);

	// 辅助数组
	int left_max = INT_MIN;
	for (i = 0; i < N; ++i) {
		if (nums[i] > left_max)
			left_max = nums[i];
		left_maxs[i] = left_max;
	}
	int right_min = INT_MAX;
	for (i = N -1; i >= 0; --i) {
		if (nums[i] < right_min)
			right_min = nums[i];
		right_mins[i] = right_min;
	}

	// N == 1 没处理

	vector <int> results;
	for (i = 0; i < N; ++i)
		// 注意笔记
		if ((i == N - 1 || right_mins[i + 1] > nums[i]) &&
			(i == 0 || left_maxs[i - 1] < nums[i]))

			results.push_back(nums[i]);

	int n_size = results.size();
	printf("%d\n", n_size);
	if (n_size) {
		printf("%d", results[0]);
		for (i = 1; i < n_size; ++i)
			printf(" %d", results[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}