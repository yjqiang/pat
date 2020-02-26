# define _CRT_SECURE_NO_WARNINGS
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

#define MAX_N 20
int processing_time[1001];
int results[1001];
int end_time[MAX_N] = { 0 };

int main() {
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);

	int i;
	for (i = 1; i <= K; ++i)
		scanf("%d", processing_time + i);

	vector <queue<int>> queues(N);

	int user_id = 1;
	int window_id;
	int tmp_int;

	for (i = 0; i < M; ++i)
		for (window_id = 0; window_id < N; ++window_id) {
			if (user_id > K)
				break;

			tmp_int = processing_time[user_id] + end_time[window_id];
			queues[window_id].push(tmp_int);
			end_time[window_id] = tmp_int;
			
			results[user_id] = tmp_int;

			++user_id;
		}

	
	int min_first_time, min_window_id;
	for (; user_id <= K; ++user_id) {
		min_first_time = INT_MAX;
		for (window_id = 0; window_id < N; ++window_id)
			if (queues[window_id].front() < min_first_time) {
				min_first_time = queues[window_id].front();
				min_window_id = window_id;
			}

		queues[min_window_id].pop();

		tmp_int = processing_time[user_id] + end_time[min_window_id];
		queues[min_window_id].push(tmp_int);
		end_time[min_window_id] = tmp_int;
		results[user_id] = tmp_int;
	}

	int result;
	for (i = 0; i < Q; ++i) {
		scanf("%d", &user_id);
		result = results[user_id] + 480;  // 8:00   8*60

		if (result >= 1020 && // 17:00 17*60
			result - processing_time[user_id] >= 1020) // service_start_time
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", result / 60, result % 60);
	}

	system("pause");
	return 0;
}