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

#define N_MAX 10000

struct Node {
	int value;
	int level; // 层数
	Node* left,* right;
	Node* parent;
};

// 快速查找value与对应的节点
map<int, Node*>indices;

int pre[N_MAX];
int in[N_MAX];


// root 为该子树的根在pre中下标
// [start, end]为该子树在in的范围（闭区间）
void createTree(Node*& r, Node* parent, int level, int root, int start, int end) {
	if (start > end) {
		r = NULL;
		return;
	}
	int i;
	for (i = start; in[i] != pre[root]; ++i);

	r = (Node*)malloc(sizeof(Node));
	r->value = pre[root];
	r->parent = parent;
	r->level = level;
	// map
	indices[pre[root]] = r;

	createTree(r->left, r, level + 1, root + 1, start, i - 1);
	createTree(r->right, r, level + 1, root + i + 1 - start, i + 1, end);
}


int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", in + i);
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);

	Node* root = NULL;
	createTree(root, NULL, 0, 0, 0, N - 1);
	
	int U, V;
	bool is_exist_U, is_exist_V;
	Node* node_U, * node_V;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &U, &V);

		is_exist_U = indices.find(U) != indices.end();
		is_exist_V = indices.find(V) != indices.end();
		if (!is_exist_U && !is_exist_V)
			printf("ERROR: %d and %d are not found.\n", U, V);
		else if (!is_exist_U)
			printf("ERROR: %d is not found.\n", U);
		else if (!is_exist_V)
			printf("ERROR: %d is not found.\n", V);
		else {
			node_U = indices[U];
			node_V = indices[V];
			// 不断上调level,以寻找最低祖先节点
			while (node_U != node_V) {
				if (node_U->level > node_V->level)
					node_U = node_U->parent;
				else
					node_V = node_V->parent;
			}
			// 祖先节点就是U
			if (node_U->value == U)
				printf("%d is an ancestor of %d.\n", U, V);
			else if (node_V->value == V)
				printf("%d is an ancestor of %d.\n", V, U);
			else
				printf("LCA of %d and %d is %d.\n", U, V, node_U->value);
		}

	}

	system("pause");
	return 0;
}