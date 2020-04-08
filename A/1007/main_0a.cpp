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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define K_MAX 10001
int K;

int nums[K_MAX];

bool allNegative() {
	int i;
	for (i = 1; i <= K; ++i)
		if (nums[i] >= 0)
			return false;
	return true;
}

// result = nums[i] + nums[i+1] + ... + nums[j]
struct Sum {
	int result;
	int i, j;
};

int main() {
	
	scanf("%d", &K);

	int i;
	for (i = 1; i <= K; ++i)
		scanf("%d", nums + i);

	if (allNegative()) {
		printf("0 %d %d", nums[1], nums[K]);
		return 0;
	}

	// min_sums[i] = nums[1] + nums[2] + ... + nums[i]  前缀和最小的情况
	Sum min_sums_i;
	min_sums_i.result = 0;
	min_sums_i.i = 1;  // 这个是写死的，不变了
	min_sums_i.j = 0;  // min_sums[0] = 0

	// sums[i] = nums[1] + nums[i + 1] + ... + nums[i]  前缀和
	int sums_i;

	// result_sum 为最优子串的结果
	Sum result;
	result.result = INT_MIN;
	result.i = result.j = 1;


	sums_i = 0;
	for (i = 1; i <= K; ++i) {
		sums_i += nums[i];

		if (sums_i - min_sums_i.result > result.result) {
			result.result = sums_i - min_sums_i.result;
			result.i = min_sums_i.j + 1;
			result.j = i;
		}

		if (sums_i < min_sums_i.result) {
			min_sums_i.result = sums_i;
			min_sums_i.j = i;
		}
	}

	printf("%d %d %d", result.result, nums[result.i], nums[result.j]);

	system("pause");
	return 0;
}