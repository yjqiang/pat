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
// Դ��
#define START 0

int C_max, N, S_p, M;

// �ڽӾ���(time)
// INT_MAX ��ʾ�ޱ�
int edges[N_MAX][N_MAX];
// ÿ��ĳ�����Ŀ
int num_bikes[N_MAX];



// dijkstraʹ��
// �Ƿ��Ѿ�����S����
bool is_in_set[N_MAX];
// ��¼���·������
int path_dists[N_MAX];
// ��¼·�����ݣ������������·��(path_dists[i])�£�ǰ׺�������(0->...->ǰ׺��->i Ϊ���·��)
// ע�����·�����ܶ��������ܶ�Ӧ���ǰ׺��
vector<int> path_neighbours[N_MAX];

// ��start�������ģ���������start�ĳ�����Ŀ
int min_bring_from = INT_MAX, min_bring_back = INT_MAX;
// ��Ӧ���·��
vector<int>result;
vector<int> tmp;
void dfs(int vex) {
	int i;
	// ����Դ����
	if (vex == START) {
		// ��·��ͳ��
		int bring_from = 0, bring_back = 0;
		int difference;
		// ·���ǵ��ŵ�
		for (i = tmp.size() - 1; i >= 0; --i) {
			difference = num_bikes[tmp[i]] - C_max / 2;
			// ���Ӷ��ˣ��ͻ���������
			if (difference >= 0)
				bring_back += difference;
			// ����ȱ�ˣ��Ͱ���;��start�������ĳ���Ͷ��ȥ;���ܻ����ٶ��һ�㳵�ӣ���start���
			else {
				difference = -difference;
				if (bring_back >= difference)
					bring_back -= difference;
				else {
					// ע��˳���ȿ۳�bring_back,��ʾ��;�ռ��ĳ���ȫ����ȱ���Ȼ���bring_back����
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
			// �������б�
			edges[i][h] = INT_MAX;

	int S_i, S_j, T_ij;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &S_i, &S_j, &T_ij);
		edges[S_i][S_j] = edges[S_j][S_i] = T_ij;
	}



	// ����ȫ��dijkstra
	for (i = 0; i <= N; ++i) {
		is_in_set[i] = false;
		path_dists[i] = INT_MAX;
	}

	// ��Դ�����set
	int cur = START;
	is_in_set[START] = true;
	path_dists[START] = 0;

	// �ɳ�·������ѡ���·��
	int min_dist, min_index;

	// ��������
	int cur_dist;

	// ʵ����N+1���㣬����ѭ��N��
	for (i = 1; i <= N; ++i) {
		// �ɳ�cur�ڽӵ��·��
		for (h = 0; h <= N; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX) {
				// ��h��curΪǰ׺�ڵ㣬�����Ӧ����
				cur_dist = path_dists[cur] + edges[h][cur];

				if (cur_dist < path_dists[h]) {
					path_dists[h] = cur_dist;
					// ����ǰ׺��
					path_neighbours[h].clear();
					path_neighbours[h].push_back(cur);
				}
				// ����ͬ���ȵ�·��
				else if (cur_dist == path_dists[h]) {
					// ����ǰ׺��
					path_neighbours[h].push_back(cur);
				}
			}

		// ����Сֵ������S
		min_dist = INT_MAX;
		for (h = 0; h <= N; ++h)
			if (!is_in_set[h] && path_dists[h] < min_dist) {
				min_dist = path_dists[h];
				min_index = h;
			}

		// ����S
		is_in_set[min_index] = true;
		cur = min_index;
	}

	// �������·�����ҵ���Ҫ����ϵ�·����the least number of bikes sent from PBMC��requires minimum number of bikes that we must take back to PBMC��
	dfs(S_p);

	printf("%d 0", min_bring_from);
	for (i = result.size()-1; i >= 0; --i)
		printf("->%d", result[i]);
	printf(" %d", min_bring_back);

	system("pause");
	return 0;
}