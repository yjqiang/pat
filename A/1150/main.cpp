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

#define N_MAX 201

// 邻接矩阵
int edges[N_MAX][N_MAX] = { 0 };
bool visited[N_MAX];


int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i, h;
	int city1, city2, dist;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &city1, &city2, &dist);
		edges[city1][city2] = edges[city2][city1] = dist;
	}
	int pre_city, city;

	int K, n;
	scanf("%d", &K);
	// 起点
	int start;
	// 两点直接是否都有边
	bool is_edge_ok;
	// 所有点都访问了
	bool all_visited;

	int path_dist;
	int min_dist, min_index;
	min_dist = INT_MAX;
	for (i = 1; i <= K; ++i) {
		// init
		for (h = 1; h <= N; ++h)
			visited[h] = false;
		is_edge_ok = true;
		all_visited = true;
		path_dist = 0;

		scanf("%d %d", &n, &start);
		pre_city = start;
		
		
		// 为了节省空间（n尼玛没给上限啊，我也不想这么恶心逻辑啊）
		for (h = 1; h < n; ++h) {
			scanf("%d", &city);
			// 所给的dist都是大于0的，默认为0
			if (!edges[city][pre_city])
				is_edge_ok = false;
			path_dist += edges[city][pre_city];
			visited[city] = true;

			pre_city = city;
		}
		
		// 是否有点未遍历的
		for (h = 1; h <= N; ++h)
			if (!visited[h]) {
				all_visited = false;
				break;
			}

		// 边正确、点全遍历、首尾对应 => TS cycle

		if (!is_edge_ok)  // edge不对，计数作废
			printf("Path %d: NA (Not a TS cycle)\n", i);
		else {
			// 是个 TS cycle了
			if (all_visited && city == start) {
				if (min_dist > path_dist) {
					min_dist = path_dist;
					min_index = i;
				}

				if (n == N + 1)
					printf("Path %d: %d (TS simple cycle)\n", i, path_dist);
				else
					printf("Path %d: %d (TS cycle)\n", i, path_dist);
			}
			else
				printf("Path %d: %d (Not a TS cycle)\n", i, path_dist);
		}

	}
	printf("Shortest Dist(%d) = %d", min_index, min_dist);

	system("pause");
	return 0;
}