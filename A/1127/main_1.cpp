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

#define N_MAX 35

struct Node {
	int value;
	Node* left, * right;
};

// 后序
int post[N_MAX];
// 中序
int in[N_MAX];

void createTree(int root, int start, int end, Node*& t) {
	// root 为本子树中根在post的下标
	// [start, end]为本子树在in中的范围
	if (start > end) {
		t = NULL;
		return;
	}
	
	int i;
	for (i = start; in[i] != post[root]; ++i);

	t = (Node*)malloc(sizeof(Node));
	t->value = post[root];

	createTree(i + root - end - 1, start, i - 1, t->left);
	createTree(root - 1, i + 1, end, t->right);
}

// levels[i] 第i层的节点
// 35个节点，最大35层
vector<Node*> levels[N_MAX];

// 把每一层的节点从左到右，写入数组levels[level]
void bfs(Node* root) {
	queue<Node*> q;
	q.push(root);

	int level = 0;
	int size_cur_level;
	Node* t;
	int i;
	while (!q.empty()) {
		size_cur_level = q.size();

		for (i = 0; i < size_cur_level; ++i) {
			t = q.front();
			q.pop();

			levels[level].push_back(t);
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
		++level;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", in + i);
	for (i = 0; i < N; ++i)
		scanf("%d", post + i);

	Node* root = NULL;
	createTree(N - 1, 0, N - 1, root);

	bfs(root);

	int n_size;
	printf("%d", root->value);
	int h;
	for (i = 1; i < N_MAX; i++) {
		n_size = levels[i].size();
		if (i % 2 == 1) {
			for (h = 0; h < n_size; ++h)
				printf(" %d", levels[i][h]->value);
		}
		else {
			for (h = n_size - 1; h >= 0; --h)
				printf(" %d", levels[i][h]->value);
		}
	}

	system("pause");
	return 0;
}