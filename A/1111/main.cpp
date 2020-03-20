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

using namespace std;

#define N_MAX 500
int N, M;

struct Edge {
	// ��һ�˵�
	int V;
	int length;
	int time;
};

// �ڽӱ�
vector<Edge> edges[N_MAX];

// dists ����Ȩ�أ�other_costs�Ǹ�Ȩ��
// �����·��ʱ��dists����length��costs����time
// �����ʱ��ʱ��dists����time��costs���𾭹��ĵ�
int dists[N_MAX];
int costs[N_MAX];

// ������סdij_time��length
int tmp[N_MAX];


int neighbours[N_MAX];
// ��¼����·��
vector <int> path0;
vector <int> path1;

// dijkstra �Ƿ���set������
bool is_in_set[N_MAX];


void dij_length(int source, int destination, int& min_length, int& min_time) {
	int i, h;
	for (i = 0; i < N; ++i) {
		dists[i] = INT_MAX;
		costs[i] = INT_MAX;
		neighbours[i] = -1;
		is_in_set[i] = false;
	}
	
	// ��source����set
	int cur = source;
	is_in_set[source] = true;
	dists[source] = 0;
	costs[source] = 0;

	int min_dist, min_index;
	int n_size;
	int dist, cost, V;
	for (i = 1; i < N; ++i) {
		// ����cur�����ڵ�
		n_size = edges[cur].size();
		for (h = 0; h < n_size; ++h) {
			V = edges[cur][h].V;
			if (!is_in_set[V]) {
				dist = dists[cur] + edges[cur][h].length;
				cost = costs[cur] + edges[cur][h].time;

				if (dist < dists[V]) {
					dists[V] = dist;
					costs[V] = cost;
					neighbours[V] = cur;
				}
				else if (dist == dists[V] && cost < costs[V]) {
					costs[V] = cost;
					neighbours[V] = cur;
				}
			}
		}

		min_dist = INT_MAX;
		for (h = 0; h < N; ++h)
			if (dists[h] < min_dist && !is_in_set[h]) {
				min_index = h;
				min_dist = dists[h];
			}

		cur = min_index;
		is_in_set[min_index] = true;
	}

	for (i = destination; i != -1; i = neighbours[i])
		path0.push_back(i);

	min_length = dists[destination];
	min_time = costs[destination];

	//printf("%d", path0.back());
	//for (i = path0.size() - 2; i >= 0; --i)
	//	printf(" -> %d", path0[i]);

}

void dij_time(int source, int destination, int& min_length, int& min_time) {
	int i, h;
	for (i = 0; i < N; ++i) {
		dists[i] = INT_MAX;
		costs[i] = INT_MAX;
		tmp[i] = 0;
		neighbours[i] = -1;
		is_in_set[i] = false;
	}

	// ��source����set
	int cur = source;
	is_in_set[source] = true;
	dists[source] = 0;
	costs[source] = 0;
	tmp[source] = 0;

	int min_dist, min_index;
	int n_size;
	int dist, cost, V;
	for (i = 1; i < N; ++i) {
		// ����cur�����ڵ�
		n_size = edges[cur].size();
		for (h = 0; h < n_size; ++h) {
			V = edges[cur][h].V;
			if (!is_in_set[V]) {
				dist = dists[cur] + edges[cur][h].time;
				cost = costs[cur] + 1;

				if (dist < dists[V]) {
					dists[V] = dist;
					costs[V] = cost;
					neighbours[V] = cur;
					tmp[V] = tmp[cur] + edges[cur][h].length;
				}
				else if (dist == dists[V] && cost < costs[V]) {
					costs[V] = cost;
					neighbours[V] = cur;
					tmp[V] = tmp[cur] + edges[cur][h].length;
				}
			}
		}

		min_dist = INT_MAX;
		for (h = 0; h < N; ++h)
			if (dists[h] < min_dist && !is_in_set[h]) {
				min_index = h;
				min_dist = dists[h];
			}

		cur = min_index;
		is_in_set[min_index] = true;
	}

	for (i = destination; i != -1; i = neighbours[i])
		path1.push_back(i);

	min_time = dists[destination];
	min_length = tmp[destination];
	

	//printf("%d", path1.back());
	//for (i = path1.size() - 2; i >= 0; --i)
	//	printf(" -> %d", path1[i]);

}


int main() {
	scanf("%d%d", &N, &M);

	int i;
	int V1, V2, one_way, length, time;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d %d %d", &V1, &V2, &one_way, &length, &time);
		edges[V1].push_back(Edge{ V2, length, time });
		if (one_way == 0)
			edges[V2].push_back(Edge{ V1, length, time });
	}

	int source, destination;
	scanf("%d%d", &source, &destination);

	int min_length0, min_time0, min_length1, min_time1;
	dij_length(source, destination, min_length0, min_time0);
	// printf("\n");
	dij_time(source, destination, min_length1, min_time1);
	// printf("\n");


	// ��������һ����˵��pathһ����
	// �����ж��������·��������ͬ��length����ͬtime����path0Ҫ��ì��
	if (min_length0 == min_length1 && min_time0 == min_time1) {
		printf("Distance = %d; Time = %d: ", min_length0, min_time0);
		printf("%d", path0.back());
		for (i = path0.size() - 2; i >= 0; --i)
			printf(" -> %d", path0[i]);
	}
	else {
		printf("Distance = %d: ", min_length0);
		printf("%d", path0.back());
		for (i = path0.size() - 2; i >= 0; --i)
			printf(" -> %d", path0[i]);
		printf("\n");

		printf("Time = %d: ", min_time1);
		printf("%d", path1.back());
		for (i = path1.size() - 2; i >= 0; --i)
			printf(" -> %d", path1[i]);
	}


	system("pause");
	return 0;
}