#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 100001

// 前缀和
int sums[N_MAX];

// 大于等于wanted的最小index
int find(int wanted, int low, int high) {
	int mid;
	while (low < high) {
		mid = (high - low) / 2 + low;
		if (sums[mid] >= wanted)
			high = mid;
		else
			low = mid + 1;
	}
	if (sums[low] >= wanted)
		return low;
	return -1;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int i;
	int num;
	int sum = 0;
	// 加一个守卫
	sums[0] = 0;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &num);
		sum += num;
		// values根本没存，直接生成前缀和了
		sums[i] = sum;
	}

	// i_1  就是 i-1， 因为 sums[j] - sums[i-1] 就是  values[i-j] 的和
	int j, i_1;
	int min_result = INT_MAX;
	int result;
	vector<int> results;
	for (i_1 = 0; i_1 < N; ++i_1) {
		j = find(sums[i_1] + M, i_1, N);
		if (j == -1)
			continue;
		i = i_1 + 1;
		result = sums[j] - sums[i_1];
		// printf("%d-%d=>%d\n", i, j, result);

		if (result < min_result) {
			min_result = result;
			results.clear();

			// 很机智，把俩数据相邻 存放
			results.push_back(i);
			results.push_back(j);
		}
		else if (result == min_result) {
			// 同上
			results.push_back(i);
			results.push_back(j);
		}
	}

	int n = results.size() / 2;
	for (i = 0; i < n; ++i)
		printf("%d-%d\n", results[2 * i], results[2 * i + 1]);


	system("pause");
	return 0;
}