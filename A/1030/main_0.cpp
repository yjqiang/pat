#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

#define N_MAX 501
#define NA INT_MAX

int path_distances[N_MAX][N_MAX];
int path_costs[N_MAX][N_MAX];

int dist[N_MAX];
int sum_costs[N_MAX];
int neighbour[N_MAX];
bool is_in_set[N_MAX];


int main() {
	int N, M, S, D;
	scanf("%d%d%d%d", &N, &M, &S, &D);

	int i, k;
	for (i = 0; i < N; ++i) {
		dist[i] = NA;
		sum_costs[i] = NA;
		neighbour[i] = -1;
		is_in_set[i] = false;
	}
	for (i = 0; i < N; ++i)
		for (k = 0; k < N; ++k)
			path_distances[i][k] = NA;

	int from, to, distance, cost;
	for (i = 0; i < M; ++i) {
		scanf("%d %d %d %d", &from, &to, &distance, &cost);
		path_distances[from][to] = distance;
		path_distances[to][from] = distance;

		path_costs[from][to] = cost;
		path_costs[to][from] = cost;
	}

	
	is_in_set[S] = true;
	dist[S] = 0;
	sum_costs[S] = 0;

	int cur = S;
	int min_dist, min_index;

	for (i = 1; i < N; ++i) {
		for (k = 0; k < N; ++k)
			if (path_distances[cur][k] != NA && !is_in_set[k]) {
				if (dist[cur] + path_distances[cur][k] < dist[k]) {
					dist[k] = dist[cur] + path_distances[cur][k];
					neighbour[k] = cur;
					sum_costs[k] = sum_costs[cur] + path_costs[cur][k];
				}
				else if (dist[cur] + path_distances[cur][k] == dist[k]) {
					if (sum_costs[cur] + path_costs[cur][k] < sum_costs[k]) {
						neighbour[k] = cur;
						sum_costs[k] = sum_costs[cur] + path_costs[cur][k];
					}
				}
			}

		min_dist = INT_MAX;
		for (k = 0; k < N; ++k)
			if (dist[k] != NA && !is_in_set[k] && dist[k] < min_dist) {
				min_dist = dist[k];
				min_index = k;
			}
		is_in_set[min_index] = true;
		cur = min_index;
	}

	vector <int> s;
	for (i = D; neighbour[i] != -1; i = neighbour[i])
		s.push_back(i);
	s.push_back(S);

	for (i = s.size() - 1; i >= 0; --i)
		printf("%d ", s[i]);
	printf("%d %d", dist[D], sum_costs[D]);

	system("pause");
	return 0;
}