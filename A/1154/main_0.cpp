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
int N, M;

// 邻接矩阵
vector<int> edges[N_MAX];
int colors[N_MAX];

// 遍历所有节点，以及每个节点的所有邻接点，判定色彩匹配
bool isOk() {
	int i, h;
	int v, cur_color;
	for (i = 0; i < N; ++i) {
		cur_color = colors[i];
		// 遍历i节点的所有邻接点
		for (h = edges[i].size() - 1; h >= 0; --h) {
			v = edges[i][h];
			if (cur_color == colors[v])
				return false;
		}
	}
	return true;
}

int main() {

	scanf("%d%d", &N, &M);

	int i;
	int v0, v1;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &v0, &v1);
		edges[v0].push_back(v1);
		edges[v1].push_back(v0);
	}

	int K;
	scanf("%d", &K);
	int h;
	// 统计颜色数目
	set<int> set_colors;
	for (i = 0; i < K; ++i) {
		set_colors.clear();
		for (h = 0; h < N; ++h) {
			scanf("%d", colors + h);
			set_colors.insert(colors[h]);
		}

		if (isOk())
			printf("%d-coloring\n", set_colors.size());
		else
			printf("No\n");

	}


	system("pause");
	return 0;
}