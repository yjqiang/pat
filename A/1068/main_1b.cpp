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

#define N_MAX 10001
#define M_MAX 101

int nums[N_MAX];

// dp[j]其实是dp[i][j]的空间改进版，dp[i][j] 表示约束最大编号（nums）小于等于i && 体积不超过j的情况下最大重量（01背包问题）
// 初始化为0，表示dp[0][j] 全为0
int dp[M_MAX] = {0};

// results[i][j] 表示恰好以j为和的子序列中，最大编号为i的最优子序列（原题要求output the smallest sequence）是否存在
bool results[N_MAX][M_MAX] = { false };

// 从大到小排序
int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*b) - (*a);
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	int i, j;
	// 从1编号是为了方便01背包
	for (i = 1; i <= N; ++i)
		scanf("%d", nums + i);

	qsort(nums + 1, N, sizeof(int), cmp);


	int cur;
	for (i = 1; i <= N; ++i)
		for (j = M; j >= 0; --j)
			// 若j - nums[i] < 0，则说明i号物品不可以被选中参与到dp[i][j]中
			if (j - nums[i] >= 0) {
				cur = dp[j - nums[i]] + nums[i]; // 背包中一定包含了i，则此时最优结果为dp[i][j] = dp[i-1][j-V[i]] + m[i]
				if (cur >= dp[j]) {
					results[i][cur] = true;
					dp[j] = cur;
				}
		}

	vector<int> s;

	if (dp[M] != M)
		printf("No Solution");
	else {
		for (i = N; i >= 0 && M > 0;) {
			for (;!results[i][M]; --i);
			s.push_back(nums[i]);
			M -= nums[i];
			// nums[i] 已被选中了，不可重复了
			--i;
		}

		printf("%d", s[0]);
		for (i = 1; i < s.size(); ++i)
			printf(" %d", s[i]);
	}
	system("pause");
	return 0;
}