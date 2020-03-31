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

#define N_MAX 500

// 邻接矩阵
// INT_MAX 表示无边
int edges[N_MAX][N_MAX];
// 记录每个点的teams数目
int num_teams[N_MAX];


// dijkstra使用
// 是否已经收入S里面
bool is_in_set[N_MAX];
// 最短路径条数
int path_counts[N_MAX];
// 记录最短路径长度
int path_dists[N_MAX];
// start到本点的最短路径上的最大team数目
int path_num_teams[N_MAX];


int main() {
	int N, M, C1, C2;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);

	int i, h;
	for (i = 0; i < N; ++i)
		scanf("%d", num_teams + i);

	for (i = 0; i < N; ++i)
		for (h = 0; h < N; ++h)
			// 清理所有边
			edges[i][h] = INT_MAX;

	// 注意C1c1  C2c2区别，按照sb题目里面的，C为start end的编号，c就是点的通用编号
	int c1, c2, L;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &c1, &c2, &L);
		edges[c1][c2] = edges[c2][c1] = L;
	}



	// 下面全是dijkstra
	for (i = 0; i < N; ++i) {
		is_in_set[i] = false;
		path_counts[i] = 0;
		path_dists[i] = INT_MAX;
		path_num_teams[i] = 0;
	}

	// 把C1源点放入set
	int cur = C1;
	is_in_set[C1] = true;
	path_counts[C1] = 1;
	path_dists[C1] = 0;
	path_num_teams[C1] = num_teams[C1];

	// 松弛路径后挑选最短路径
	int min_dist, min_index;

	// 其他变量
	int cur_dist, cur_num_teams;

	for (i = 1; i < N; ++i) {
		// 松弛cur邻接点的路径
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX) {
				// 若h以cur为前缀节点，计算对应参数
				cur_dist = path_dists[cur] + edges[h][cur];
				cur_num_teams = path_num_teams[cur] + num_teams[h];

				if (cur_dist < path_dists[h]) {
					path_dists[h] = cur_dist;
					path_num_teams[h] = cur_num_teams;
					// 长为cur_dist从C1到h的路径条数，等于C1到cur的最短路径条数
					path_counts[h] = path_counts[cur];
				}
				// 有相同长度的路径
				else if (cur_dist == path_dists[h]) {
					// 长为cur_dist从C1到h的路径条数，等于原来的数据，加上C1到cur的最短路径条数
					path_counts[h] += path_counts[cur];
					if(cur_num_teams > path_num_teams[h])
						path_num_teams[h] = cur_num_teams;
				}
			}

		// 找最小值，放入S
		min_dist = INT_MAX;
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && path_dists[h] < min_dist) {
				min_dist = path_dists[h];
				min_index = h;
			}

		// 放入S
		is_in_set[min_index] = true;
		cur = min_index;
	}

	printf("%d %d", path_counts[C2], path_num_teams[C2]);

	system("pause");
	return 0;
}