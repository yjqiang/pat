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

#define N_MAX 501
// 源点
#define START 0

int C_max, N, S_p, M;

// 邻接矩阵(time)
// INT_MAX 表示无边
int edges[N_MAX][N_MAX];
// 每点的车子数目
int num_bikes[N_MAX];



// dijkstra使用
// 是否已经收入S里面
bool is_in_set[N_MAX];
// 记录最短路径长度
int path_dists[N_MAX];
// 记录路径回溯，即给定的最短路径(path_dists[i])下，前缀点的数组(0->...->前缀点->i 为最短路径)
// 注意最短路径可能多条，可能对应多个前缀点
vector<int> path_neighbours[N_MAX];

// 从start带出来的，跑完后带回start的车子数目
int min_bring_from = INT_MAX, min_bring_back = INT_MAX;
// 对应最佳路径
vector<int>result;
vector<int> tmp;
void dfs(int vex) {
	int i;
	// 等于源点了
	if (vex == START) {
		// 沿路径统计
		int bring_from = 0, bring_back = 0;
		int difference;
		// 路径是倒着的
		for (i = tmp.size() - 1; i >= 0; --i) {
			difference = num_bikes[tmp[i]] - C_max / 2;
			// 车子多了，就积攒起来了
			if (difference >= 0)
				bring_back += difference;
			// 车子缺了，就把沿途从start攒起来的车子投进去;可能还得再多带一点车子（从start那里）
			else {
				difference = -difference;
				if (bring_back >= difference)
					bring_back -= difference;
				else {
					// 注意顺序，先扣除bring_back,表示沿途收集的车子全填到这个缺口里，然后把bring_back归零
					bring_from += difference - bring_back;
					bring_back = 0;
				}
			}
		}

		if (bring_from < min_bring_from) {
			result = tmp;
			min_bring_from = bring_from;
			min_bring_back = bring_back;
		}
		else if (bring_from == min_bring_from && bring_back < min_bring_back) {
			result = tmp;
			min_bring_back = bring_back;
		}
		return;
	}

	int n_size = path_neighbours[vex].size();
	tmp.push_back(vex);
	for (i = 0; i < n_size; ++i)
		dfs(path_neighbours[vex][i]);
	tmp.pop_back();

}

int main() {
	scanf("%d %d %d %d", &C_max, &N, &S_p, & M);

	int i, h;
	num_bikes[0] = 0;
	for (i = 1; i <= N; ++i)
		scanf("%d", num_bikes + i);

	for (i = 0; i <= N; ++i)
		for (h = 0; h <= N; ++h)
			// 清理所有边
			edges[i][h] = INT_MAX;

	int S_i, S_j, T_ij;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &S_i, &S_j, &T_ij);
		edges[S_i][S_j] = edges[S_j][S_i] = T_ij;
	}



	// 下面全是dijkstra
	for (i = 0; i <= N; ++i) {
		is_in_set[i] = false;
		path_dists[i] = INT_MAX;
	}

	// 把源点放入set
	int cur = START;
	is_in_set[START] = true;
	path_dists[START] = 0;

	// 松弛路径后挑选最短路径
	int min_dist, min_index;

	// 其他变量
	int cur_dist;

	// 实际有N+1个点，所以循环N次
	for (i = 1; i <= N; ++i) {
		// 松弛cur邻接点的路径
		for (h = 0; h <= N; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX) {
				// 若h以cur为前缀节点，计算对应参数
				cur_dist = path_dists[cur] + edges[h][cur];

				if (cur_dist < path_dists[h]) {
					path_dists[h] = cur_dist;
					// 更新前缀点
					path_neighbours[h].clear();
					path_neighbours[h].push_back(cur);
				}
				// 有相同长度的路径
				else if (cur_dist == path_dists[h]) {
					// 更新前缀点
					path_neighbours[h].push_back(cur);
				}
			}

		// 找最小值，放入S
		min_dist = INT_MAX;
		for (h = 0; h <= N; ++h)
			if (!is_in_set[h] && path_dists[h] < min_dist) {
				min_dist = path_dists[h];
				min_index = h;
			}

		// 放入S
		is_in_set[min_index] = true;
		cur = min_index;
	}

	// 回溯最短路径，找到最要求符合的路径（the least number of bikes sent from PBMC；requires minimum number of bikes that we must take back to PBMC）
	dfs(S_p);

	printf("%d 0", min_bring_from);
	for (i = result.size()-1; i >= 0; --i)
		printf("->%d", result[i]);
	printf(" %d", min_bring_back);

	system("pause");
	return 0;
}