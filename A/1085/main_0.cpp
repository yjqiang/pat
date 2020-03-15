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

#define N_MAX 100000

long long nums[N_MAX];

int cmp(const void* p0, const void* p1) {
	long long* a = (long long*)p0;
	long long* b = (long long*)p1;

	if ((*a) < (*b))
		return -1;
	if ((*a) > (*b))
		return 1;
	return 0;
}

int main() {
	int N;
	long long p;
	scanf("%d %lld", &N, &p);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%lld", nums + i);

	qsort(nums, N, sizeof(long long), cmp);

	int i_M, i_m;
	i_M = 0;

	int result = -1;

	// m*p
	long long mp;
	for (i_m = 0; i_m < N; ++i_m) {
		mp = nums[i_m] * p;
		// i_m增大后，mp一定比之前大了，所以可以接着上次的M位置，继续查找
		for (; i_M < N && nums[i_M] <= mp; ++i_M);
		result = max(result, i_M - i_m);
	}

	printf("%d", result);
	system("pause");
	return 0;
}