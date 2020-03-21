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

#define N_MAX 201
int N, M;

// 邻接矩阵
bool vex[N_MAX][N_MAX] = { false };

bool visited[N_MAX];

// 查询数组
int inputs[10000];

bool isOK(int n) {
	// 长度对应且首尾一致
	if (n != N + 1 || inputs[0] != inputs[n - 1])
		return false;
	int i;

	// 去重
	for (i = 1; i <= N; ++i)
		visited[i] = false;

	// visited[inputs[0]] = true; 不需要，因为首尾相同的点
	for (i = 1; i < n; ++i) {
		// 相邻点能连在一起且不重复
		if (vex[inputs[i - 1]][inputs[i]] && !visited[inputs[i]])
			visited[inputs[i]] = true;
		else
			return false;
	}
	return true;
}

int main() {

	scanf("%d%d", &N, &M);

	int i;
	int V1, V2;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &V1, &V2);
		vex[V1][V2] = true;
		vex[V2][V1] = true;
	}

	int K;
	scanf("%d", &K);

	int n, h;
	int is_ok;
	for (i = 0; i < K; ++i) {
		scanf("%d", &n);

		for (h = 0; h < n; ++h)
			scanf("%d", inputs + h);

		if (isOK(n))
			printf("YES\n");
		else
			printf("NO\n");
	}


	system("pause");
	return 0;
}