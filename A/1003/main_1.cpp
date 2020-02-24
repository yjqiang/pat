# define _CRT_SECURE_NO_WARNINGS
# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <climits>

using namespace std;


# define MAX_N 510

int city_hands[MAX_N] = {0};
int edge[MAX_N][MAX_N];
int dist[MAX_N];
bool is_in_S[MAX_N] = { false };
int result_hands[MAX_N] = { 0 };
int result_count[MAX_N] = { 0 };

int main(){
	int N, M, C1, C2;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	
	int i, j;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j) {
			if (i == j)
			{
				edge[i][j] = 0;
			}
			else
			{
				edge[i][j] = INT_MAX;
			}
		}

	for (i = 0; i < N; ++i)
		dist[i] = INT_MAX;
			


	///////////////////////////////////////////////////////////////////

	for (i = 0; i < N; ++i)
		scanf("%d", city_hands + i);

	int c_1, c_2;
	int length;
	result_hands[C1] = city_hands[C1];
	for (i = 0; i < M; ++i){
		scanf("%d%d%d", &c_1, &c_2, &length);
		edge[c_1][c_2] = length;
		edge[c_2][c_1] = length;
	}

	///////////////////////////////////////////////////////////////////

	// modified dijkstra
	int cur = C1;
	// ad C1
	dist[C1] = 0;
	is_in_S[cur] = true;  
	result_count[C1] = 1;
	result_hands[C1] = city_hands[C1];
	int min_dist;
	for (i = 1; i < N; ++i) {
		for (j = 0; j < N; ++j)
			if (edge[cur][j] != INT_MAX && !is_in_S[j]) {
				int new_dist = dist[cur] + edge[cur][j];
				if (dist[j] > new_dist) {
					dist[j] = new_dist;
					result_hands[j] = result_hands[cur] + city_hands[j];
					result_count[j] = result_count[cur];
				}
				else if (dist[j] == new_dist)
				{
					result_hands[j] = max(result_hands[j], result_hands[cur] + city_hands[j]);
					result_count[j] += result_count[cur];
				}
			}

		min_dist = INT_MAX;
		cur = -1;
		for (j = 0; j < N; ++j)
			if (!is_in_S[j] && dist[j] < min_dist)
			{
				min_dist = dist[j];
				cur = j;
			}
		is_in_S[cur] = true;
	}


	printf("%d %d", result_count[C2], result_hands[C2]);
	system("pause");
	return 0;
}