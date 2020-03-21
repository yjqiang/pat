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

int N;

struct Node {
	int value;
	// 完全二叉树的编号
	int index;
	Node* left, * right;
};

// 右旋
void LL(Node*& A) {
	Node* B = A->left;
	A->left = B->right;
	B->right = A;
	A = B;
}

// 左旋
void RR(Node*& A) {
	Node* B = A->right;
	A->right = B->left;
	B->left = A;
	A = B;
}

void LR(Node*& A) {
	// 左旋
	RR(A->left);
	// 右旋
	LL(A);
}

void RL(Node*& A) {
	// 右旋
	LL(A->right);
	// 左旋
	RR(A);
}

// 求树高
int getHeight(Node* root) {
	if (root == NULL)
		return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void insert(Node*& root, int value) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->left = NULL;
		root->right = NULL;
		root->value = value;
		return;
	}

	if (value < root->value) {
		insert(root->left, value);
		// 加入左子树，最坏只可能是左子树高出右子树，超过1了
		// 递归的机制使得，在最小不平衡树这里首先被调整（LL、LR、RL、RR），再往上追溯，就都平衡了
		if (getHeight(root->left) - getHeight(root->right) > 1) {
			// value不可能在最小不平衡树的左右孩子节点
			if (value < root->left->value)
				LL(root);
			else
				LR(root);

		}

	}
	else {
		insert(root->right, value);
		if (getHeight(root->right) - getHeight(root->left) > 1) {
			// value不可能在最小不平衡树的左右孩子节点
			if (value < root->right->value)
				RL(root);
			else
				RR(root);

		}
	}
}


vector<int> results;

// 层序遍历
bool dfs(Node* root) {
	queue<Node*>q;

	int index;
	Node* cur = root;
	root->index = 1;
	q.push(root);
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		// visit
		results.push_back(cur->value);

		if (cur->left) {
			cur->left->index = 2 * cur->index;
			q.push(cur->left);
		}
		if (cur->right) {
			cur->right->index = 2 * cur->index + 1;
			q.push(cur->right);
		}
	}

	// 最后一点的index标号为N
	return cur->index == N;
}

int main() {
	scanf("%d", &N);

	Node* root = NULL;

	int i;
	int num;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		insert(root, num);
	}

	bool is_complete = dfs(root);
	int n = results.size();
	printf("%d", results[0]);
	for (i = 1; i < n; ++i)
		printf(" %d", results[i]);
	
	printf("\n");
	is_complete ? printf("YES") : printf("NO");

	system("pause");
	return 0;
}