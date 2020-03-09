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

// 最大公约数
int gcd(int m, int n) {
	int x = m;
	while (x != 0) {
		x = m % n;
		m = n;
		n = x;
	}
	// m % n 为 0，此时 m=n的语句执行了，我们想要的n其实变成了m
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
	// [min_N, max_N]闭区间
	int min_N, max_N;
	// 整数加一，否则上取整 => 下取整后加一
	min_N = N1 * K / M1 + 1;

	// 整数减一，否则下取整 => 上取整后减一
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