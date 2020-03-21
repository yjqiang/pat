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

using namespace std;

struct Node {
	int value;
	Node* left, * right;
};

// �ݹ����
int getHeight(Node* r) {
	if (r == NULL)
		return 0;
	return max(getHeight(r->left), getHeight(r->right)) + 1;
}

// �ҵ���
// �����µĸ��ڵ�
void LL(Node*& A) {
	Node* B = A->left;
	A->left = B->right;
	B->right = A;
	A = B;
}

// ����
// �����µĸ��ڵ�
void RR(Node*& A) {
	Node* B = A->right;
	A->right = B->left;
	B->left = A;
	A = B;
}

// ������(RR)�����ҵ���(LL)
// �����µĸ��ڵ�
void LR(Node*& A) {
	RR(A->left);
	LL(A);
}

// ���ҵ���(LL)��������(RR)
// �����µĸ��ڵ�
void RL(Node*& A) {
	LL(A->right);
	RR(A);
}


// �ݹ������Ԫ�ص�Ҷ�ڵ㣬������ƽ��
// �����µĸ��ڵ�
void insert(Node*& root, int new_value) {
	// ��ǰΪҶ�ڵ�
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->value = new_value;
		root->left = root->right = NULL;
	}
	// ����ݹ��ѯ��Ҷ�ڵ�
	else if (new_value < root->value) {
		insert(root->left, new_value);
		// �������������ֻ�������������߳�������������1��
		// �ݹ�Ļ���ʹ�ã�����С��ƽ�����������ȱ�������LL��LR��RL��RR����������׷�ݣ��Ͷ�ƽ����
		if (getHeight(root->left) - getHeight(root->right) > 1) {
			// LL
			if (new_value < root->left->value)
				LL(root);
			else // LR
				LR(root);
		}
	}
	else {
		insert(root->right, new_value);
		// �������������ֻ�������������߳�������������1��
		// �ݹ�Ļ���ʹ�ã�����С��ƽ�����������ȱ�������LL��LR��RL��RR����������׷�ݣ��Ͷ�ƽ����
		if (getHeight(root->right) - getHeight(root->left) > 1) {
			// RL
			if (new_value < root->right->value)
				RL(root);
			else // RR
				RR(root);
		}
	}

}

int main() {
	int N;
	scanf("%d", &N);

	int i, new_value;
	Node* root = NULL;
	for (i = 0; i < N; ++i) {
		scanf("%d", &new_value);
		// ���ϸ���root
		insert(root, new_value);
	}
	printf("%d", root->value);
	
	system("pause");
	return 0;
}