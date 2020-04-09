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

#define N_MAX 201
#define M_MAX 200
#define L_MAX 10000

// 把输入的第一行数组的元素值映射为输入顺序，这样就把题目转化为最长不降子串
// 默认为 0，表示没这个数
int books[N_MAX] = { 0 };

int nums[L_MAX];

// dp[i]表示以i为结尾的最长不降子串的长度
int dp[L_MAX];

int main() {
	int N, M, L;

	scanf("%d %d", &N, &M);

	int i, h;
	int num;
	for (i = 1; i <= M; ++i) {
		scanf("%d", &num);
		books[num] = i;
	}

	scanf("%d", &L);
	for (i = 0, h = 0; i < L; ++i) {
		scanf("%d", &num);
		// 过滤掉那些不在需要序列里面的元素
		if (books[num])
			nums[h++] = books[num];
	}
	// 更新L长度
	L = h;



	int result = -1;

	// 每个循环都是在求dp[i]
	for (i = 0; i < L; ++i) {
		dp[i] = 1; // 因为最差就是这个子串只有本身一个元素
		for (h = 0; h < i; ++h)
			// 可以在dp[h]对应子串的基础上，继续扩展
			if (nums[i] >= nums[h])
				dp[i] = max(dp[i], dp[h] + 1);

		result = max(dp[i], result);
	}

	printf("%d", result);
	system("pause");
	return 0;
}