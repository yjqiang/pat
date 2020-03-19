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

// �Ӵ�С
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
	// m ���ڵ��� sqrt(N)
	for (m = 1; N % m != 0 || N / m > m; ++m);
	n = N / m;

	// printf("%d\n", m);

	int h;
	// ��i��
	int round;
	int count;
	// ��������һ���ߣ������Ͻ�(i, n-i-1) �����Ͻǵĵ�(i, i)�غϣ���ʱ���߼����ÿ��ƣ��������������߿����ظ�ˢ�����ݣ�
	// ����ʹ��count����ֹ��������һ���ߵ����⻷ʱҲ��������
	for (round = 0, count = 0; count < N; ++round) {
		// �ϱ�(round, round)->(round, n-round-1)
		// ����ʹ��count����ֹ
		for (h = round; h <= n - round - 1 && count < N; ++h)
			results[round][h] = nums[count++];

		// �ұߣ��۳�������ĵ�(round + 1,  n - round - 1)->(m - round - 1,  n - round - 1)
		// ����ʹ��count����ֹ
		for (h = round + 1; h <= m - round - 1 && count < N; ++h)
			results[h][n - round - 1] = nums[count++];

		// �±ߣ��۳�������ĵ�(m - round - 1,  n - round - 2) -> (m - round - 1, round)
		// ����ʹ��count����ֹ
		for (h = n - round - 2; h >= round && count < N; --h)
			results[m - round - 1][h] = nums[count++];

		// ��ߣ��۳������˵�ĵ�(m - round - 2,  round) -> (round + 1, round)
		// ����ʹ��count����ֹ
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