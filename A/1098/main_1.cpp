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

#define N_MAX 101

int orig[N_MAX];
int half_sorted[N_MAX];

// assert n > 0
void print_array(int* array, int n) {
	int i;
	printf("%d", array[0]);
	for (i = 1; i < n; ++i)
		printf(" %d", array[i]);
}

// 向下调整
void adjustDown(int* tree, int k, int n_tree) {
	int i;
	// i 指向左子节点
	for (i = k * 2; i <= n_tree; i *= 2) {
		// 找到孩子节点中最大元素
		if (i + 1 <= n_tree && tree[i + 1] > tree[i])
			i += 1;

		// 判定较大子节点与父节点的大小比较
		if (tree[i] > tree[i / 2])
			swap(tree[i], tree[i / 2]);
		else
			break;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", orig + i);
	for (i = 1; i <= N; ++i)
		scanf("%d", half_sorted + i);

	int num;

	int threshold;  // insert sort 的临界值
	for (i = 1; i <= N && half_sorted[i - 1] <= half_sorted[i]; ++i);
	threshold = i;
	for (; i <= N && half_sorted[i] == orig[i]; ++i);
	if (i == N + 1) {
		printf("Insertion Sort\n");
		num = half_sorted[threshold];
		for (i = threshold - 1; i >= 1 && half_sorted[i] > num; --i)
			half_sorted[i + 1] = half_sorted[i];

		half_sorted[i + 1] = num;

		print_array(half_sorted + 1, N);
	}
	else {
		printf("Heap Sort\n");

		// 大根堆的root在half_sort[1]处
		for (i = N; i >= 2 && half_sorted[i] > half_sorted[1]; --i);
		int n_tree = i;  // 当前大根堆的大小

		swap(half_sorted[1], half_sorted[n_tree]);
		--n_tree;
		adjustDown(half_sorted, 1, n_tree);
		print_array(half_sorted + 1, N);
	}

	system("pause");
	return 0;
}