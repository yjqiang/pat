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
#include <unordered_map>

using namespace std;

#define N_MAX 30
int K, N;

int pre[N_MAX];
int in[N_MAX];

bool result;

// root 为该子树的根在pre的下标
// [start, end] 为该子树在in的范围
// count_black 为该子树的根到后缀根节点（NULL）的路径上，黑节点数目
// is_black 表示该子树的根的颜色
void check(int root, int start, int end, int& count_black, bool& is_black) {
	// NULL 节点
	if (start > end) {
		count_black = 1;
		is_black = true;
		return;
	}

	int left_count_black;
	bool left_is_black;
	int right_count_black;
	bool right_is_black;
	int i;
	for (i = start; i <= end && in[i] != pre[root]; ++i);
	if (i > end) {
		result = false;
		return;
	}

	check(root + 1, start, i - 1, left_count_black, left_is_black);

	check(root + i + 1 - start, i + 1, end, right_count_black, right_is_black);

	// 红色节点的孩子颜色有红色的
	if (pre[root] < 0 && (!left_is_black || !right_is_black))
		result = false;

	// 某点到后续NULL的路径上的黑色点数目不一样
	if (left_count_black != right_count_black)
		result = false;

	if (pre[root] < 0) {
		is_black = false;
		count_black = left_count_black;
	}
	else {
		is_black = true;
		count_black = left_count_black + 1;
	}

	// printf("%d count_black: %d  is_black: %d\n", pre[root], count_black, is_black);
}

// 绝对值排序
int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return abs(*a) - abs(*b);
}

int main() {
	scanf("%d", &K);

	int i, h;
	bool is_black;
	int count_black;
	for (i = 0; i < K; ++i) {
		scanf("%d", &N);
		for (h = 0; h < N; ++h) {
			scanf("%d", pre + h);
			in[h] = pre[h];
		}

		qsort(in, N, sizeof(int), cmp);
		result = true;
		check(0, 0, N - 1, count_black, is_black);
		// 根为黑
		if (result && is_black)
			printf("Yes\n");
		else
			printf("No\n");

	}


	system("pause");
	return 0;
}