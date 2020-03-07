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
	// ��(int)��N��ʼ��Ѱ
	for (i = sqrt(N); i <= N; ++i)
		if (N % i == 0 && i >= N/i) {
			m = i;
			n = N / i;
			break;
		}

	// printf("m=%d n=%d\n", m, n);

	// ��ǵڼ���(���⻷��Ϊ1)
	int round;
	// ������˶�����
	int count;
	for (round = 1, count = 0; count < N; ++round) {

		// && count < N  ���� m*n = 1 * 2 ��ôֱ�Ӿ�������

		// �����ϱ�
		// �����ϱ� a[round-1][round-1] -> a[round-1][n-round]
		for (i = round - 1; i <= n - round && count < N; ++i) {
			results[round - 1][i] = a[count];
			++count;
		}

		// �����ұߣ��۳��������Ǹ�
		// �����ұ� a[round][n-round] -> a[m-round][n-round]
		for (i = round; i <= m - round && count < N; ++i) {
			results[i][n - round] = a[count];
			++count;
		}

		// ע��i�ļӼ�����
		// �����±ߣ��۳��������Ǹ�
		// �����±� a[m-round][n-round-1] -> a[m-round][round-1]
		for (i = n - round - 1; i >= round - 1 && count < N; --i) {
			results[m - round][i] = a[count];
			++count;
		}

		// ע��i�ļӼ�����
		// ������ߣ��۳����¶˵�
		// �����±� a[m-round-1][[round-1] -> a[round][round-1]
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