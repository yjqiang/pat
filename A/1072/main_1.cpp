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

using namespace std;

#define N_MAX 1001
#define M_MAX 11
// SUM_MAX = N_MAX + M_MAX
#define SUM_MAX 1012

int N, M, K, D_s;

// 邻接矩阵；Gi => N + i，把Gi加在房子编号后面  
int edges[SUM_MAX][SUM_MAX];

// 每个加油站候选点都要进行一次dijkstra
int dists[SUM_MAX];
// dijkstra是否在集合里面了
bool is_in_set[SUM_MAX];

// Gi => N + i，把Gi加在房子编号后面 
int strP2intP(char* s) {
	int result;
	if (s[0] == 'G') {
		sscanf(s, "G%d", &result);
		result += N;
	}
	else
		sscanf(s, "%d", &result);
	return result;
}

void dijkstra(int start) {
	int i, h;
	// 全部不可达
	for (i = 0; i < SUM_MAX; ++i)
		dists[i] = INT_MAX;
	// 全部未在集合
	for (i = 0; i < SUM_MAX; ++i)
		is_in_set[i] = false;

	// 把源点加入set
	is_in_set[start] = true;
	dists[start] = 0;
	int cur = start;

	int min_element, min_index;
	// 总节点数
	int size_vex = N + M;

	// 添加 n - 1 次，start已经在里面了
	for (i = 1; i < size_vex; ++i) {
		// 对cur的所有的集合外邻居进行松弛操作
		for (h = 1; h <= size_vex; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX)
					dists[h] = min(dists[h], dists[cur] + edges[h][cur]);

		// 挑选dist最小的
		min_element = INT_MAX;
		min_index = -1;
		for (h = 1; h <= size_vex; ++h)
			if (!is_in_set[h] && dists[h] < min_element) {
				min_index = h;
				min_element = dists[h];
			}

		// 把它收入set
		is_in_set[min_index] = true;
		cur = min_index;
	}
}

int main() {
	
	scanf("%d%d%d%d", &N, &M, &K, &D_s);


	int i, h;

	// edge全部设为不可达
	for (i = 0; i < SUM_MAX; ++i)
		for (h = 0; h < SUM_MAX; ++h)
			edges[i][h] = INT_MAX;

	char str_P1[5], str_P2[5];
	int int_P1, int_P2, edge;
	for (i = 0; i < K; ++i) {
		scanf("%s %s %d", str_P1, str_P2, &edge);
		int_P1 = strP2intP(str_P1);
		int_P2 = strP2intP(str_P2);
		edges[int_P1][int_P2] = edge;
		edges[int_P2][int_P1] = edge;
		// printf("%d-%d=%d\n", int_P1, int_P2, edge);
	}

	int sum_cost;

	// 最小与房子的距离之和 以及对应的index
	int min_element, min_index;
	// 每个候选点都有离某房子的最近，找到这些距离最大的一个点的对应距离（加油站危险，离最近房子要远一点）
	int max_min_dist;

	min_element = INT_MAX;
	min_index = -1;
	max_min_dist = -1;

	// 本候选点离哪个房子最近，对应最近距离
	int cur_min_dist;
	for (i = 1; i <= M; ++i) {
		dijkstra(N + i);

		sum_cost = 0;
		cur_min_dist = INT_MAX;
		for (h = 1; h <= N; ++h) {
			if (dists[h] > D_s) {
				sum_cost = -1; // 特殊设置，表示这个加油站不符合要求(所有住宅区的距离是否都在服务范围内)
				break;
			}
			else {
				sum_cost += dists[h];
				if (dists[h] < cur_min_dist)
					cur_min_dist = dists[h];
			}
		}
		
		// 候选点有效
		if (sum_cost != -1) {
			if (cur_min_dist > max_min_dist || cur_min_dist == max_min_dist && sum_cost < min_element) {
				min_element = sum_cost;
				min_index = i;
				max_min_dist = cur_min_dist;
			}
		}

	}
	if (min_index == -1)
		printf("No Solution");
	else {
		printf("G%d\n%.1lf %.1lf", min_index, (double)max_min_dist, (double)min_element / N);
	}
	

	system("pause");
	return 0;
}