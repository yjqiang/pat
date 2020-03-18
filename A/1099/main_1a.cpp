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

struct Node {
	int value;
	int left_index, right_index;
};

Node nodes[N_MAX];
int nums[N_MAX];

int cmp_int(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}


// 指示mid的下标
int count_mid = 0;
// root 为当前子树的根
// index 为满二叉树的编号办法，从1开始
void mid(int root) {
	if (root == -1)
		return;

	mid(nodes[root].left_index);

	nodes[root].value = nums[count_mid++];

	mid(nodes[root].right_index);
}

// 方法1：可以直接层序遍历
void levelOrder(int root)
{
	queue<Node> q;
	int pos = 0;
	q.push(nodes[root]);
	Node cur;

	bool is_first = true;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (!is_first)
			printf(" %d", cur.value);
		else {
			is_first = false;
			printf("%d", cur.value);
		}

		if (cur.left_index != -1)
			q.push(nodes[cur.left_index]);
		if (cur.right_index != -1)
			q.push(nodes[cur.right_index]);
	}
}


int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d%d", &(nodes[i].left_index), &(nodes[i].right_index));

	for (i = 0; i < N; ++i)
		scanf("%d", nums + i);

	// 从小到大对nums排序
	qsort(nums, N, sizeof(int), cmp_int);

	mid(0);

	levelOrder(0);

	system("pause");
	return 0;
}