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

// 递归求高
int getHeight(Node* r) {
	if (r == NULL)
		return 0;
	return max(getHeight(r->left), getHeight(r->right)) + 1;
}

// 右单旋
// 返回新的父节点
Node* LL(Node* A) {
	Node* B = A->left;
	A->left = B->right;
	B->right = A;
	return B;
}

// 左单旋
// 返回新的父节点
Node* RR(Node* A) {
	Node* B = A->right;
	A->right = B->left;
	B->left = A;
	return B;
}

// 先左单旋(RR)，后右单旋(LL)
// 返回新的父节点
Node* LR(Node* A) {
	A->left = RR(A->left);
	return LL(A);
}

// 先右单旋(LL)，后左单旋(RR)
// 返回新的父节点
Node* RL(Node* A) {
	A->right = LL(A->right);
	return RR(A);
}


// 递归插入新元素到叶节点，并调整平衡
// 返回新的父节点
Node* insert(Node* root, int new_value) {
	// 当前为叶节点
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->value = new_value;
		root->left = root->right = NULL;
	}
	// 否则递归查询至叶节点
	else if (new_value < root->value) {
		root->left = insert(root->left, new_value);
		// 加入左子树，最坏只可能是左子树高出右子树，超过1了
		// 递归的机制使得，在最小不平衡树这里首先被调整（LL、LR、RL、RR），再往上追溯，就都平衡了
		if (getHeight(root->left) - getHeight(root->right) > 1) {
			// LL
			if (new_value < root->left->value)
				root = LL(root);
			else // LR
				root = LR(root);
		}
	}
	else {
		root->right = insert(root->right, new_value);
		// 加入右子树，最坏只可能是右子树高出右子树，超过1了
		// 递归的机制使得，在最小不平衡树这里首先被调整（LL、LR、RL、RR），再往上追溯，就都平衡了
		if (getHeight(root->right) - getHeight(root->left) > 1) {
			// RL
			if (new_value < root->right->value)
				root = RL(root);
			else // RR
				root = RR(root);
		}
	}
	return root;

}

int main() {
	int N;
	scanf("%d", &N);

	int i, new_value;
	Node* root = NULL;
	for (i = 0; i < N; ++i) {
		scanf("%d", &new_value);
		// 不断更新root
		root = insert(root, new_value);
	}
	printf("%d", root->value);
	
	system("pause");
	return 0;
}