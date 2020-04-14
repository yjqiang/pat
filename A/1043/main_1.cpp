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
int N;

int pre[N_MAX];
int post[N_MAX];
int index_post = 0;

// [start, end]为该子树在pre的范围
bool is_BST(int start, int end) {
	if (start > end)
		return true;
	int root = pre[start];
	int i, j;
	for (i = start + 1; i <= end && pre[i] < root; ++i);
	// [start+1, i -1] 左子树   [i, end]右子树
	// 判断BST
	for (j = i; j <= end && pre[j] >= root; ++j);
	if (j <= end)
		return false;

	if (is_BST(start + 1, i - 1) && is_BST(i, end)) {
		post[index_post++] = root;
		return true;
	}
	return false;
}

// [start, end]为该子树在pre的范围
bool is_Mirror_BST(int start, int end) {
	if (start > end)
		return true;
	int root = pre[start];
	int i, j;
	for (i = start + 1; i <= end && pre[i] >= root; ++i);
	// [start+1, i -1] 左子树   [i, end]右子树
	// 判断Mirror_BST
	for (j = i; j <= end && pre[j] < root; ++j);
	if (j <= end)
		return false;

	if (is_Mirror_BST(start + 1, i - 1) && is_Mirror_BST(i, end)) {
		post[index_post++] = root;
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);

	if (is_BST(0, N - 1))
		printf("YES\n");
	else if (is_Mirror_BST(0, N - 1))
		printf("YES\n");
	else {
		printf("NO");
		system("pause");
		return 0;
	}

	printf("%d", post[0]);
	for (i = 1; i < N; ++i)
		printf(" %d", post[i]);

	system("pause");
	return 0;
}