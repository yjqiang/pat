// 可以把硬币看成w = v(即容量 = 价值)的物品，现在要选取这些物品放入到容量为m的背包中，求能装的最大价值。
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

#define N_MAX 10002
int N;
int c[N_MAX];
// 动态规划f[i][v]表示从[1, i]挑选最大容量为v的商品，最大的价值之和
// 初始化f[0][v]为0
int f[N_MAX] = { 0 };

// chosen[i][j]数组表示背包里容量限制为j的时候，最佳选择是否含有第i个物品，用于最后序列的输出。
bool chosen[10010][110] = {false};

int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;
	return (*i1) - (*i0);
}

int main() {
	int M;
	scanf("%d%d", &N, &M);

	int i;
	// 为了dp而设置的，从1开始
	for (i = 1; i <= N; ++i)
		scanf("%d", c + i);
	qsort(c + 1, N, sizeof(int), cmp);

	int v;
	for (i = 1; i <= N; ++i)
		// 因为节省空间，把f二维数组压缩了，所以在求f[i][v]时，得让f[i-1][v-c[i]]在f里面，必须v从大到小迭代了
		for (v = M; v >= 0; --v) {
			// 等于的情况下，也选择i，这是因为结果是要求“最小”的；因为数字是从大到小的
			if (v - c[i] >= 0 && f[v - c[i]] + c[i] >= f[v]) {
				f[v] = f[v - c[i]] + c[i];
				// 在约束v的情况下，i加入且以i为最大标号的路径是否是一个最佳路径
				chosen[i][v] = true;
			}
		}

	
	if (f[M] != M) {
		printf("No Solution");
	}
	else {

		vector<int> answer;
		for (v = M, i = N; v > 0; --i)
			if (chosen[i][v]) {
				answer.push_back(c[i]);
				v -= c[i];
			}

		// 打印结果
		printf("%d", answer[0]);
		for (i = 1; i < answer.size(); i++)
			printf(" %d", answer[i]);
	}

	system("pause");
	return 0;
}