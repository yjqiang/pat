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

int nums[10001];

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);
	sort(nums, nums + N);

	// 哈夫曼那样，取最短的两根
	double result = nums[0];
	for (i = 1; i < N; ++i)
		result = (nums[i] + result) / 2;
	printf("%d", (int)result);

	system("pause");
	return 0;
}