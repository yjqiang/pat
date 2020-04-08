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

	// cur_sums[i] = 以 nums[i] 为结尾的最大sum的序列
	Sum cur_sums_i;
	cur_sums_i.result = nums[1];
	cur_sums_i.i = cur_sums_i.j = 1;

	// result_sum 为最优子串的结果
	Sum result;
	result.result = nums[1];
	result.i = result.j = 1;

	int sum1, sum2;

	for (i = 2; i <= K; ++i) {
		sum1 = cur_sums_i.result + nums[i];
		sum2 = nums[i];
		if (sum2 > sum1) {
			cur_sums_i.result = sum2;
			cur_sums_i.i = i;
			cur_sums_i.j = i;
		}
		else {
			cur_sums_i.result = sum1;
			// max_sums_i.i = max_sums_i.i;
			cur_sums_i.j = i;
		}
		
		if (cur_sums_i.result > result.result) {
			result.result = cur_sums_i.result;
			result.i = cur_sums_i.i;
			result.j = cur_sums_i.j;
		}
	}

	printf("%d %d %d", result.result, nums[result.i], nums[result.j]);

	system("pause");
	return 0;
}