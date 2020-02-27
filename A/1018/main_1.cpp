#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 500
int costs_v[MAX_N + 1];
int dist[MAX_N + 1];
vector<int> neighbours[MAX_N + 1];
int paths[MAX_N + 1][MAX_N + 1];
bool sets[MAX_N + 1] = { false };
vector<int> path_result;
vector<int> tmp_path_result;

int min_back = INT_MAX, min_need = INT_MAX;


void dfs(int S_p) {
	tmp_path_result.push_back(S_p);
	int i, n;
	int back, need;
	int x;
	if (!S_p) {
		back = 0; need = 0;
		for (i = tmp_path_result.size() - 1; i >= 0; --i) {
			x = costs_v[tmp_path_result[i]];
			if (x >= 0)
				back += x;
			else if (back >= -x)
				back -= (-x);
			else {
				need += (-x) - back;
				back = 0;			
			}
		}
		if (need < min_need) {
			min_need = need;
			min_back = back;
			path_result = tmp_path_result;
		}
		else if (need == min_need && back < min_back) {
			min_back = back;
			path_result = tmp_path_result;
		}
		tmp_path_result.pop_back();
		return;
	}
	n = neighbours[S_p].size();
	for (i = 0; i < n; ++i)
		dfs(neighbours[S_p][i]);
	tmp_path_result.pop_back();
}

int main() {
	int C_max, N, S_p, M;
	scanf("%d%d%d%d", &C_max, &N, &S_p, &M);

	int index, k;
	int tmp_int;
	for (index = 1; index <= N; ++index) {
		scanf("%d", &tmp_int);
		costs_v[index] = tmp_int - C_max / 2;
	}

	for (index = 0; index <= N; ++index) {
		dist[index] = INT_MAX;
	}

	for (index = 0; index <= N; ++index) 
		for (k = 0; k <= N; ++k) {
			paths[index][k] = INT_MAX;
		}

	int from, to, path;
	for (index = 0; index < M; ++index) {
		scanf("%d%d%d", &from, &to, &path);
		paths[from][to] = path;
		paths[to][from] = path;
	}

	
	// dijkstra
	// add vertice0
	sets[0] = true;
	dist[0] = 0;
	int cur = 0;
	int min_element, min_index, distance;
	for (index = 0; index < N; ++index) {
		for (k = 0; k <= N; ++k)
			if (paths[cur][k] != INT_MAX &&!sets[k]) {
				distance = dist[cur] + paths[cur][k];
				if (distance < dist[k]) {
					dist[k] = distance;
					neighbours[k].clear();
					neighbours[k].push_back(cur);
				}
				else if (distance == dist[k])
					neighbours[k].push_back(cur);				
			}

		min_element = INT_MAX;
		for ( k = 0; k <= N; ++k)
			if (!sets[k] && dist[k] != INT_MAX && dist[k] < min_element) {
				min_element = dist[k];
				min_index = k;
			}
		sets[min_index] = true;
		cur = min_index;
	}


	dfs(S_p);

	printf("%d ", min_need);
	printf("0");
	for (index = path_result.size() - 2; index >= 0; --index) {
		printf("->%d", path_result[index]);
	}
	printf(" %d", min_back);

	system("pause");


	return 0;
}