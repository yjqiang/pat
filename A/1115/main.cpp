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

#define N_MAX 10000

struct Node {
	int value;
	Node* left,* right; // NULL表示无
};


// 指针引用
void myInsert(Node* & root, int num) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->value = num;
		root->left = NULL;
		root->right = NULL;
		return;
	}

	if (num <= root->value)
		myInsert(root->left, num);
	else
		myInsert(root->right, num);

}

// bfs中每层的节点个数
vector<int> counts_per_level;

void bfs(Node* root) {
	queue<Node*> q;
	q.push(root);

	int count_per_level;
	Node* cur;
	int i;
	while (!q.empty()) {
		// 本层的节点数目
		count_per_level = q.size();

		for (i = 0; i < count_per_level; ++i) {
			cur = q.front();
			q.pop();

			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}

		counts_per_level.push_back(count_per_level);

	}
}

int main() {
	int N;
	scanf("%d", &N);
	
	Node* root = NULL;

	int num;
	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		myInsert(root, num);
	}
	
	bfs(root);

	int n_size = counts_per_level.size();
	int n1 = counts_per_level[n_size - 1];
	int n2 = counts_per_level[n_size - 2];
	printf("%d + %d = %d", n1, n2, n1 + n2);
	
	system("pause");
	return 0;
}