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


// �ڽӾ���(time)
// INT_MAX ��ʾ�ޱ�
// distance
int edges[N_MAX][N_MAX];
// cost
int costs[N_MAX][N_MAX];



// dijkstraʹ��
// �Ƿ��Ѿ�����S����
bool is_in_set[N_MAX];
// ��¼���·������
int path_dists[N_MAX];
// ��¼cost
int path_costs[N_MAX];
// ����·��
int path_neighbours[N_MAX];


int main() {
	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);

	int i, h;

	for (i = 0; i <= N; ++i)
		for (h = 0; h <= N; ++h)
			// �������б�
			edges[i][h] = costs[i][h] = INT_MAX;

	int City1, City2, Distance, Cost;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d %d", &City1, &City2, &Distance, &Cost);
		edges[City1][City2] = edges[City2][City1] = Distance;
		costs[City1][City2] = costs[City2][City1] = Cost;
	}



	// ����ȫ��dijkstra
	for (i = 0; i < N; ++i) {
		is_in_set[i] = false;
		path_dists[i] = INT_MAX;
		path_costs[i] = INT_MAX;
		path_neighbours[i] = -1;
	}

	// ��Դ�����set
	int cur = S;
	is_in_set[S] = true;
	path_dists[S] = 0;
	path_costs[S] = 0;

	// �ɳ�·������ѡ���·��
	int min_dist, min_index;

	// ��������
	int cur_dist, cur_cost;

	// ѭ��N-1��
	for (i = 1; i < N; ++i) {
		// �ɳ�cur�ڽӵ��·��
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX) {
				// ��h��curΪǰ׺�ڵ㣬�����Ӧ����
				cur_dist = path_dists[cur] + edges[h][cur];
				cur_cost = path_costs[cur] + costs[h][cur];

				if (cur_dist < path_dists[h]) {
					path_dists[h] = cur_dist;
					path_neighbours[h] = cur;
					path_costs[h] = cur_cost;
				}
				// ����ͬ���ȵ�·��
				else if (cur_dist == path_dists[h] && cur_cost < path_costs[h]) {
					path_neighbours[h] = cur;
					path_costs[h] = cur_cost;
				}
			}

		// ����Сֵ������S
		min_dist = INT_MAX;
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && path_dists[h] < min_dist) {
				min_dist = path_dists[h];
				min_index = h;
			}

		// ����S
		is_in_set[min_index] = true;
		cur = min_index;
	}

	vector<int> path;
	int City;
	for (City = D; City != -1; City = path_neighbours[City])
		path.push_back(City);

	for (i = path.size()-1; i >= 0; --i)
		printf("%d ", path[i]);

	printf("%d %d", path_dists[D], path_costs[D]);

	system("pause");
	return 0;
}