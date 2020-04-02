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

#define N_MAX 100
#define ROOT 1

struct Node {
	int ID;
	vector<int> Child_IDs;
};

// nodes[ID] = 对应node
Node nodes[N_MAX];

// 每一层的叶子节点数目(root第0层)
int leaf_nums_per_level[200] = { 0 };
int max_level = -1;

void dfs(int r, int level) {
	// 更新树高
	max_level = max(max_level, level);

	int n_child = nodes[r].Child_IDs.size();
	// r节点无child，则其为叶子节点
	if (n_child == 0)
		++leaf_nums_per_level[level];
	int i;
	for (i = 0; i < n_child; ++i)
		dfs(nodes[r].Child_IDs[i], level + 1);
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	
	int i, h;
	int ID, K, Child_ID;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &ID, &K);
		for (h = 0; h < K; ++h) {
			scanf("%d", &Child_ID);
			nodes[ID].Child_IDs.push_back(Child_ID);
		}
	}

	dfs(ROOT, 0);
	
	for (i = 0; i <= max_level; ++i) {
		if (i == 0)
			printf("%d", leaf_nums_per_level[i]);
		else
			printf(" %d", leaf_nums_per_level[i]);
	}



	system("pause");
	return 0;
}