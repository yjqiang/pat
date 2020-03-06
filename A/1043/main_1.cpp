#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 1000
int N;
int pre[N_MAX];
bool isMirror;
vector<int> post;

// left right 为pre片段的左右端点，root在left上
bool checkPost(int left, int right) {
	if (left > right)
		return true;

	int root = pre[left];
	// i负责寻找左子树的右端点，k找右子树的左端点
	int i, k;
	if (!isMirror) {
		for (i = left + 1; i <= right && pre[i] < root; ++i);
		--i;

		for (k = right; k >= left+1 && pre[k] >= root; --k);
		++k;
	}
	else {
		for (i = left + 1; i <= right && pre[i] >= root; ++i);
		--i;

		for (k = right; k >= left + 1 && pre[k] < root; --k);
		++k;
	}
	if (k - i != 1)
		return false;
	if (checkPost(left + 1, i) && checkPost(k, right)) {
		post.push_back(root);
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);

	int i;
	int num;
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);

	// 先测试镜像
	isMirror = true;


	if (checkPost(0, N - 1)) {
		printf("YES\n");
		printf("%d", post[0]);
		for (i = 1; i < post.size(); ++i)
			printf(" %d", post[i]);
		system("pause");
		return 0;
	}

	// 先测试BFS
	isMirror = false;
	post.clear();
	if (checkPost(0, N - 1)) {
		printf("YES\n");
		printf("%d", post[0]);
		for (i = 1; i < post.size(); ++i)
			printf(" %d", post[i]);
		system("pause");
		return 0;
	}

	printf("NO\n");

	system("pause");
	return 0;
}