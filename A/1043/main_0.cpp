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
// 正向二叉搜索树的中序遍历是递增
int sorted[N_MAX];
// 镜像二叉搜索树的中序是递减
int revert_sorted[N_MAX];

vector<int> post;

int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;
	return (*a) - (*b);
}

//  正向二叉搜索树的中序遍历建立树的时候，对应root有重复的元素，一定选最左侧的，否则，左子树会有元素与root相等的，不符合要求
bool checkPost_sorted(int root, int start, int end) {
	if (start > end)
		return true;
	int i;
	for (i = start; i <= end; ++i)
		if (sorted[i] == pre[root]) {

			if (checkPost_sorted(root + 1, start, i - 1) && checkPost_sorted(root + i + 1 - start, i + 1, end)) {
				// 中序+前序 可能多棵树 eg： 1 1 1 1 1，1 1 1 1 1
				post.push_back(pre[root]);
				return true;			
			}
			return false;
		}
	return false;
}

//  镜像二叉搜索树的中序遍历建立树的时候，对应root有重复的元素，一定选最右侧的，否则，右子树会有元素与root相等的，不符合要求
bool checkPost_revert_sorted(int root, int start, int end) {
	if (start > end)
		return true;
	int i;
	for (i = end; i >= start; --i)
		if (revert_sorted[i] == pre[root]) {
			if (checkPost_revert_sorted(root + 1, start, i - 1) && checkPost_revert_sorted(root + i + 1 - start, i + 1, end)) {
				// 中序+前序 可能多棵树 eg： 1 1 1 1 1，1 1 1 1 1
				post.push_back(pre[root]);
				return true;
			}
			return false;
		}
	return false;
}

int main() {

	scanf("%d", &N);

	int i;
	int num;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		pre[i] = num;
		sorted[i] = num;
	}
	qsort(sorted, N, sizeof(int), cmp);
	for (i = 0; i < N; ++i)
		revert_sorted[N - 1 - i] = sorted[i];


	if (checkPost_sorted(0, 0, N - 1)) {
		printf("YES\n");
		printf("%d", post[0]);
		for (i = 1; i < post.size(); ++i)
			printf(" %d", post[i]);
		system("pause");
		return 0;
	}
	post.clear();
	if (checkPost_revert_sorted(0, 0, N - 1)) {
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