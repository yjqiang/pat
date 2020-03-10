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

#define N_MAX 1001
int N;
// index从1开始
int sorted[N_MAX];

// index从1开始
// 最终建立的树（完全二叉树表示法）
int a[N_MAX];

// index从1开始
// 表示（完全二叉树表示法）下标为i的子树的大小，完全二叉树表示法也从1开始标号
int subtree_nums[N_MAX] = { 0 };

int cmp(const void* p0, const void* p1) {
	int* i0 = (int*)p0;
	int* i1 = (int*)p1;
	return (*i0) - (*i1);
}

// 前序遍历建立子树a[i];left和right为sorted对应的该子树的下标范围
void pre(int i, int left, int right) {
	if (left > right)
		return;
	// 左子树的大小
	int size_left_tree = (i * 2 <= N) ? subtree_nums[i * 2] : 0;
	// parent赋值
	a[i] = sorted[left + size_left_tree];

	pre(i * 2, left, left + size_left_tree - 1);
	pre(i * 2 + 1, left + size_left_tree + 1, right);
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", sorted + i);
	// 从小到大
	qsort(sorted + 1, N, sizeof(int), cmp);
	
	// 建立 subtree_nums，已经初始化为0
	for (i = N; i >= 0; --i) {
		if (2 * i <= N)  // 左子树
			subtree_nums[i] += subtree_nums[2 * i];
		if (2 * i + 1 <= N)  // 右子树
			subtree_nums[i] += subtree_nums[2 * i + 1];
		// parent节点自身
		++subtree_nums[i];
	}
	
	pre(1, 1, N);

	printf("%d", a[1]);
	for (i = 2; i <= N; ++i)
		printf(" %d", a[i]);

	system("pause");
	return 0;
}