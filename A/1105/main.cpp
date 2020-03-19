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

#define MATRIX_MAX 1000
#define N_MAX 100000

int nums[N_MAX];
int results[MATRIX_MAX][MATRIX_MAX];

// 从大到小
int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*b) - (*a);
}

int main() {
	int N;
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);
	qsort(nums, N, sizeof(int), cmp);
	
	int m, n;
	// m 大于等于 sqrt(N)
	for (m = 1; N % m != 0 || N / m > m; ++m);
	n = N / m;

	// printf("%d\n", m);

	int h;
	// 第i环
	int round;
	int count;
	// 若环成了一条线，即右上角(i, n-i-1) 与左上角的点(i, i)重合，这时候逻辑不好控制（上右下中四条边可能重复刷入数据）
	// 巧妙使用count的终止，可以在一条线的特殊环时也正常工作
	for (round = 0, count = 0; count < N; ++round) {
		// 上边(round, round)->(round, n-round-1)
		// 巧妙使用count的终止
		for (h = round; h <= n - round - 1 && count < N; ++h)
			results[round][h] = nums[count++];

		// 右边，扣除最上面的点(round + 1,  n - round - 1)->(m - round - 1,  n - round - 1)
		// 巧妙使用count的终止
		for (h = round + 1; h <= m - round - 1 && count < N; ++h)
			results[h][n - round - 1] = nums[count++];

		// 下边，扣除最右面的点(m - round - 1,  n - round - 2) -> (m - round - 1, round)
		// 巧妙使用count的终止
		for (h = n - round - 2; h >= round && count < N; --h)
			results[m - round - 1][h] = nums[count++];

		// 左边，扣除两个端点的点(m - round - 2,  round) -> (round + 1, round)
		// 巧妙使用count的终止
		for (h = m - round - 2; h >= round + 1 && count < N; --h)
			results[h][round] = nums[count++];
	}

	for (i = 0; i < m; ++i) {
		printf("%d", results[i][0]);
		for (h = 1; h < n; ++h)
			printf(" %d", results[i][h]);
		printf("\n");
	}
	
	system("pause");
	return 0;
}