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

#define N_MAX 10
struct Node {
	int left_child, right_child;
};

Node nodes[N_MAX];
// 寻找root的位置
bool root_finder[N_MAX] = { false };

// 类似前序遍历
void invert(int root) {
	if (root == -1)
		return;
	swap(nodes[root].left_child, nodes[root].right_child);
	invert(nodes[root].left_child);
	invert(nodes[root].right_child);
}

// 打印时候辅助查看是不是第一个元素
bool is_first;

void levelOrder(int root) {
	queue<int>q;
	q.push(root);

	
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (!is_first)
			printf(" %d", cur);
		else {
			is_first = false;
			printf("%d", cur);
		}

		if (nodes[cur].left_child != -1)
			q.push(nodes[cur].left_child);
		if (nodes[cur].right_child != -1)
			q.push(nodes[cur].right_child);
	}
}

void inOrder(int root) {
	if (root == -1)
		return;

	inOrder(nodes[root].left_child);

	if (!is_first)
		printf(" %d", root);
	else {
		is_first = false;
		printf("%d", root);
	}

	inOrder(nodes[root].right_child);
}

int main() {
	int N;
	scanf("%d", &N);
	// 读回车
	getchar();
	int i;
	char char_left_child, char_right_child;
	int left_child, right_child;

	for (i = 0; i < N; ++i) {
		scanf("%c %c", &char_left_child, &char_right_child);
		if (char_left_child == '-')
			left_child = -1;
		else {
			left_child = char_left_child - '0';
			//root 是从未出现在过child里面
			root_finder[left_child] = true;
		}


		if (char_right_child == '-')
			right_child = -1;
		else {
			right_child = char_right_child - '0';
			//root 是从未出现在过child里面
			root_finder[right_child] = true;
		}
		nodes[i].left_child = left_child;
		nodes[i].right_child = right_child;

		// 回车
		getchar();
	}

	int root;
	for (i = 0; i < N; ++i)
		if (!root_finder[i]) {
			root = i;
			break;
		}

	// printf("%d\n", root);
	invert(root);

	is_first = true;
	levelOrder(root);
	printf("\n");

	is_first = true;
	inOrder(root);
	printf("\n");

	system("pause");
	return 0;
}