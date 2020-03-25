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

#define N_MAX 1001
int N;

// 层序变量序列（从1开始）
int level[N_MAX];

// index 为子树的根在level的下标（完全二叉树编号从1开始）
bool isMaxHeap() {
	int i;
	// 比较该节点与父节点大小
	for (i = N; i >= 2; --i)
		if (level[i / 2] < level[i])
			return false;
	return true;
}

// index 为子树的根在level的下标（完全二叉树编号从1开始）
bool isMinHeap() {
	int i;
	// 比较该节点与父节点大小
	for (i = N; i >= 2; --i)
		if (level[i / 2] > level[i])
			return false;
	return true;
}

bool is_first;
// 转换完全二叉树的层序遍历为后序遍历
// index 为子树的根在level的下标（完全二叉树编号从1开始）
void post(int index) {
	if (index > N)
		return;

	// 左子树
	int left = index * 2;
	post(left);

	// 右子树
	int right = index * 2 + 1;
	post(right);

	if (is_first) {
		printf("%d", level[index]);
		is_first = false;
	}
	else
		printf(" %d", level[index]);
}

int main() {
	int M;
	scanf("%d%d", &M, &N);

	int i, h;
	for (i = 0; i < M; ++i) {
		for (h = 1; h <= N; ++h)
			scanf("%d", level + h);

		if (isMaxHeap())
			printf("Max Heap\n");
		else if (isMinHeap())
			printf("Min Heap\n");
		else
			printf("Not Heap\n");

		is_first = true;
		post(1);
		printf("\n");

	}

	system("pause");
	return 0;
}