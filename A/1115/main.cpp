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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 1000

struct Node {
	int value;
	Node* left, * right;
};


void bfs(Node* root) {
	queue<Node*>q;
	q.push(root);

	int i, h;
	Node* cur;
	// n1��ʾ������һ�㣬n2��ʾ�����ڶ���
	int n1, n2;
	int nodes_num_per_level;

	// n1 = n2 = -1;
	n1 = n2 = 0;
	while (!q.empty()) {
		nodes_num_per_level = q.size();
		// ������һ����һ���n1���ڳ��˱����n2
		n2 = n1;
		n1 = nodes_num_per_level;

		for (i = 0; i < nodes_num_per_level; ++i) {
			cur = q.front();
			q.pop();

			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}

	}
	// �������ܾ�һ��
	//if (n2 == -1)
	//	exit(-1);
	printf("%d + %d = %d", n1, n2, n1 + n2);
}


void insert(int value, Node*& cur) {
	if (cur == NULL) {
		cur = (Node*)malloc(sizeof(Node));
		cur->value = value;
		cur->left = cur->right = NULL;
		return;
	}
	if (value <= cur->value)
		insert(value, cur->left);
	else
		insert(value, cur->right);
}

int main() {
	int N;
	scanf("%d", &N);

	int i, h;
	int value;

	Node* root = NULL;
	for (i = 0; i < N; ++i) {
		scanf("%d", &value);

		insert(value, root);
	}

	bfs(root);

	system("pause");
	return 0;
}