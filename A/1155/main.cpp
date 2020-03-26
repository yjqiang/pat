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

// 从1开始编号
int level[N_MAX];

bool isMaxHeap() {
	int i;
	for (i = N; i >= 2; --i)
		if (level[i / 2] < level[i])
			return false;
	return true;
}

bool isMinHeap() {
	int i;
	for (i = N; i >= 2; --i)
		if (level[i / 2] > level[i])
			return false;
	return true;
}

vector<int>tmp;
void check(int index) {
	int left = 2 * index;
	int right = 2 * index + 1;

	tmp.push_back(level[index]);
	// 没有左子树 <==> 叶子节点
	if (left > N) {
		int i;
		printf("%d", tmp[0]);
		for (i = 1; i < tmp.size(); ++i)
			printf(" %d", tmp[i]);
		printf("\n");
	}
	else {
		if (right <= N)
			check(right);
		if (left <= N)
			check(left);
	}
	tmp.pop_back();
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", level + i);

	check(1);
	if (isMaxHeap())
		printf("Max Heap");
	else if (isMinHeap())
		printf("Min Heap");
	else
		printf("Not Heap");

	system("pause");
	return 0;
}