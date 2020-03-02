#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

#define N_MAX 100001
int nums[N_MAX];
int N;

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}


int main() {
	int p;
	scanf("%d%d", &N, &p);
	int i, max_num;
	max_num = INT_MIN;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);
	
	qsort(nums, N, sizeof(int), cmp);

	int k;
	int count = -1;
	long long wanted;
	k = 0;
	for (i = 0; i < N; ++i) {
		wanted = (long long)nums[i] * p;
		for (; k < N && nums[k] <= wanted; ++k);
		count = max((k - 1) - i + 1, count);
	}
	printf("%d", count);

	system("pause");
	return 0;
}