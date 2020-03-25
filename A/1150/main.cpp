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

#define N_MAX 201

// �ڽӾ���
int edges[N_MAX][N_MAX] = { 0 };
bool visited[N_MAX];


int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int i, h;
	int city1, city2, dist;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d", &city1, &city2, &dist);
		edges[city1][city2] = edges[city2][city1] = dist;
	}
	int pre_city, city;

	int K, n;
	scanf("%d", &K);
	// ���
	int start;
	// ����ֱ���Ƿ��б�
	bool is_edge_ok;
	// ���е㶼������
	bool all_visited;

	int path_dist;
	int min_dist, min_index;
	min_dist = INT_MAX;
	for (i = 1; i <= K; ++i) {
		// init
		for (h = 1; h <= N; ++h)
			visited[h] = false;
		is_edge_ok = true;
		all_visited = true;
		path_dist = 0;

		scanf("%d %d", &n, &start);
		pre_city = start;
		
		
		// Ϊ�˽�ʡ�ռ䣨n����û�����ް�����Ҳ������ô�����߼�����
		for (h = 1; h < n; ++h) {
			scanf("%d", &city);
			// ������dist���Ǵ���0�ģ�Ĭ��Ϊ0
			if (!edges[city][pre_city])
				is_edge_ok = false;
			path_dist += edges[city][pre_city];
			visited[city] = true;

			pre_city = city;
		}
		
		// �Ƿ��е�δ������
		for (h = 1; h <= N; ++h)
			if (!visited[h]) {
				all_visited = false;
				break;
			}

		// ����ȷ����ȫ��������β��Ӧ => TS cycle

		if (!is_edge_ok)  // edge���ԣ���������
			printf("Path %d: NA (Not a TS cycle)\n", i);
		else {
			// �Ǹ� TS cycle��
			if (all_visited && city == start) {
				if (min_dist > path_dist) {
					min_dist = path_dist;
					min_index = i;
				}

				if (n == N + 1)
					printf("Path %d: %d (TS simple cycle)\n", i, path_dist);
				else
					printf("Path %d: %d (TS cycle)\n", i, path_dist);
			}
			else
				printf("Path %d: %d (Not a TS cycle)\n", i, path_dist);
		}

	}
	printf("Shortest Dist(%d) = %d", min_index, min_dist);

	system("pause");
	return 0;
}