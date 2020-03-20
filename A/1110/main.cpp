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

#define N_MAX 20

struct Node {
	int left_child, right_child;
};
Node nodes[N_MAX];

// root 从来未在child_ID序列中出现过
bool root_checker[N_MAX] = { false };

// 二叉树的编号（完全二叉树）
int max_ID = -1;
// 最大编号的对应index
int max_index;

void dfs(int r, int ID) {
	if (r == -1)
		return;

	dfs(nodes[r].left_child, ID * 2);

	if (ID > max_ID) {
		max_ID = ID;
		max_index = r;
	}

	dfs(nodes[r].right_child, ID * 2 + 1);
}

int main() {
	int N;
	scanf("%d", &N);

	char s0[3], s1[3];
	int i;
	int child;
	for (i = 0; i < N; ++i) {
		scanf("%s %s", s0, s1);
		if (s0[0] == '-')
			nodes[i].left_child = -1;
		else {
			sscanf(s0, "%d", &child);
			nodes[i].left_child = child;
			root_checker[child] = true;
		}

		if (s1[0] == '-')
			nodes[i].right_child = -1;
		else {
			sscanf(s1, "%d", &child);
			nodes[i].right_child = child;
			root_checker[child] = true;
		}
	}
	
	// 找到root
	int root;
	for (i = 0; root_checker[i]; ++i);
	root = i;

	// 模仿完全二叉树编号
	dfs(root, 1);

	if (max_ID == N)
		printf("YES %d", max_index);
	else
		printf("NO %d", root);

	system("pause");
	return 0;
}