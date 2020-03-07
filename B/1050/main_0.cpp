#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int a[10000];
int results[10000][10000];

int myCmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return -((*a) - (*b));
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", a + i);

	qsort(a, N, sizeof(int), myCmp);

	int m, n;
	// 从(int)√N开始搜寻
	for (i = sqrt(N); i <= N; ++i)
		if (N % i == 0 && i >= N/i) {
			m = i;
			n = N / i;
			break;
		}

	// printf("m=%d n=%d\n", m, n);

	// 标记第几环(最外环记为1)
	int round;
	// 标记填了多少人
	int count;
	for (round = 1, count = 0; count < N; ++round) {

		// && count < N  例如 m*n = 1 * 2 那么直接就填完了

		// 整个上边
		// 环的上边 a[round-1][round-1] -> a[round-1][n-round]
		for (i = round - 1; i <= n - round && count < N; ++i) {
			results[round - 1][i] = a[count];
			++count;
		}

		// 整个右边，扣除最上面那个
		// 环的右边 a[round][n-round] -> a[m-round][n-round]
		for (i = round; i <= m - round && count < N; ++i) {
			results[i][n - round] = a[count];
			++count;
		}

		// 注意i的加减方向
		// 整个下边，扣除最右面那个
		// 环的下边 a[m-round][n-round-1] -> a[m-round][round-1]
		for (i = n - round - 1; i >= round - 1 && count < N; --i) {
			results[m - round][i] = a[count];
			++count;
		}

		// 注意i的加减方向
		// 整个左边，扣除上下端点
		// 环的下边 a[m-round-1][[round-1] -> a[round][round-1]
		for (i = m - round - 1; i >= round && count < N; --i) {
			results[i][round - 1] = a[count];
			++count;
		}

	}

	int k;
	for (i = 0; i < m; ++i) {
		printf("%d", results[i][0]);
		for (k = 1; k < n; ++k)
			printf(" %d", results[i][k]);
		printf("\n");
	}

	system("pause");
	return 0;
}