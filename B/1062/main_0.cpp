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

using namespace std;

// ���Լ��
int gcd(int m, int n) {
	int x = m;
	while (x != 0) {
		x = m % n;
		m = n;
		n = x;
	}
	// m % n Ϊ 0����ʱ m=n�����ִ���ˣ�������Ҫ��n��ʵ�����m
	return m;
}

int main() {
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	int N1M2 = N1 * M2, N2M1 = N2 * M1;
	if (N1M2 > N2M1) {
		swap(N1, N2);
		swap(M1, M2);
	}
	// [min_N, max_N]������
	int min_N, max_N;
	// ������һ��������ȡ�� => ��ȡ�����һ
	min_N = N1 * K / M1 + 1;

	// ������һ��������ȡ�� => ��ȡ�����һ
	max_N = (N2 * K + M2 - 1) / M2 - 1;

	int i;
	bool is_first = true;
	for (i = min_N; i <= max_N; ++i)
		if (gcd(i, K) == 1) {
			if (!is_first)
				printf(" %d/%d", i, K);
			else {
				printf("%d/%d", i, K);
				is_first = false;
			}
		}
			

	system("pause");
	return 0;
}