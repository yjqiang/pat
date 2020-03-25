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

#define N_MAX 1001
int N, M;

// 邻接表
vector<int> edges[N_MAX];

// 每个点的入度
int in[N_MAX] = { 0 };
int tmp_in[N_MAX];

int inputs[N_MAX];

bool check() {
	int v;

	int i, h;
	// tmp_in是in的拷贝，因为多个测试用例，不能直接在in数组上操作
	for (i = 1; i <= N; ++i)
		tmp_in[i] = in[i];

	for (i = 0; i < N; ++i) {
		v = inputs[i];
		// 每次都要找入度为0的点
		if (tmp_in[v] == 0) {
			// 删去该点和与其相连的所有边
			for (h = edges[v].size() - 1; h >= 0; --h)
				--tmp_in[edges[v][h]];
		}
		else
			return false;
	}
	return true;
}

int main() {

	scanf("%d%d", &N, &M);

	int v0, v1;
	int i, h;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &v0, &v1);
		edges[v0].push_back(v1);
		++in[v1];
	}

	int K;
	// 控制输出格式
	bool is_first = true;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		for (h = 0; h < N; ++h)
			scanf("%d", inputs + h);

		if (!check()) {
			if (!is_first)
				printf(" %d", i);
			else {
				printf("%d", i);
				is_first = false;
			}
		}


	}



	system("pause");
	return 0;
}