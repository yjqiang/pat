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
#include <unordered_map>

using namespace std;

#define N_MAX 10000

// 快速查找value与对应的节点(在in的下标)
unordered_map<int, int>indices;

int pre[N_MAX];
int in[N_MAX];

// UV 在in的下标
int position_U, position_V;

// root 为该子树的根在pre中下标
// [start, end]为该子树在in的范围（闭区间）
// 返回LCA值在in的下标
int LCA(int root, int start, int end) {
	int i;
	int value_root = pre[root];
	for (i = start; in[i] != pre[root]; ++i);

	// 同在本子树的左子树部分
	if (position_U < i && position_V < i)
		return LCA(root + 1, start, i - 1);
	// 同在本子树的右子树部分
	else if(i < position_U && i < position_V)
		return LCA(root + i + 1 - start, i + 1, end);
	return i;
}


int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int i;
	for (i = 0; i < N; ++i) {
		scanf("%d", in + i);
		indices[in[i]] = i;
	}
	for (i = 0; i < N; ++i)
		scanf("%d", pre + i);

	
	int U, V;
	bool is_exist_U, is_exist_V;
	int position_LCA;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &U, &V);

		is_exist_U = indices.find(U) != indices.end();
		is_exist_V = indices.find(V) != indices.end();
		if (!is_exist_U && !is_exist_V)
			printf("ERROR: %d and %d are not found.\n", U, V);
		else if (!is_exist_U)
			printf("ERROR: %d is not found.\n", U);
		else if (!is_exist_V)
			printf("ERROR: %d is not found.\n", V);
		else {
			position_U = indices[U];
			position_V = indices[V];
			position_LCA = LCA(0, 0, N - 1);
			// 祖先节点就是U
			if (position_LCA == position_U)
				printf("%d is an ancestor of %d.\n", U, V);
			else if (position_LCA == position_V)
				printf("%d is an ancestor of %d.\n", V, U);
			else
				printf("LCA of %d and %d is %d.\n", U, V, in[position_LCA]);
		}

	}

	system("pause");
	return 0;
}