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

int pre[N_MAX];

struct Node {
	int value;
	Node* left, * right;
	Node* parent;  // ���ڵ�
	int level; // �ڼ���
};

// ������pre�ķ�Χ�������䣩
void createTree(int start, int end, Node* &r, Node* parent, int level) {
	if (start > end) {
		r = NULL;
		return;
	}

	int root = pre[start];
	r = (Node*)malloc(sizeof(Node));
	r->value = root;
	r->parent = parent;
	r->level = level;

	// ������С��rootֵ�����������ڵ���root
	int i;
	for (i = start + 1; i <= end && pre[i] < root; ++i);
	createTree(start + 1, i - 1, r->left, r, level + 1);
	createTree(i, end, r->right, r, level + 1);
}

void mySearch(int U, int V, Node* root) {
	// ��¼U V����·����ĳ��
	Node* node_U, * node_V;

	// �� root ��ʼ����
	node_U = node_V = root;
	while (node_U) {
		if (U < node_U->value)
			node_U = node_U->left;
		else if (U > node_U->value)
			node_U = node_U->right;
		else
			break;
	}
	while (node_V) {
		if (V < node_V->value)
			node_V = node_V->left;
		else if (V > node_V->value)
			node_V = node_V->right;
		else
			break;
	}
	if (node_U == NULL && node_V == NULL)
		printf("ERROR: %d and %d are not found.\n", U, V);
	else if (node_U == NULL)
		printf("ERROR: %d is not found.\n", U);
	else if (node_V == NULL)
		printf("ERROR: %d is not found.\n", V);
	else {
		int level_U = node_U->level, level_V = node_V->level;

		// �����߶ȵ�һ��(���root)
		while (node_U != node_V) {
			if (level_U < level_V) {
				--level_V;
				node_V = node_V->parent;
			}
			else if (level_U > level_V) {
				--level_U;
				node_U = node_U->parent;
			}
			else {
				--level_V;
				node_V = node_V->parent;
				--level_U;
				node_U = node_U->parent;
			}
		}
		// ����һ��δŲ�ѣ�˵���õ�����һ����游�ڵ�
		if (node_U->value == U)
			printf("%d is an ancestor of %d.\n", U, V);
		else if (node_V->value == V)
			printf("%d is an ancestor of %d.\n", V, U);

		else
			printf("LCA of %d and %d is %d.\n", U, V, node_V->value);
	}

}

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);

	Node* root = NULL;
	createTree(0, N - 1, root, NULL, 0);

	int U, V;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &U, &V);
		mySearch(U, V, root);
	}

	system("pause");
	return 0;
}