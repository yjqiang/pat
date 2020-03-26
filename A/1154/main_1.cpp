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

struct Edge {
	int v0, v1;
};

// 只存边
vector<Edge> edges;
int colors[N_MAX];

// 遍历所有边，判定色彩匹配
bool isOk() {
	int i, h;
	int v0, v1;
	for (i = 0; i < M; ++i) {
		v0 = edges[i].v0;
		v1 = edges[i].v1;
		if (colors[v0] == colors[v1])
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M);

	int i;
	int v0, v1;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &v0, &v1);
		edges.push_back(Edge{ v0, v1 });
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