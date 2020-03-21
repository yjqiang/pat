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

#define N_MAX 100001

int nums[N_MAX];

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*b) - (*a);
}

int main() {
	int N;
	scanf("%d", &N);
	
	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", nums + i);
	
	qsort(nums+1, N, sizeof(int), cmp);
	
	for (i = 1; i <= N; ++i)
		// nums[i] > i 则 nums[1,2...i]这至少i天均大于i英里
		// nums[i] <= i 则最多 nums[1,2...(i-1)]这i-1天大于i英里
		if (nums[i] <= i) {
			break;
		}

	// i == N+1时，结果为N
	printf("%d", i - 1);

	system("pause");
	return 0;
}