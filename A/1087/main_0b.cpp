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

#define N_MAX 200
#define START 0

// 城市名字
string city_names[N_MAX];
// city_names index与name交换
map<string, int> indices;


// 邻接矩阵(time)
// INT_MAX 表示无边
// cost
int costs[N_MAX][N_MAX];
// happinesses
int happinesses[N_MAX];



// dijkstra使用
// 是否已经收入S里面
bool is_in_set[N_MAX];
// 记录最短路径长度，这里cost其实相当于dijkstra的路径长度
int path_costs[N_MAX];
// 记录最短路径的条数
int path_counts[N_MAX];
// 回溯路径（相同长度cost的路径可能有多条）
vector<int> path_neighbours[N_MAX];



vector<int>result;
vector<int>tmp;
// 最优路径的平均快乐以及快乐之和
double max_average_happiness = -1;
int max_sum_happiness = -1;
void dfs(int vex) {
	int i, n_size;
	if (vex == START) {
		int sum_happiness = 0;
		double average_happiness;
		n_size = tmp.size();
		for (i = n_size - 1; i >= 0; --i)
			sum_happiness += happinesses[tmp[i]];
		average_happiness = 1.0 * sum_happiness / n_size;

		if (max_sum_happiness < sum_happiness) {
			max_sum_happiness = sum_happiness;
			max_average_happiness = average_happiness;
			result = tmp;
		}
		else if (max_sum_happiness == sum_happiness && max_average_happiness < average_happiness) {
			max_average_happiness = average_happiness;
			result = tmp;
		}
		return;

	}

	tmp.push_back(vex);
	n_size = path_neighbours[vex].size();
	for (i = 0; i < n_size; ++i)
		dfs(path_neighbours[vex][i]);
	tmp.pop_back();
}


int main() {
	int N, K;
	cin >> N >> K >> city_names[START]; // 0号作为起始点
	indices[city_names[START]] = START;


	int i, h;

	// 输入剩余点的happiness
	int happiness;
	for (i = 1; i < N; ++i) {
		cin >> city_names[i] >> happiness;
		happinesses[i] = happiness;
		indices[city_names[i]] = i;
	}
	int END = indices["ROM"];

	// 输入边
	for (i = 0; i < N; ++i)
		for (h = 0; h < N; ++h)
			// 清理所有边
			costs[i][h] = INT_MAX;
	int Cost;
	string City1_name, City2_name;
	int City1_index, City2_index;
	for (i = 0; i < K; ++i) {
		cin >> City1_name >> City2_name >> Cost;
		City1_index = indices[City1_name];
		City2_index = indices[City2_name];
		costs[City1_index][City2_index] = costs[City2_index][City1_index] = Cost;
	}


	// 下面全是dijkstra
	for (i = 0; i < N; ++i) {
		is_in_set[i] = false;
		path_costs[i] = INT_MAX;
		path_counts[i] = 0;
	}

	// 把源点放入set
	int cur = START;
	is_in_set[START] = true;
	path_costs[START] = 0;
	path_counts[START] = 1;

	// 松弛路径后挑选最短路径
	int min_cost, min_index;

	// 其他变量
	int cur_cost;

	// 循环N-1次
	for (i = 1; i < N; ++i) {
		// 松弛cur邻接点的路径
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && costs[h][cur] != INT_MAX) {
				// 若h以cur为前缀节点，计算对应参数
				cur_cost = path_costs[cur] + costs[h][cur];

				if (cur_cost < path_costs[h]) {
					path_costs[h] = cur_cost;
					path_neighbours[h].clear();
					path_neighbours[h].push_back(cur);
					path_counts[h] = path_counts[cur];
				}
				// 有相同长度的路径
				else if (cur_cost == path_costs[h]) {
					// 添加
					path_neighbours[h].push_back(cur);
					path_counts[h] += path_counts[cur];
				}
			}

		// 找最小值，放入S
		min_cost = INT_MAX;
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && path_costs[h] < min_cost) {
				min_cost = path_costs[h];
				min_index = h;
			}

		// 放入S
		is_in_set[min_index] = true;
		cur = min_index;
	}

	dfs(END);

	int n_size = result.size();

	printf("%d %d %d %d\n", path_counts[END], path_costs[END], max_sum_happiness, (int)max_average_happiness);
	printf("%s", city_names[START].c_str());
	for (i = n_size -1; i >= 0; --i)
		printf("->%s", city_names[result[i]].c_str());

	system("pause");
	return 0;
}