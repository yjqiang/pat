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
	// ��ȫ�������ı��
	int index;
	Node* left, * right;
};

// ����
void LL(Node*& A) {
	Node* B = A->left;
	A->left = B->right;
	B->right = A;
	A = B;
}

// ����
void RR(Node*& A) {
	Node* B = A->right;
	A->right = B->left;
	B->left = A;
	A = B;
}

void LR(Node*& A) {
	// ����
	RR(A->left);
	// ����
	LL(A);
}

void RL(Node*& A) {
	// ����
	LL(A->right);
	// ����
	RR(A);
}

// ������
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
		// �������������ֻ�������������߳�������������1��
		// �ݹ�Ļ���ʹ�ã�����С��ƽ�����������ȱ�������LL��LR��RL��RR����������׷�ݣ��Ͷ�ƽ����
		if (getHeight(root->left) - getHeight(root->right) > 1) {
			// value����������С��ƽ���������Һ��ӽڵ�
			if (value < root->left->value)
				LL(root);
			else
				LR(root);

		}

	}
	else {
		insert(root->right, value);
		if (getHeight(root->right) - getHeight(root->left) > 1) {
			// value����������С��ƽ���������Һ��ӽڵ�
			if (value < root->right->value)
				RL(root);
			else
				RR(root);

		}
	}
}


vector<int> results;

// �������
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

	// ���һ���index���ΪN
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