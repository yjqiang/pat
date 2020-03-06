#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define N_MAX 100001

int values[N_MAX];

// [0, i]最大值
int max_values[N_MAX];
// [i, N-1]最小值
int min_values[N_MAX];

int main() {
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", values + i);

	
	int max_value = INT_MIN;
	for (i = 0; i < N; ++i) {
		max_value = max(max_value, values[i]);
		max_values[i] = max_value;
	}
	
	int min_value = INT_MAX;
	for (i = N - 1; i >= 0; --i) {
		min_value = min(min_value, values[i]);
		min_values[i] = min_value;
	}

	vector<int> results;
	for (i = 0; i < N; ++i)
		// (i - 1 < 0 || max_values[i -1] < values[i]) 保证左侧最大值仍然小于之
		// (i + 1 > N -1 || min_values[i +1] > values[i]) 保证右侧最小值仍然小于之
		if ((i - 1 < 0 || max_values[i - 1] < values[i]) &&
			(i + 1 > N - 1 || min_values[i + 1] > values[i]))
			results.push_back(values[i]);

	int n_results = results.size();
	
	if (n_results > 0) {
		printf("%d\n", n_results);
		printf("%d", results[0]);
		
		for (i = 1; i < n_results; ++i)
			printf(" %d", results[i]);
	}
	else {
		// 傻逼埋坑
		printf("%d\n\n", n_results);
	}

	system("pause");
	return 0;
}