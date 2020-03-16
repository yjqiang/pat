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

#define N_MAX 200

struct City {
	int happiness;
	string city_name;
};
// vex
City cities[N_MAX];

struct Edge {
	int city_id;
	int cost;
};
// weight/cost/edge
vector<Edge> edges[N_MAX];

// dijkstra
bool is_in_set[N_MAX];
vector<int> neighbours[N_MAX];
int dists[N_MAX];


// 与cities相反
map<string, int>indexes;
string ROM = "ROM";

vector<int> tmp;
vector<int> result;
// 最大happy之和中，找平均最大的，那就是count最小
int min_counts_vex = INT_MAX;
int max_sum_happiness = INT_MIN;
int count_paths = 0;
// 筛选结果
void dfs(int node) {
	tmp.push_back(node);

	int i, n;

	// 起始点为0
	if (node == 0) {
		++count_paths;

		int sum_happiness = 0;
		n = tmp.size();
		for (i = 0; i < n; ++i)
			sum_happiness += cities[tmp[i]].happiness;

		if (sum_happiness > max_sum_happiness || sum_happiness == max_sum_happiness && tmp.size() < min_counts_vex) {
			max_sum_happiness = sum_happiness;
			min_counts_vex = tmp.size();
			result = tmp;
		}
	}

	
	n = neighbours[node].size();
	for (i = 0; i < n; ++i)
		dfs(neighbours[node][i]);
	tmp.pop_back();
}

int main() {
	int N, K;
	string s;

	cin >> N >> K >> s;

	indexes[s] = 0;
	cities[0].city_name = s;
	// 起始点happy填个0
	cities[0].happiness = 0;

	int i, h;
	int happiness;
	for (i = 1; i < N; ++i) {
		cin >> s >> happiness;
		indexes[s] = i;
		cities[i].city_name = s;
		cities[i].happiness = happiness;
	}

	int cost;
	string city_name1, city_name2;
	int city_id1, city_id2, city_id;
	for (i = 0; i < K; ++i) {
		cin >> city_name1 >> city_name2 >> cost;
		city_id1 = indexes[city_name1];
		city_id2 = indexes[city_name2];
		edges[city_id1].push_back(Edge{ city_id2, cost });
		edges[city_id2].push_back(Edge{ city_id1, cost });
	}


	// dijkstra
	for (i = 0; i < N_MAX; ++i) {
		is_in_set[i] = false;
		dists[i] = INT_MAX;
	}

	int cur = 0;
	is_in_set[0] = true;
	dists[0] = 0;

	int n_size, dist;
	int min_dist, min_index;

	for (i = 1; i < N; ++i) {
		// 收缩相邻结点
		n_size = edges[cur].size();
		for (h = 0; h < n_size; ++h) {
			city_id = edges[cur][h].city_id;  // 相邻节点
			if (!is_in_set[edges[cur][h].city_id]) {
				dist = dists[cur] + edges[cur][h].cost;
				// 若更新可以使dist小，清理之前的数据
				if (dist < dists[city_id]) {
					neighbours[city_id].clear();
					neighbours[city_id].push_back(cur);

					dists[city_id] = dist;
				}
				// 相同就添加，后续再处理
				else if (dist == dists[city_id]) {
					neighbours[city_id].push_back(cur);
				}
			}

		}

		min_dist = INT_MAX;
		min_index = -1;
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && dists[h] < min_dist) {
				min_dist = dists[h];
				min_index = h;
			}
		cur = min_index;
		is_in_set[min_index] = true;
	}
	//printf("\n");
	//for (i = 0; i < N; ++i) {
	//	printf("dist[%d]=%d\n", i, dists[i]);
	//}


	dfs(indexes[ROM]);

	// 打印结果
	printf("%d %d %d %d\n", count_paths, dists[indexes[ROM]], max_sum_happiness, max_sum_happiness / (result.size() - 1));
	printf("%s", cities[result.back()].city_name.c_str());
	for (i = result.size() - 2; i >= 0; --i)
		printf("->%s", cities[result[i]].city_name.c_str());

	system("pause");
	return 0;
}