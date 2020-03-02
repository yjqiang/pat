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

int find(long long max_wanted) {
	int low, high, mid, value;
	low = 0;
	high = N - 1;
	while (low < high) {
		mid = (low + high) / 2;
		value = nums[mid];
		if (value > max_wanted)
			high = mid;
		else
			low = mid + 1;
	}
	// printf("%d nums[%d]=%d\n", max_wanted, low, nums[low]);
	if (nums[low] > max_wanted)
		return low - 1;
	return low;
}

int main() {
	int p;
	scanf("%d%d", &N, &p);
	int i, max_num;
	max_num = INT_MIN;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);
	
	qsort(nums, N, sizeof(int), cmp);

	int count = -1;
	for (i = 0; i < N; ++i)
		count = max(count, find((long long)nums[i] * p) - i + 1);
	printf("%d", count);

	system("pause");
	return 0;
}