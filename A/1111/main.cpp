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

int N, M, source, destination;
// �ڽӾ���(time)
// INT_MAX ��ʾ�ޱ�
int edges[N_MAX][N_MAX];
// times
int times[N_MAX][N_MAX];


// dijkstraʹ��
// �Ƿ��Ѿ�����S����
bool is_in_set0[N_MAX];
// ��¼���·������
int path_dists0[N_MAX];
// ��¼·��ʱ��
int path_times0[N_MAX];
// ����·��
int path_neighbours0[N_MAX];
// ���·����path[0]Ϊdestination��
vector<int> path0;
void dijkstra0() {
	int i, h;
	for (i = 0; i < N; ++i) {
		is_in_set0[i] = false;
		path_dists0[i] = INT_MAX;
		path_times0[i] = INT_MAX;
		path_neighbours0[i] = - 1;
	}

	// ��Դ�����set
	int cur = source;
	is_in_set0[source] = true;
	path_dists0[source] = 0;
	path_times0[source] = 0;


	// �ɳ�·������ѡ���·��
	int min_dist, min_index;

	// ��������
	int cur_dist, cur_time;

	// ѭ��N-1��
	for (i = 1; i < N; ++i) {
		// �ɳ�cur�ڽӵ��·��
		for (h = 0; h < N; ++h)
			// edges[cur][h] ���� edges[h][cur] ע��˳��
			if (!is_in_set0[h] && edges[cur][h] != INT_MAX) {
				// ��h��curΪǰ׺�ڵ㣬�����Ӧ����
				cur_dist = path_dists0[cur] + edges[cur][h];
				cur_time = path_times0[cur] + times[cur][h];

				if (cur_dist < path_dists0[h]) {
					path_dists0[h] = cur_dist;
					path_neighbours0[h] = cur;
					path_times0[h] = cur_time;
				}
				// ����ͬ���ȵ�·��
				else if (cur_dist == path_dists0[h] && cur_time < path_times0[h]) {
					path_neighbours0[h] = cur;
					path_times0[h] = cur_time;
				}
			}

		// ����Сֵ������S
		min_dist = INT_MAX;
		for (h = 0; h < N; ++h)
			if (!is_in_set0[h] && path_dists0[h] < min_dist) {
				min_dist = path_dists0[h];
				min_index = h;
			}


		// ����S
		is_in_set0[min_index] = true;
		cur = min_index;
	}

	// ����·����¼
	int V;
	for (V = destination; V != -1; V = path_neighbours0[V])
		path0.push_back(V);
}



// dijkstraʹ��
// �Ƿ��Ѿ�����S����
bool is_in_set1[N_MAX];
// ��¼���·��ʱ�䣬�൱��dijkstra��dist
int path_times1[N_MAX];
// ��¼·��intersection
int path_intersections1[N_MAX];
// ����·��
int path_neighbours1[N_MAX];
// ���·����path[0]Ϊdestination��
vector<int> path1;
void dijkstra1() {
	int i, h;
	for (i = 0; i < N; ++i) {
		is_in_set1[i] = false;
		path_times1[i] = INT_MAX;
		path_intersections1[i] = INT_MAX;
		path_neighbours1[i] = -1;
	}

	// ��Դ�����set
	int cur = source;
	is_in_set1[source] = true;
	path_times1[source] = 0;
	path_intersections1[source] = 0;


	// �ɳ�·������ѡ���·��
	int min_time, min_index;

	// ��������
	int cur_intersection, cur_time;

	// ѭ��N-1��
	for (i = 1; i < N; ++i) {
		// �ɳ�cur�ڽӵ��·��
		for (h = 0; h < N; ++h)
			// edges[cur][h] ���� edges[h][cur] ע��˳��
			if (!is_in_set1[h] && times[cur][h] != INT_MAX) {
				// ��h��curΪǰ׺�ڵ㣬�����Ӧ����
				cur_time = path_times1[cur] + times[cur][h];
				cur_intersection = path_intersections1[cur] + 1;

				if (cur_time < path_times1[h]) {
					path_times1[h] = cur_time;
					path_neighbours1[h] = cur;
					path_intersections1[h] = cur_intersection;
				}
				// ����ͬ���ȵ�·��
				else if (cur_time == path_times1[h] && cur_intersection < path_intersections1[h]) {
					path_neighbours1[h] = cur;
					path_intersections1[h] = cur_intersection;
				}
			}

		// ����Сֵ������S
		min_time = INT_MAX;
		for (h = 0; h < N; ++h)
			if (!is_in_set1[h] && path_times1[h] < min_time) {
				min_time = path_times1[h];
				min_index = h;
			}


		// ����S
		is_in_set1[min_index] = true;
		cur = min_index;
	}

	// ����·����¼
	int V;
	for (V = destination; V != -1; V = path_neighbours1[V])
		path1.push_back(V);
}

int main() {
	scanf("%d%d", &N, &M);
	int i, h;

	// �����
	for (i = 0; i < N; ++i)
		for (h = 0; h < N; ++h)
			// �������б�
			edges[i][h] = times[i][h] = INT_MAX;
	int one_way, length, time;
	int V1, V2;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d %d %d", &V1, &V2, &one_way, &length, &time);
		// ˫��
		if (one_way == 0) {
			edges[V1][V2] = edges[V2][V1] = length;
			times[V1][V2] = times[V2][V1] = time;
		}
		// ����
		else {
			edges[V1][V2] = length;
			times[V1][V2] = time;
		}
	}

	scanf("%d %d", &source, &destination);
	dijkstra0();
	dijkstra1();

	if (path0 != path1){
		printf("Distance = %d: %d", path_dists0[destination], path0.back());
		for (i = path0.size() - 2; i >= 0; --i)
			printf(" ->% d", path0[i]);

		printf("\n");
		printf("Time = %d: %d", path_times1[destination], path1.back());
		for (i = path1.size() - 2; i >= 0; --i)
			printf(" -> %d", path1[i]);
	}
	else {
		printf("Distance = %d; Time = %d: %d", path_dists0[destination], path_times1[destination], path0.back());
		for (i = path0.size() - 2; i >= 0; --i)
			printf(" ->% d", path0[i]);
	}

	

	system("pause");
	return 0;
}