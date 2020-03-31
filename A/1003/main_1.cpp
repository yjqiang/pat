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

// �ڽӾ���
// INT_MAX ��ʾ�ޱ�
int edges[N_MAX][N_MAX];
// ��¼ÿ�����teams��Ŀ
int num_teams[N_MAX];


// dijkstraʹ��
// �Ƿ��Ѿ�����S����
bool is_in_set[N_MAX];
// ���·������
int path_counts[N_MAX];
// ��¼���·������
int path_dists[N_MAX];
// start����������·���ϵ����team��Ŀ
int path_num_teams[N_MAX];


int main() {
	int N, M, C1, C2;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);

	int i, h;
	for (i = 0; i < N; ++i)
		scanf("%d", num_teams + i);

	for (i = 0; i < N; ++i)
		for (h = 0; h < N; ++h)
			// �������б�
			edges[i][h] = INT_MAX;

	// ע��C1c1  C2c2���𣬰���sb��Ŀ����ģ�CΪstart end�ı�ţ�c���ǵ��ͨ�ñ��
	int c1, c2, L;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &c1, &c2, &L);
		edges[c1][c2] = edges[c2][c1] = L;
	}



	// ����ȫ��dijkstra
	for (i = 0; i < N; ++i) {
		is_in_set[i] = false;
		path_counts[i] = 0;
		path_dists[i] = INT_MAX;
		path_num_teams[i] = 0;
	}

	// ��C1Դ�����set
	int cur = C1;
	is_in_set[C1] = true;
	path_counts[C1] = 1;
	path_dists[C1] = 0;
	path_num_teams[C1] = num_teams[C1];

	// �ɳ�·������ѡ���·��
	int min_dist, min_index;

	// ��������
	int cur_dist, cur_num_teams;

	for (i = 1; i < N; ++i) {
		// �ɳ�cur�ڽӵ��·��
		for (h = 0; h < N; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX) {
				// ��h��curΪǰ׺�ڵ㣬�����Ӧ����
				cur_dist = path_dists[cur] + edges[h][cur];
				cur_num_teams = path_num_teams[cur] + num_teams[h];

				if (cur_dist < path_dists[h]) {
					path_dists[h] = cur_dist;
					path_num_teams[h] = cur_num_teams;
					// ��Ϊcur_dist��C1��h��·������������C1��cur�����·������
					path_counts[h] = path_counts[cur];
				}
				// ����ͬ���ȵ�·��
				else if (cur_dist == path_dists[h]) {
					// ��Ϊcur_dist��C1��h��·������������ԭ�������ݣ�����C1��cur�����·������
					path_counts[h] += path_counts[cur];
					if(cur_num_teams > path_num_teams[h])
						path_num_teams[h] = cur_num_teams;
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

	printf("%d %d", path_counts[C2], path_num_teams[C2]);

	system("pause");
	return 0;
}