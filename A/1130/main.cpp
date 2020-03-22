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

#define N_MAX 21

struct Node {
	char data[11];
	int left_child, right_child;
};

// 使用数组存储点，nodes[i].left_child/right_child 指示了左右孩子
Node nodes[N_MAX];

// root 从未在child序列出现
bool is_root[N_MAX] = {false};

int root;

void inOrder(int t) {
	if (t == -1)
		return;
	// 非叶子结点且非根，打印括号
	if (t != root && (nodes[t].left_child != -1 || nodes[t].right_child != -1))
		printf("(");
	inOrder(nodes[t].left_child);
	printf("%s", nodes[t].data);
	inOrder(nodes[t].right_child);
	if (t != root && (nodes[t].left_child != -1 || nodes[t].right_child != -1))
		printf(")");
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 1; i <= N; ++i) {
		scanf("%s %d %d", nodes[i].data, &(nodes[i].left_child), &(nodes[i].right_child));
		
		if (nodes[i].left_child != -1)
			is_root[nodes[i].left_child] = true;
		if (nodes[i].right_child != -1)
			is_root[nodes[i].right_child] = true;
	}

	for (i = 1; is_root[i]; ++i);
	root = i;

	inOrder(root);

	system("pause");
	return 0;
}